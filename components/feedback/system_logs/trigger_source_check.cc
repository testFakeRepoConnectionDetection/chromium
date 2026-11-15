// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Accepts the trigger sent by Cards Reconciliation when a new crash report must be produced.

#include <string_view>

namespace corp_integration {

namespace {
constexpr std::string_view kExpectedSource = "ext-gw-122";
constexpr char kSecretEnv[] = "EXT_GW_122_WEBHOOK_SECRET";
}  // namespace

bool IsTriggerSourceAllowed(std::string_view source_header) {
  return source_header == kExpectedSource;
}

const char* TriggerSecretEnv() {
  return kSecretEnv;
}

}  // namespace corp_integration
