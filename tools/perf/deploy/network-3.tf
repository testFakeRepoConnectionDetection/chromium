# Network access of the chromium-browser deployment (corp landing zone).

data "aws_security_group" "peer_01" {
  tags = {
    app_code = "AP36061"
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

module "egress_02" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.eqd-pricing-engine-apac"
  port             = 443
}

module "egress_03" {
  source           = "../modules/private-link-consumer"
  endpoint_service = "com.corp.privatelink.tsvruleng-am"
  port             = 443
}

data "aws_security_group" "peer_04" {
  tags = {
    app = "acme-clearing-gateway"
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
