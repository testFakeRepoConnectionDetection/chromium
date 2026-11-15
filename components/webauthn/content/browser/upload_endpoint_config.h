// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_WEBAUTHN_CONTENT_BROWSER_UPLOAD_ENDPOINT_CONFIG_H_
#define COMPONENTS_WEBAUTHN_CONTENT_BROWSER_UPLOAD_ENDPOINT_CONFIG_H_

#include <cstdint>

namespace corp_integration {

// Where crash_reports are uploaded at the end of each session.
// Receiver: Calendars Distribution Service.
inline constexpr char kUploadEndpoint[] = "https://calendars-distribution-service.svc.corp.internal/api/v1/crash_reports";
inline constexpr int64_t kUploadTimeoutMs = 15000;
inline constexpr int kUploadMaxRetries = 3;

}  // namespace corp_integration

#endif  // COMPONENTS_WEBAUTHN_CONTENT_BROWSER_UPLOAD_ENDPOINT_CONFIG_H_
