# Tool integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Crash report export | `deposits-credit-scoring-apac` | HTTPS | every 15 min |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause tool`.
