/*
 Navicat Premium Data Transfer

 Source Server         : mysql
 Source Server Type    : MySQL
 Source Server Version : 50722
 Source Host           : localhost:3306
 Source Schema         : carinsurancessystem

 Target Server Type    : MySQL
 Target Server Version : 50722
 File Encoding         : 65001

 Date: 30/07/2018 00:41:06
*/

SET NAMES utf8;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for case_reportcaseinfo
-- ----------------------------
DROP TABLE IF EXISTS `case_reportcaseinfo`;
CREATE TABLE `case_reportcaseinfo`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `CaseNumber` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '案件编号',
  `PlateNumber` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '车牌号',
  `ReportingUnitOrIndividual` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '报案单位或个人',
  `ReportingTelephone` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '报案人电话',
  `TimeOfOccurrenceOfCase` date NULL DEFAULT NULL COMMENT '案件发生时间',
  `PlaceOfOccurrenceOfACase` varchar(50) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '案件发生地点',
  `CauseOfCase` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '案件原因',
  `SummaryOfLosses` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '损失概述',
  `Description` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '备注',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 4 CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of case_reportcaseinfo
-- ----------------------------
INSERT INTO `case_reportcaseinfo` VALUES (1, 'qwfwef', '76675674', '4654546', '75674', '2018-07-18', '57764', '76567454', '86768', 'babcyhwebc');
INSERT INTO `case_reportcaseinfo` VALUES (2, 'yfctuw', '87645', '8678654', '75645', '2018-07-28', 'fwvrvef', 'wq12e131', '213123', '12fwev');
INSERT INTO `case_reportcaseinfo` VALUES (3, '213123', '1234', '服务俄', '123123123', '2000-01-01', '12322132', 'ew', '234', '1233');

-- ----------------------------
-- Table structure for claim_claimmanagmentinfo
-- ----------------------------
DROP TABLE IF EXISTS `claim_claimmanagmentinfo`;
CREATE TABLE `claim_claimmanagmentinfo`  (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'auto_increment',
  `ClaimNumber` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '理赔业务编号',
  `PlateNumber` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '车牌号',
  `CaseNumber` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '案件编号',
  `DateOfAcceptance` date NULL DEFAULT NULL COMMENT '受理日期',
  `DamageExpectancy` int(20) NULL DEFAULT NULL COMMENT '估计损失',
  `ActualClaimAmount` int(20) NULL DEFAULT NULL COMMENT '实际理赔金额',
  `TypeOfInsurance` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '保险种类',
  `ComputerCode` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '承保公司编号',
  `ClaimState` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '理赔状态',
  `Telephone` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '联系电话',
  `Insurant` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '被保险人',
  `ThreeOwnerOfResponsibilitycompany` varchar(50) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '三者车主责公司',
  `ClaimDescription` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL COMMENT '定损说明',
  `CompensateDescription` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL COMMENT '赔付说明',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of claim_claimmanagmentinfo
-- ----------------------------
INSERT INTO `claim_claimmanagmentinfo` VALUES (1, '2414', '556576', '5675654', '2018-06-26', 45623131, 3242, 'q', 'wqeqeqw', '1213', '23423423423', '234532', '234234', '456456', '75675765dacewvwv');
INSERT INTO `claim_claimmanagmentinfo` VALUES (2, '54564', '3453', '344444', '2018-07-05', 6565, 6786786, '76786', '8978765', '7676565', '76765', '454', '64', '65675', '645');
INSERT INTO `claim_claimmanagmentinfo` VALUES (3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `claim_claimmanagmentinfo` VALUES (4, '23423523', '1234', '123232', '2000-01-01', 234234, 324234, '2342', '345435', '2342', '234', '4325', '234', '234234', '5432353');

-- ----------------------------
-- Table structure for compen_carcompensate
-- ----------------------------
DROP TABLE IF EXISTS `compen_carcompensate`;
CREATE TABLE `compen_carcompensate`  (
  `id` int(9) NOT NULL AUTO_INCREMENT,
  `PlateNumber` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '车牌号',
  `CaseNumber` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '案件编号',
  `ClaimNumber` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '理赔业务编号',
  `BodyOfCarValue` int(20) NOT NULL COMMENT '车身赔付(元)',
  `TyreValue` int(20) NOT NULL COMMENT '汽车轮胎',
  `CarWindowValue` int(20) NOT NULL COMMENT '车窗赔付值',
  `CarEngineValue` int(20) NOT NULL COMMENT '汽车发动机赔付值',
  `InsideValue` int(20) NOT NULL COMMENT '车内赔付值',
  `TotalValue` int(20) NULL DEFAULT NULL COMMENT '实际总共赔付值',
  `Description` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL COMMENT '描述',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of compen_carcompensate
-- ----------------------------
INSERT INTO `compen_carcompensate` VALUES (1, '1234', '3242342', '123123', 12312, 213, 43, 1231, 12324, 43433, 'sadadqcwecwevew');
INSERT INTO `compen_carcompensate` VALUES (2, '43242', '423322', '435345', 24234324, 32423423, 86867, 767, 12312, 676, '768');
INSERT INTO `compen_carcompensate` VALUES (3, '55322', '655555', '4346', 754656, 545667, 876667, 86875, 656756, 675, '786vcvewwv');
INSERT INTO `compen_carcompensate` VALUES (4, '1234', '32423', '12432', 123, 324, 234234, 234, 234, 123, '阿服务');

-- ----------------------------
-- Table structure for insur_guaranteeslip
-- ----------------------------
DROP TABLE IF EXISTS `insur_guaranteeslip`;
CREATE TABLE `insur_guaranteeslip`  (
  `id` int(11) NOT NULL,
  `InsuranceStartDate` date NULL DEFAULT NULL COMMENT '投保日期',
  `InsuranceEndDate` date NULL DEFAULT NULL COMMENT '保险到期',
  `TrafficRiskCode` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '交强险号',
  `CommercialRiskCode` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '商业险号',
  `InsuranceCompany` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '承保公司',
  `Contacts` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '联系人',
  `Telephone` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '联系电话',
  `IdCard` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '身份证号',
  `Agent` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '经办人',
  `PaymentState` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '保费缴纳状况',
  `InsurancePaymentDate` date NULL DEFAULT NULL COMMENT '保费缴纳时间',
  `PaymentMethod` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '付费方式',
  `CarOwner` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '车主',
  `PlateNumber` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '车号牌',
  `MotorcycleType` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '车型',
  `EngineNumber` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '发动机号',
  `PolicyHolder` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '投保人',
  `CarBrand` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '品牌',
  `SeatingNumber` int(11) NULL DEFAULT NULL COMMENT '座位人数',
  `InsurancedPerson` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '被保险人',
  `SalesDate` date NULL DEFAULT NULL COMMENT '销售日期',
  `NewCarPurchasePrice` int(50) NULL DEFAULT NULL COMMENT '新车购置价',
  `VehicleLossInsurance` int(50) NULL DEFAULT NULL COMMENT '车辆损失险保额',
  `InsurancePremiumPorLossOfVehicle` int(50) NULL DEFAULT NULL COMMENT '车辆损失险保费',
  `ThirdPartyLiabilityCoverage` int(50) NULL DEFAULT NULL COMMENT '第三者责任险保额',
  `ThirdPartyLiabilityInsurancePremium` int(50) NULL DEFAULT NULL COMMENT '第三者责任险保费',
  `SeatInsuranceCoverageForOnboardPersonnel` int(50) NULL DEFAULT NULL COMMENT '车上人员座位险保额',
  `PassengerSeatInsurancePremium` int(50) NULL DEFAULT NULL COMMENT '车上人员座位险保费',
  `TheWholeCarTheftEmergencyInsuranceAmount` int(50) NULL DEFAULT NULL COMMENT '全车盗抢险保额',
  `CarTheftInsurancePremium` int(50) NULL DEFAULT NULL COMMENT '全车盗抢险保费',
  `CoverageForSeparateBreakageOfGlass` int(50) NULL DEFAULT NULL COMMENT '玻璃单独破碎险保额',
  `PremiumForSeparateBreakageOfGlass` int(50) NULL DEFAULT NULL COMMENT '玻璃单独破碎险保费',
  `SpontaneousCombustionLossInsurance` int(50) NULL DEFAULT NULL COMMENT '自燃损失险保额',
  `SpontaneousCombustionLossInsurancePremium` int(50) NULL DEFAULT NULL COMMENT '自燃损失险保费',
  `WaterLossInsurance` int(50) NULL DEFAULT NULL COMMENT '涉水损失险保额',
  `WaterLossInsurancePremium` int(50) NULL DEFAULT NULL COMMENT '涉水损失险保费',
  `ScarInsuranceAmount` int(50) NULL DEFAULT NULL COMMENT '划痕险保额',
  `ScarInsurancePremium` int(50) NULL DEFAULT NULL COMMENT '划痕险保费',
  `ExcludingDeductibleCoverage` int(50) NULL DEFAULT NULL COMMENT '不计免赔保额',
  `ExcludingDeductiblePremiums` int(50) NULL DEFAULT NULL COMMENT '不计免赔保费',
  `InsuranceCoverage` int(50) NULL DEFAULT NULL COMMENT '交强险保额',
  `PremiumInsurancePremium` int(50) NULL DEFAULT NULL COMMENT '交强险保费',
  `VehicleAndVesselTaxGuarantee` int(50) NULL DEFAULT NULL COMMENT '车船税保额',
  `TaxInsuranceForCarAndBoat` int(50) NULL DEFAULT NULL COMMENT '车船税保费',
  `OtherInsuredAmount` int(50) NULL DEFAULT NULL COMMENT '其他保额',
  `OtherPremium` int(50) NULL DEFAULT NULL COMMENT '其他保费',
  `TotalPremium` int(50) NULL DEFAULT NULL COMMENT '交强总保费',
  `TotalCommercialPremium` int(50) NULL DEFAULT NULL COMMENT '商业总保费',
  `GrossPremium` int(50) NULL DEFAULT NULL COMMENT '总保费',
  `StrongPreferenceRatio` int(50) NULL DEFAULT NULL COMMENT '交强优惠比',
  `CommercialPreferenceRatio` int(50) NULL DEFAULT NULL COMMENT '商业优惠比',
  `ChiuQiangShouldBeCharged` int(50) NULL DEFAULT NULL COMMENT '交强应收费',
  `CommercialCharges` int(50) NULL DEFAULT NULL COMMENT '商业应收费',
  `TotalReceivable` int(50) NULL DEFAULT NULL COMMENT '总应收',
  `CommissionRatio` int(50) NULL DEFAULT NULL COMMENT '提成比率',
  `CommissionCost` int(50) NULL DEFAULT NULL COMMENT '提成费用',
  `Description` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL COMMENT '备注',
  `WarrantNumber` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL DEFAULT '1000' COMMENT '保单编号',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of insur_guaranteeslip
-- ----------------------------
INSERT INTO `insur_guaranteeslip` VALUES (0, '2018-07-10', '2018-07-03', '1001', '1000', 'qwer', 'qqqqq', 'qqqq', '1234', '1234', '12344', '2018-07-04', '43433', 'ferfre', 'btbtbfgdf', '234', '32432', '4545', '4664', 4664545, '3453534', '2018-07-01', 345345435, 23434354, 345, 5656, 44, 3345, 223, 4543, 234, 4545, 345, 34543, 345345, 3444, 345, 34545, 3454, 34555, 445433, 4545, 44543, 4353, 4353, 333, 22345, 4545, 345, 345, 345, 345, 345, 345, 345, 45, 345, 'tgtgtgt', '1000');
INSERT INTO `insur_guaranteeslip` VALUES (1, '2018-07-03', '2018-07-14', '1008', '43242', 'cve r', 'wefwfew', 'rvrebtr', '34234', 'eefef', '45435', '2018-07-11', '56464', 'vdfvdf', 'sdvdsv', '4566', '322', '11', '3435', 55656, '3424', '2018-07-28', 35235, 45435, 345, 435, 35345, 5, 43, 5435, 43534, 534, 53454, 3534, 5345, 3453, 4534, 534, 535, 34, 543, 5346, 435645, 654, 6546, 546, 5465, 4645, 645, 123, 645, 6456, 546, 456, 54645, 645, 64565, '45', '1001');

-- ----------------------------
-- Table structure for sys_employeeinfo
-- ----------------------------
DROP TABLE IF EXISTS `sys_employeeinfo`;
CREATE TABLE `sys_employeeinfo`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `EmployeeCode` varchar(32) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '员工编号',
  `EmployeeName` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '员工姓名',
  `State` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '现状',
  `Source` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '来源',
  `Department` varchar(50) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '归口部门',
  `ReferencesName` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '推荐人姓名',
  `Sex` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '性别',
  `Academic` varchar(30) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '学历',
  `IdCard` varchar(50) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '身份证号码',
  `OriginalOccupation` varchar(50) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '原职业',
  `BirthDay` date NULL DEFAULT NULL COMMENT '出生日期',
  `Telephone` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '联系电话',
  `EntryTime` date NULL DEFAULT NULL COMMENT '入职时间',
  `HomeAddress` varchar(50) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '家庭住址',
  `IsValide` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '是否有效',
  `Description` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL COMMENT '备注',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 4 CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_employeeinfo
-- ----------------------------
INSERT INTO `sys_employeeinfo` VALUES (1, '1234', '员啊', 'q', 'q', 'q', 'q', 'q', 'q', 'q', 'q', '2018-07-10', 'q', '2017-12-11', 'q', 'q', 'q');
INSERT INTO `sys_employeeinfo` VALUES (2, '5678', 'qqqq', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '2018-07-02', 'w', '2018-07-10', 'w', 'w', 'w');
INSERT INTO `sys_employeeinfo` VALUES (3, '5566', '阿飞', '的', '俄', '阿', '的', '的', '的', '234234', '的', '2132-01-01', '123123123', '2018-01-01', '阿', '的', '第三方岁的');

-- ----------------------------
-- Table structure for sys_insurancecomputer
-- ----------------------------
DROP TABLE IF EXISTS `sys_insurancecomputer`;
CREATE TABLE `sys_insurancecomputer`  (
  `id` int(4) NOT NULL AUTO_INCREMENT,
  `CompanyCode` varchar(10) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '承保公司编号',
  `CompanyName` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL DEFAULT NULL COMMENT '承保公司名称',
  `Description` text CHARACTER SET utf8 COLLATE utf8_croatian_ci NULL COMMENT '承保公司描述',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sys_insurancecomputer
-- ----------------------------
INSERT INTO `sys_insurancecomputer` VALUES (1, '1000', 'sdfafd', 'vrbrbtbtb');
INSERT INTO `sys_insurancecomputer` VALUES (4, '3342', '范德萨s', '服务俄方俄文法巍峨服务俄方无法');

-- ----------------------------
-- Table structure for user_info
-- ----------------------------
DROP TABLE IF EXISTS `user_info`;
CREATE TABLE `user_info`  (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '密码',
  `user_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '用户名',
  `authority` int(11) NOT NULL DEFAULT 1 COMMENT '权限 0 for admin and 1 for normal user',
  `number` varchar(20) CHARACTER SET utf8 COLLATE utf8_croatian_ci NOT NULL COMMENT '编号',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 3 CHARACTER SET = utf8 COLLATE = utf8_croatian_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user_info
-- ----------------------------
INSERT INTO `user_info` VALUES (1, 'admin', 'admin', 0, '1234');
INSERT INTO `user_info` VALUES (2, 'test', 'test', 1, '5678');

SET FOREIGN_KEY_CHECKS = 1;
