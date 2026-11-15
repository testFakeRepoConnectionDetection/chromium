// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Accepts the trigger sent by Messaging Log Collector AMER when a new crash report must be produced.

#include <string_view>

namespace corp_integration {

namespace {
constexpr std::string_view kExpectedSource = "messaging-log-collector-amer";
constexpr char kSecretEnv[] = "MESSAGING_LOG_COLLECTOR_AMER_WEBHOOK_SECRET";
}  // namespace

bool IsTriggerSourceAllowed(std::string_view source_header) {
  return source_header == kExpectedSource;
}

const char* TriggerSecretEnv() {
  return kSecretEnv;
}

}  // namespace corp_integration
