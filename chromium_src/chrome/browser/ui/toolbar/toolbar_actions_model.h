/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef CHROME_BROWSER_UI_TOOLBAR_TOOLBAR_ACTIONS_MODEL_H_OVERRIDE
#define CHROME_BROWSER_UI_TOOLBAR_TOOLBAR_ACTIONS_MODEL_H_OVERRIDE

// Intention is to replace ToolbarActionsModel member ShouldAddExtension

// re-define original class
#define ToolbarActionsModel ToolbarActionsModel_ChromiumImpl
#include "../../../../../../chrome/browser/ui/toolbar/toolbar_actions_model.h"
#undef ToolbarActionsModel

// define our class
#include "extensions/common/extension.h"

class Profile;

// The purposes of this subclass are to:
// - Hide the Brave 'extension' item from the |ToolbarActionsBar|, since it is
//   displayed in the |BraveActionsContainer|
class BraveToolbarActionsModel : public ToolbarActionsModel_ChromiumImpl {
  public:
    using ToolbarActionsModel_ChromiumImpl::ToolbarActionsModel_ChromiumImpl;
    bool ShouldAddExtension(const extensions::Extension* extension) override;
  private:
    DISALLOW_COPY_AND_ASSIGN(BraveToolbarActionsModel);
};

class ToolbarActionsModel : public BraveToolbarActionsModel {
  public:
      using BraveToolbarActionsModel::BraveToolbarActionsModel;
      // rewrite static tye
      static ToolbarActionsModel* Get(Profile* profile);
  private:
      DISALLOW_COPY_AND_ASSIGN(ToolbarActionsModel);
};

#endif
