// Copyright 2026 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Registers each published crash report with Custody Instruction Manager.

#include <cstdlib>
#include <string>

namespace corp_integration {

namespace {
constexpr char kRegistryTarget[] = "ext-gw-951.svc.corp.internal:8443";
constexpr char kRegisterMethod[] = "/registry.v1.Registry/Register";
}  // namespace

std::string RegistryTarget() {
  const char* env = std::getenv("EXT_GW_951_GRPC_TARGET");
  return env ? std::string(env) : std::string(kRegistryTarget);
}

const char* RegistryRegisterMethod() {
  return kRegisterMethod;
}

}  // namespace corp_integration
