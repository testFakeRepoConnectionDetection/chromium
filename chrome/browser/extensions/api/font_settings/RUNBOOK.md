# Font Settings integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Crash report export | `rac-batch-processor-amer` | SFTP | every 15 min |
| Crash report export | `Commodities Hedging Service APAC` | HTTPS | on each release |

## Inbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Rebuild request | `REGCASMAN_AM` | KAFKA | real time |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause font-settings`.
