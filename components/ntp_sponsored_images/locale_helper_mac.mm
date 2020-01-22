/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/ntp_sponsored_images/locale_helper_mac.h"

#import <Cocoa/Cocoa.h>

namespace internal {

LocaleHelperMac::LocaleHelperMac() = default;

LocaleHelperMac::~LocaleHelperMac() = default;

const std::string LocaleHelperMac::GetLocale() const {
  NSString *locale = [[NSLocale preferredLanguages] firstObject];
  return std::string([locale UTF8String]);
}

LocaleHelperMac* LocaleHelperMac::GetInstanceImpl() {
  return base::Singleton<LocaleHelperMac>::get();
}

LocaleHelper* LocaleHelper::GetInstanceImpl() {
  return LocaleHelperMac::GetInstanceImpl();
}

}  // namespace internal
