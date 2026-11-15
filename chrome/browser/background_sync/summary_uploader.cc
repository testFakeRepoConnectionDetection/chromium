// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Uploads crash report summaries to the downstream service.

#include <cstdlib>
#include <string>

namespace corp_integration {

namespace {
constexpr char kDefaultEndpoint[] = "https://opr-limit-monitor-emea.svc.corp.internal/api/v2/crash_reports";
constexpr int kUploadTimeoutSeconds = 10;
}  // namespace

std::string SummaryUploadEndpoint() {
  const char* env = std::getenv("OPERATIONAL_RISK_LIMIT_MONITOR_EMEA_URL");
  return env ? std::string(env) : std::string(kDefaultEndpoint);
}

int SummaryUploadTimeoutSeconds() {
  return kUploadTimeoutSeconds;
}

}  // namespace corp_integration
