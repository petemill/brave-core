/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

// Intention is to replace ToolbarActionsModel member ShouldAddExtension

#include "chrome/browser/ui/toolbar/toolbar_actions_model.h"

// re-define original class
#define ToolbarActionsModel ToolbarActionsModel_ChromiumImpl
#include "../../../../../../chrome/browser/ui/toolbar/toolbar_actions_model.cc"
#undef ToolbarActionsModel

// define our class members
#include "brave/common/extensions/extension_constants.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/toolbar/toolbar_actions_model_factory.h"
#include "extensions/common/extension.h"

bool BraveToolbarActionsModel::ShouldAddExtension(const extensions::Extension* extension) {
  // Don't show the Brave 'extension' in the ToolbarActions extensions area. It
  // will instead be shown in the BraveActions area.
  if (extension->id() == brave_extension_id) {
    return false;
  }
  return ToolbarActionsModel_ChromiumImpl::ShouldAddExtension(extension);
}

ToolbarActionsModel* ToolbarActionsModel::Get(Profile* profile) {
  return ToolbarActionsModelFactory::GetForProfile(profile);
}