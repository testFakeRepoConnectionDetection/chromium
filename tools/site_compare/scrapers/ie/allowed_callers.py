# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Client systems allowed to call the internal API.

Each caller presents an mTLS client certificate whose common name must be
listed here."""

ALLOWED_CLIENTS = {
    "credit-risk-sensitivities-service-apac.svc.corp.internal": ("read", "write"),
    "commodities-pricing-engine-amer.svc.corp.internal": ("read", "write"),
    "rates-market-data-feed-apac.svc.corp.internal": ("read", "write"),  # Rates Market Data Feed APAC
}


def is_allowed(common_name, method):
    return method in ALLOWED_CLIENTS.get(common_name, ())
