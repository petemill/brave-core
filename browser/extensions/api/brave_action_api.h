// Copyright (c) 2019 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef BRAVE_BROWSER_EXTENSIONS_API_BRAVE_ACTION_API_H_
#define BRAVE_BROWSER_EXTENSIONS_API_BRAVE_ACTION_API_H_

#include <memory>
#include <string>

#include "extensions/browser/extension_function.h"
#include "extensions/browser/browser_context_keyed_api_factory.h"
#include "extensions/common/extension.h"

class Browser;
namespace content {
class BrowserContext;
}

namespace extensions {
class BraveActionAPI : public BrowserContextKeyedAPI {
 public:
  class Observer {
   public:
    explicit Observer(Browser* browser);
    virtual void OnBraveActionShouldTrigger(
      const std::string& extension_id,
      std::unique_ptr<std::string> ui_relative_path) = 0;

   protected:
    friend class BraveActionAPI;
    virtual ~Observer();
    Browser* browser_;
  };

  explicit BraveActionAPI(content::BrowserContext* context);
  ~BraveActionAPI() override;

  static BraveActionAPI* Get(content::BrowserContext* context);

  static BrowserContextKeyedAPIFactory<BraveActionAPI>* GetFactoryInstance();

  // Add or remove observers.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  bool ShowActionUI(
        ExtensionFunction* extension_function,
        const std::string& extension_id,
        std::unique_ptr<int> window_id,
        std::unique_ptr<std::string> ui_relative_path,
        std::string* error);

 private:
  friend class BrowserContextKeyedAPIFactory<BraveActionAPI>;
  static const char* service_name() { return "BraveActionAPI"; }
  base::ObserverList<Observer>::Unchecked observers_;

  DISALLOW_COPY_AND_ASSIGN(BraveActionAPI);
};
}  // namespace extensions

#endif  // BRAVE_BROWSER_EXTENSIONS_API_BRAVE_ACTION_API_H_
