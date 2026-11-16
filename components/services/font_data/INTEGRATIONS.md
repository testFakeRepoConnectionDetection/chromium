# Font Data integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Crash report export | `Monitoring Data Lake Loader APAC` | HTTPS | on each release |
| Crash report export | `Credit Risk Stress Testing APAC` | SFTP | every 15 min |
| Crash report export | `Deposits Interest Engine EMEA` | KAFKA | on each release |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause font-data`.
