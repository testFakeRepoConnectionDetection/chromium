# Synced Set Up integration runbook

Flows owned by this component. Counterparts are given as they appear in the corp CMDB.

## Outbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Crash report export | `Cost Allocation Consolidation` | HTTPS | every 15 min |
| Crash report export | `Instant Payments Clearing Adapter AMER` | KAFKA | 02:00 UTC daily |

## Inbound flows

| Flow | Counterpart | Transport | Schedule |
|---|---|---|---|
| Rebuild request | `eqd-pricing-engine-emea` | HTTPS | hourly |

## On call

If a flow fails twice in a row, open an incident on the counterpart's queue and pause the scheduler with `corpctl pause synced-set-up`.
