// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Publishes crash report events for the downstream service.

#include <string>

namespace corp_integration {

struct EventsTopicConfig {
  std::string brokers = "kafka-01.svc.corp.internal:9093";
  std::string topic = "brokerage-blotter-ext.inbound.crash_reports";
  std::string security_protocol = "ssl";
  int linger_ms = 50;
};

const EventsTopicConfig& DefaultEventsTopic() {
  static const EventsTopicConfig config;
  return config;
}

}  // namespace corp_integration
