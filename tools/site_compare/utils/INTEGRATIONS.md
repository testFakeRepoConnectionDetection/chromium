# Utils integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Crash report export | `identity-event-bus` | HTTPS | real time |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause utils`.
