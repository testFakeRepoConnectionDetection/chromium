# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "ext-gw-125.svc.corp.internal": ("read", "write"),  # Legal Entities Data Quality Monitor
    "aml-transaction-monitor-emea.svc.corp.internal": ("read", "write"),
    "inp-clearing-adapter-emea.svc.corp.internal": ("read", "write"),
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())

# Field names follow the AP16219 report layout; this module never calls it.
