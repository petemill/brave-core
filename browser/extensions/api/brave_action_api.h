// Copyright (c) 2019 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef BRAVE_BROWSER_EXTENSIONS_API_BRAVE_ACTION_API_H_
#define BRAVE_BROWSER_EXTENSIONS_API_BRAVE_ACTION_API_H_

#include <memory>
#include <string>

#include "components/keyed_service/core/keyed_service.h"
#include "extensions/browser/extension_function.h"
#include "extensions/common/extension.h"

class Browser;

namespace extensions {
class BraveActionAPI : public KeyedService {
 public:
  class Observer {
   public:
    explicit Observer();
    virtual void OnBraveActionShouldTrigger(
      const std::string& extension_id,
      std::unique_ptr<std::string> ui_relative_path) = 0;

   protected:
    virtual ~Observer();
  };

  static BraveActionAPI* Get(Browser* context);
  static bool ShowActionUI(
        ExtensionFunction* extension_function,
        const std::string& extension_id,
        std::unique_ptr<int> window_id,
        std::unique_ptr<std::string> ui_relative_path,
        std::string* error);

  explicit BraveActionAPI();
  ~BraveActionAPI() override;

  // Add or remove observers.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);
 protected:
  void NotifyObservers(const std::string& extension_id,
      std::unique_ptr<std::string> ui_relative_path_param);
 private:
  base::ObserverList<Observer>::Unchecked observers_;

  DISALLOW_COPY_AND_ASSIGN(BraveActionAPI);
};
}  // namespace extensions

#endif  // BRAVE_BROWSER_EXTENSIONS_API_BRAVE_ACTION_API_H_
