// Copyright (c) 2019 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.


#include "brave/browser/extensions/api/brave_action_api.h"

#include <memory>
#include <string>
#include <utility>

#include "base/lazy_instance.h"
#include "components/keyed_service/core/dependency_manager.h"
#include "components/keyed_service/core/keyed_service_factory.h"
#include "chrome/browser/extensions/api/tabs/tabs_constants.h"
#include "chrome/browser/extensions/api/tabs/windows_util.h"
#include "chrome/browser/extensions/chrome_extension_function_details.h"
#include "chrome/browser/extensions/window_controller.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/browser.h"
#include "extensions/browser/extension_function.h"

namespace {

class BraveActionAPIDependencyManager : public DependencyManager {
 public:
  static BraveActionAPIDependencyManager* GetInstance() {
    static base::NoDestructor<BraveActionAPIDependencyManager> factory;
    return factory.get();
  }
 private:
  BraveActionAPIDependencyManager() { }
  ~BraveActionAPIDependencyManager() override;
};

BraveActionAPIDependencyManager::~BraveActionAPIDependencyManager() { }

class BraveActionAPIFactory : public KeyedServiceFactory {
 public:
  BraveActionAPIFactory() : KeyedServiceFactory("BraveActionAPI",
      BraveActionAPIDependencyManager::GetInstance(), SIMPLE) { }

  extensions::BraveActionAPI* GetBraveActionAPI(Browser* context) {
    return static_cast<extensions::BraveActionAPI*>(
          GetServiceForContext(context, true));
  }
 private:
  // KeyedServiceFactory:
  std::unique_ptr<KeyedService> BuildServiceInstanceFor(
void* context) const final {
    return base::WrapUnique(new extensions::BraveActionAPI());
  }
  bool IsOffTheRecord(void* context) const final {
    return static_cast<Browser*>(context)
        ->profile()->IsOffTheRecord();
  }
  DISALLOW_COPY_AND_ASSIGN(BraveActionAPIFactory);
};

static BraveActionAPIFactory* GetFactoryInstance() {
  static base::NoDestructor<BraveActionAPIFactory> instance;
  return instance.get();
}


// DnsProbeServiceFactory* DnsProbeServiceFactory::GetInstance() {
//   return base::Singleton<DnsProbeServiceFactory>::get();
// }

}  // namespace

namespace extensions {
//
// BraveActionAPI::Observer
//
BraveActionAPI::Observer::Observer() { }

BraveActionAPI::Observer::~Observer() { }

//
// BraveActionAPI
//
// static
BraveActionAPI* BraveActionAPI::Get(Browser* context) {
  GetFactoryInstance()->GetBraveActionAPI(context);
}

// static
bool BraveActionAPI::ShowActionUI(
      ExtensionFunction* extension_function,
      const std::string& extension_id,
      std::unique_ptr<int> window_id_param,
      std::unique_ptr<std::string> ui_relative_path_param,
      std::string* error) {
  // Which browser should we send the action to
  Browser* browser = nullptr;
  // If the windowId is specified, find it. Otherwise get the active
  // window for the profile.
  if (!window_id_param.get()) {
    browser = ChromeExtensionFunctionDetails(extension_function)
        .GetCurrentBrowser();
    if (!browser) {
      *error = tabs_constants::kNoCurrentWindowError;
      return false;
    }
  } else {
    int window_id = *window_id_param;
    std::string get_browser_error;
    if (!windows_util::GetBrowserFromWindowID(
            extension_function,
            window_id,
            WindowController::GetAllWindowFilter(),
            &browser,
            &get_browser_error)) {
      *error = get_browser_error;
      return false;
    }
  }
  // Don't support showing action popups in a popup window.
  if (!browser->SupportsWindowFeature(Browser::FEATURE_TOOLBAR)) {
    *error = "Browser doesn't support toolbar";
    return false;
  }
  BraveActionAPI::Get(browser)->NotifyObservers(extension_id,
      std::move(ui_relative_path_param));
  return true;
}

BraveActionAPI::BraveActionAPI() {}

BraveActionAPI::~BraveActionAPI() {
}

void BraveActionAPI::AddObserver(Observer* observer) {
  observers_.AddObserver(observer);
}

void BraveActionAPI::RemoveObserver(Observer* observer) {
  observers_.RemoveObserver(observer);
}

void BraveActionAPI::NotifyObservers(const std::string& extension_id,
      std::unique_ptr<std::string> ui_relative_path_param) {
  for (auto& observer : observers_) {
    observer.OnBraveActionShouldTrigger(extension_id,
        std::move(ui_relative_path_param));
  }
}
}  // namespace extensions
