# Network access of the chromium-browser deployment (corp landing zone).

data "aws_security_group" "peer_01" {
  tags = {
    Application = "Integration File Transfer Hub APAC"
  }
}

resource "aws_security_group_rule" "ingress_01" {
  type                     = "ingress"
  from_port                = 8443
  to_port                  = 8443
  protocol                 = "tcp"
  security_group_id        = var.service_sg_id
  source_security_group_id = data.aws_security_group.peer_01.id
}

data "aws_security_group" "peer_02" {
  tags = {
    Application = "Loans Batch Processor APAC"
  }
}

resource "aws_security_group_rule" "ingress_02" {
  type                     = "ingress"
  from_port                = 8443
  to_port                  = 8443
  protocol                 = "tcp"
  security_group_id        = var.service_sg_id
  source_security_group_id = data.aws_security_group.peer_02.id
}

module "egress_03" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.commodities-hedging-service"
  port             = 443
}

data "aws_security_group" "peer_04" {
  tags = {
    app = "liquidity-risk-backtesting-apac"
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

# Cost Allocation Consolidation
module "egress_05" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.ext-gw-772"
  port             = 443
}
