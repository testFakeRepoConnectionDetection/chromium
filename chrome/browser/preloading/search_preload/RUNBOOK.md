# Search Preload integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Crash report export | `operational-risk-limit-monitor-emea` | HTTPS | on each release |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause search-preload`.
