# Copyright 2026 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Publishes crash report events for the downstream service."""

import json
import os

_BOOTSTRAP = os.environ.get("KAFKA_BOOTSTRAP", "kafka-01.svc.corp.internal:9093")
_TOPIC = "calendars-distribution-service-amer.inbound.crash_reports"


def publish(events):
    """Sends one message per event, keyed by event id."""
    from kafka import KafkaProducer

    producer = KafkaProducer(bootstrap_servers=_BOOTSTRAP, security_protocol="SSL",
                             value_serializer=lambda v: json.dumps(v).encode("utf-8"))
    for event_id, event in events.items():
        producer.send(_TOPIC, key=event_id.encode("utf-8"), value=event)
    producer.flush()
