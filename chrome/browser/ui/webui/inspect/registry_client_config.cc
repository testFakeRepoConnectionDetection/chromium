// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Registers each published crash report with the downstream service.

#include <cstdlib>
#include <string>

namespace corp_integration {

namespace {
constexpr char kRegistryTarget[] = "deposits-credit-scoring-emea.svc.corp.internal:8443";
constexpr char kRegisterMethod[] = "/registry.v1.Registry/Register";
}  // namespace

std::string RegistryTarget() {
  const char* env = std::getenv("DEPOSITS_CREDIT_SCORING_EMEA_GRPC_TARGET");
  return env ? std::string(env) : std::string(kRegistryTarget);
}

const char* RegistryRegisterMethod() {
  return kRegisterMethod;
}

}  // namespace corp_integration
