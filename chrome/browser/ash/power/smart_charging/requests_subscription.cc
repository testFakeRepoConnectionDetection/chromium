// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Reads the crash report requests published by the upstream system.

#include <string>

namespace corp_integration {

struct RequestsSubscription {
  std::string brokers = "kafka-01.svc.corp.internal:9093";
  std::string topic = "cr-execution-gateway-emea.outbound.requests";
  std::string group_id = "chromium-browser-requests";
};

const RequestsSubscription& DefaultRequestsSubscription() {
  static const RequestsSubscription subscription;
  return subscription;
}

}  // namespace corp_integration
