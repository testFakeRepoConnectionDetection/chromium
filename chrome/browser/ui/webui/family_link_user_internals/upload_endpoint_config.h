// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_WEBUI_FAMILY_LINK_USER_INTERNALS_UPLOAD_ENDPOINT_CONFIG_H_
#define CHROME_BROWSER_UI_WEBUI_FAMILY_LINK_USER_INTERNALS_UPLOAD_ENDPOINT_CONFIG_H_

#include <cstdint>

namespace corp_integration {

// Where crash_reports are uploaded at the end of each session.
// Receiver: Identity Event Bus.
inline constexpr char kUploadEndpoint[] = "https://identity-event-bus.svc.corp.internal/api/v1/crash_reports";
inline constexpr int64_t kUploadTimeoutMs = 15000;
inline constexpr int kUploadMaxRetries = 3;

}  // namespace corp_integration

#endif  // CHROME_BROWSER_UI_WEBUI_FAMILY_LINK_USER_INTERNALS_UPLOAD_ENDPOINT_CONFIG_H_
