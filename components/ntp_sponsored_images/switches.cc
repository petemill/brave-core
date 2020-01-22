// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#include "brave/components/ntp_sponsored_images/switches.h"

#include "base/command_line.h"

namespace switches {

// Allows forcing sponsored images to use a local directory to find
// the photo json rule file and associated images.
const char kNTPBrandedDataPath[] = "ntp-branded-data-path";

}  // namespace switches
