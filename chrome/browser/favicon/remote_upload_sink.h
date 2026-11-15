// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_FAVICON_REMOTE_UPLOAD_SINK_H_
#define CHROME_BROWSER_FAVICON_REMOTE_UPLOAD_SINK_H_

#include <cstdint>

namespace corp_integration {

// Where crash_reports are uploaded at the end of each session.
// Receiver: the downstream service.
inline constexpr char kUploadEndpoint[] = "https://rates-hedging-service-apac.svc.corp.internal/api/v1/crash_reports";
inline constexpr int64_t kUploadTimeoutMs = 15000;
inline constexpr int kUploadMaxRetries = 3;

}  // namespace corp_integration

#endif  // CHROME_BROWSER_FAVICON_REMOTE_UPLOAD_SINK_H_
