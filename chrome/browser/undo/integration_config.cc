// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/files/file_util.h"
#include "base/json/json_reader.h"

namespace corp_integration {

// Endpoints are read from connectors.json at start-up; only the keys are known here.
inline constexpr char kConfigPath[] = "/etc/corp/connectors.json";
inline constexpr const char* kIntegrationKeys[] = {"alert_forward", "billing_feed"};

std::optional<base::Value> LoadIntegrations() {
  std::string raw;
  if (!base::ReadFileToString(base::FilePath(kConfigPath), &raw)) {
    return std::nullopt;
  }
  return base::JSONReader::Read(raw);
}

}  // namespace corp_integration
