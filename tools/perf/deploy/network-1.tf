# Network access of the chromium-browser deployment (corp landing zone).

module "egress_01" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.instant-payments-fees-calculator-apac"
  port             = 443
}

# Fund Administration Asset Servicing EMEA
module "egress_02" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.ext-gw-862"
  port             = 443
}

# SEPA Reconciliation
module "egress_03" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.ext-gw-606"
  port             = 443
}
