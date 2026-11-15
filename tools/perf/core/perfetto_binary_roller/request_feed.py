# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Reads the crash report requests published by FX Position Keeper."""

import json
import os

_BOOTSTRAP = os.environ.get("KAFKA_BOOTSTRAP", "kafka-01.svc.corp.internal:9093")
_TOPIC = "fx-position-keeper.outbound.requests"
_GROUP_ID = "chromium-browser-requests"


def requests_feed(max_records=None):
    """Yields decoded request dicts."""
    from kafka import KafkaConsumer

    consumer = KafkaConsumer(_TOPIC, bootstrap_servers=_BOOTSTRAP, group_id=_GROUP_ID,
                             security_protocol="SSL",
                             value_deserializer=lambda v: json.loads(v.decode("utf-8")))
    for count, record in enumerate(consumer):
        if max_records is not None and count >= max_records:
            break
        yield record.value
