// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Registers each published crash report with Accounting Consolidation APAC.

#include <cstdlib>
#include <string>

namespace corp_integration {

namespace {
constexpr char kRegistryTarget[] = "accounting-consolidation-apac.svc.corp.internal:8443";
constexpr char kRegisterMethod[] = "/registry.v1.Registry/Register";
}  // namespace

std::string RegistryTarget() {
  const char* env = std::getenv("ACCOUNTING_CONSOLIDATION_APAC_GRPC_TARGET");
  return env ? std::string(env) : std::string(kRegistryTarget);
}

const char* RegistryRegisterMethod() {
  return kRegisterMethod;
}

}  // namespace corp_integration
