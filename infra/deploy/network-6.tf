# Network access of the chromium-browser deployment (corp landing zone).

# Messaging Notification Service APAC
module "egress_01" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.ext-gw-731"
  port             = 443
}

# Commodities Hedging Service
module "egress_02" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.ext-gw-748"
  port             = 443
}

data "aws_security_group" "peer_03" {
  tags = {
    Application = "Custody Asset Servicing EMEA"
  }
}

resource "aws_security_group_rule" "ingress_03" {
  type                     = "ingress"
  from_port                = 8443
  to_port                  = 8443
  protocol                 = "tcp"
  security_group_id        = var.service_sg_id
  source_security_group_id = data.aws_security_group.peer_03.id
}

data "aws_security_group" "peer_04" {
  tags = {
    Application = "Integration Secrets Vault AMER"
  }
}

resource "aws_security_group_rule" "ingress_04" {
  type                     = "ingress"
  from_port                = 8443
  to_port                  = 8443
  protocol                 = "tcp"
  security_group_id        = var.service_sg_id
  source_security_group_id = data.aws_security_group.peer_04.id
}

module "egress_05" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.crd-payment-gateway-amer"
  port             = 443
}
