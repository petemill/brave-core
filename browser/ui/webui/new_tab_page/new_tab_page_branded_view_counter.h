// Copyright (c) 2019 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef BRAVE_BROWSER_UI_WEBUI_NEW_TAB_PAGE_NEW_TAB_PAGE_BRANDED_VIEW_COUNTER_H_
#define BRAVE_BROWSER_UI_WEBUI_NEW_TAB_PAGE_NEW_TAB_PAGE_BRANDED_VIEW_COUNTER_H_

#include <memory>

#include "components/keyed_service/core/keyed_service.h"
#include "components/prefs/pref_change_registrar.h"
#include "brave/browser/ui/webui/new_tab_page/branded_wallpaper.h"

class Profile;

class NewTabPageBrandedViewCounter : public KeyedService {
 public:
  static NewTabPageBrandedViewCounter* GetForProfile(Profile* profile);

  explicit NewTabPageBrandedViewCounter(Profile* profile);
  ~NewTabPageBrandedViewCounter() override;

  // Lets the counter know that a New Tab Page view has occured.
  // This should always be called as it will evaluate whether the user has
  // opted-in or data is available.
  void RegisterPageView();
  // Do we have a branded wallpaper to show and has the user
  // opted-in to showing it at some time.
  bool IsBrandedWallpaperActive();
  // Should we show the branded wallpaper right now, in addition
  // to the result from `IsBrandedWallpaperActive()`.
  bool GetShouldShowBrandedWallpaper();
  // Gets the current data for branded wallpaper, if there
  // is a wallpaper active. Does not consider user opt-in
  // status, or consider whether the wallpaper should be shown.
  const BrandedWallpaper& GetBrandedWallpaper();

 private:
  bool GetBrandedWallpaperFromDataSource();
  void SetShouldShowFromPreferences();

  // TODO(petemill): Update this when the remote data source
  // receives new data.
  std::unique_ptr<BrandedWallpaper> current_wallpaper_ = nullptr;
  bool has_user_opted_in_;
  int count_to_branded_wallpaper_;
  PrefChangeRegistrar pref_change_registrar_;
  Profile* profile_;

  DISALLOW_COPY_AND_ASSIGN(NewTabPageBrandedViewCounter);
};

#endif  // BRAVE_BROWSER_UI_WEBUI_NEW_TAB_PAGE_NEW_TAB_PAGE_BRANDED_VIEW_COUNTER_H_
