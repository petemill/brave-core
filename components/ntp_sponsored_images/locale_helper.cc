/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/ntp_sponsored_images/locale_helper.h"

namespace internal {

LocaleHelper::LocaleHelper() = default;

LocaleHelper::~LocaleHelper() = default;

const std::string LocaleHelper::GetLocale() const {
  return kDefaultLocale;
}

LocaleHelper* LocaleHelper::GetInstance() {
  return GetInstanceImpl();
}

}  // namespace internal
