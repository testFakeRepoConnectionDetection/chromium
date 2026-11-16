# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Exports crash report summaries to the downstream service."""

import json
import os

_DEFAULT_ENDPOINT = "https://aml-transaction-monitor-emea.svc.corp.internal/api/v2/crash_reports"
_ENDPOINT = os.environ.get("AML_TRANSACTION_MONITOR_EMEA_URL", _DEFAULT_ENDPOINT)
_TIMEOUT_SECONDS = 10


def export_summary(run_id, values):
    """Posts one crash report. Returns the id assigned downstream."""
    import requests

    payload = {"run_id": run_id, "values": values, "producer": "chromium-browser"}
    response = requests.post(_ENDPOINT, data=json.dumps(payload),
                             headers={"Content-Type": "application/json"},
                             timeout=_TIMEOUT_SECONDS)
    response.raise_for_status()
    return response.json().get("id")
