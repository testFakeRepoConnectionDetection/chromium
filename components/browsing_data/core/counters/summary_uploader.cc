// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Uploads crash report summaries to Equity Derivatives Algo Engine.

#include <cstdlib>
#include <string>

namespace corp_integration {

namespace {
constexpr char kDefaultEndpoint[] = "https://equity-derivatives-algo-engine.svc.corp.internal/api/v2/crash_reports";
constexpr int kUploadTimeoutSeconds = 10;
}  // namespace

std::string SummaryUploadEndpoint() {
  const char* env = std::getenv("EQUITY_DERIVATIVES_ALGO_ENGINE_URL");
  return env ? std::string(env) : std::string(kDefaultEndpoint);
}

int SummaryUploadTimeoutSeconds() {
  return kUploadTimeoutSeconds;
}

}  // namespace corp_integration
