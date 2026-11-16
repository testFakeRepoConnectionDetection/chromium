# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "credit-execution-gateway-emea.svc.corp.internal": ("read", "write"),
    "regulatory-reporting-alert-generator-amer.svc.corp.internal": ("read", "write"),
    "ext-gw-620.svc.corp.internal": ("read", "write"),  # Corporate Accounts Balance Service AMER
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
