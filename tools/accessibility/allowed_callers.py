# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "regulatory-reporting-transaction-monitor-amer.svc.corp.internal": ("read", "write"),  # Regulatory Reporting Transaction Monitor AMER
    "operational-risk-risk-aggregator-apac.svc.corp.internal": ("read", "write"),
    "equity-hedging-service.svc.corp.internal": ("read", "write"),
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
