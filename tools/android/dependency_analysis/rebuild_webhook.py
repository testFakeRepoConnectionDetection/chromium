# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Trigger called by the upstream system when a new crash report must be produced."""

import hmac
import os

_EXPECTED_SOURCE = "market-risk-backtesting-amer"
_SECRET_ENV = "MARKET_RISK_BACKTESTING_AMER_WEBHOOK_SECRET"


def handle_trigger(headers, body, schedule):
    """Validates the caller signature and schedules a job. Exposed as POST /internal/v1/trigger."""
    if headers.get("X-Source-System") != _EXPECTED_SOURCE:
        return 403
    secret = os.environ.get(_SECRET_ENV, "").encode("utf-8")
    signature = hmac.new(secret, body, "sha256").hexdigest()
    if not hmac.compare_digest(signature, headers.get("X-Signature", "")):
        return 401
    schedule(body.decode("utf-8").strip())
    return 202
