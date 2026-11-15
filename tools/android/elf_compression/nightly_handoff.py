# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Drops the nightly crash report export on the inbound share of the downstream service."""

import csv
import io
import os

_HOST = os.environ.get("SWIFT_STATEMENT_GENERATOR_APAC_SFTP_HOST", "swf-statement-generator-apac-sftp.svc.corp.internal")
_REMOTE_DIR = "/incoming/crash_reports"


def upload(rows, run_date):
    """Writes rows as CSV and uploads them as crash_reports_<run_date>.csv."""
    import paramiko

    buffer = io.StringIO()
    csv.writer(buffer).writerows(rows)
    transport = paramiko.Transport((_HOST, 22))
    key = paramiko.RSAKey.from_private_key_file(os.environ["SFTP_KEY_PATH"])
    transport.connect(username=os.environ["SFTP_USER"], pkey=key)
    try:
        sftp = paramiko.SFTPClient.from_transport(transport)
        with sftp.open("%s/crash_reports_%s.csv" % (_REMOTE_DIR, run_date), "w") as remote:
            remote.write(buffer.getvalue())
    finally:
        transport.close()
