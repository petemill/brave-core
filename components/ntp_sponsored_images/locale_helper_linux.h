/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_NTP_SPONSORED_IMAGES_LOCALE_HELPER_LINUX_H_
#define BRAVE_COMPONENTS_NTP_SPONSORED_IMAGES_LOCALE_HELPER_LINUX_H_

#include <string>

#include "brave/components/ntp_sponsored_images/locale_helper.h"

namespace internal {

class LocaleHelperLinux : public LocaleHelper {
 public:
  static LocaleHelperLinux* GetInstanceImpl();

 private:
  LocaleHelperLinux();
  ~LocaleHelperLinux() override;

  // LocaleHelper impl
  const std::string GetLocale() const override;

  friend struct base::DefaultSingletonTraits<LocaleHelperLinux>;
  DISALLOW_COPY_AND_ASSIGN(LocaleHelperLinux);
};

}  // namespace internal

#endif  // BRAVE_COMPONENTS_NTP_SPONSORED_IMAGES_LOCALE_HELPER_LINUX_H_
