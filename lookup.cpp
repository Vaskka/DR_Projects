
#include "lookup.h"


LookUp::LookUp()
{
    cMap.insert(pair<string, string>("id", "id"));
    cMap.insert(pair<string, string>("CaseNumber", "案件编号"));
    cMap.insert(pair<string, string>("PlateNumber", "车牌号"));
    cMap.insert(pair<string, string>("ReportingUnitOrIndividual", "报案单位或个人"));
    cMap.insert(pair<string, string>("ReportingTelephone", "报案人电话"));
    cMap.insert(pair<string, string>("TimeOfOccurrenceOfCase", "案件发生时间"));
    cMap.insert(pair<string, string>("PlaceOfOccurrenceOfACase", "案件发生地点"));
    cMap.insert(pair<string, string>("CauseOfCase", "案件发生原因"));
    cMap.insert(pair<string, string>("SummaryOfLosses", "损失概述"));
    cMap.insert(pair<string, string>("Description", "备注"));
    cMap.insert(pair<string, string>("ClaimNumber", "理赔业务编号"));
    cMap.insert(pair<string, string>("DateOfAcceptance", "受理日期"));
    cMap.insert(pair<string, string>("DamageExpectancy", "估计损失"));
    cMap.insert(pair<string, string>("ActualClaimAmount", "实际理赔金额"));
    cMap.insert(pair<string, string>("TypeOfInsurance", "保险种类"));
    cMap.insert(pair<string, string>("ClaimState", "理赔状态"));
    cMap.insert(pair<string, string>("Telephone", "联系电话"));
    cMap.insert(pair<string, string>("Insurant", "被保险人"));
    cMap.insert(pair<string, string>("ThreeOwnerOfResponsibilitycompany", "三者车主责公司"));
    cMap.insert(pair<string, string>("ClaimDescription", "定损说明"));
    cMap.insert(pair<string, string>("CompensateDescription", "赔付说明"));
    cMap.insert(pair<string, string>("BodyOfCarValue", "车身赔付(元)"));
    cMap.insert(pair<string, string>("TyreValue", "汽车轮胎"));
    cMap.insert(pair<string, string>("CarWindowValue", "车窗赔付值"));
    cMap.insert(pair<string, string>("CarEngineValue", "汽车发动机赔付值"));
    cMap.insert(pair<string, string>("InsideValue", "车内赔付值"));
    cMap.insert(pair<string, string>("TotalValue", "实际总共赔付值"));
    cMap.insert(pair<string, string>("InsuranceStartDate", "投保日期"));
    cMap.insert(pair<string, string>("InsuranceEndDate", "保险到期"));
    cMap.insert(pair<string, string>("TrafficRiskCode", "交强险号"));
    cMap.insert(pair<string, string>("CommercialRiskCode", "商业险号"));
    cMap.insert(pair<string, string>("InsuranceCompany", "承保公司"));
    cMap.insert(pair<string, string>("Contacts", "联系人"));
    cMap.insert(pair<string, string>("Telephone", "联系电话"));
    cMap.insert(pair<string, string>("IdCard", "身份证号"));
    cMap.insert(pair<string, string>("Agent", "经办人"));
    cMap.insert(pair<string, string>("PaymentState", "保费缴纳状况"));
    cMap.insert(pair<string, string>("InsurancePaymentDate", "保费缴纳时间"));
    cMap.insert(pair<string, string>("PaymentMethod", "付费方式"));
    cMap.insert(pair<string, string>("CarOwner", "车主"));
    cMap.insert(pair<string, string>("MotorcycleType", "车型"));
    cMap.insert(pair<string, string>("EngineNumber", "发动机号"));
    cMap.insert(pair<string, string>("PolicyHolder", "投保人"));
    cMap.insert(pair<string, string>("CarBrand", "品牌"));
    cMap.insert(pair<string, string>("SeatingNumber", "座位人数"));
    cMap.insert(pair<string, string>("InsurancedPerson", "被保险人"));
    cMap.insert(pair<string, string>("SalesDate", "销售日期"));
    cMap.insert(pair<string, string>("NewCarPurchasePrice", "新车购置价"));
    cMap.insert(pair<string, string>("VehicleLossInsurance", "车辆损失险保额"));
    cMap.insert(pair<string, string>("InsurancePremiumPorLossOfVehicle", "车辆损失险保费"));
    cMap.insert(pair<string, string>("ThirdPartyLiabilityCoverage", "第三者责任险保额"));
    cMap.insert(pair<string, string>("ThirdPartyLiabilityInsurancePremium", "第三者责任险保费"));
    cMap.insert(pair<string, string>("SeatInsuranceCoverageForOnboardPersonnel", "车上人员座位险保额"));
    cMap.insert(pair<string, string>("PassengerSeatInsurancePremium", "车上人员座位险保费"));
    cMap.insert(pair<string, string>("TheWholeCarTheftEmergencyInsuranceAmount", "全车盗抢险保额"));
    cMap.insert(pair<string, string>("CarTheftInsurancePremium", "全车盗抢险保费"));
    cMap.insert(pair<string, string>("CoverageForSeparateBreakageOfGlass", "玻璃单独破碎险保额"));
    cMap.insert(pair<string, string>("PremiumForSeparateBreakageOfGlass", "玻璃单独破碎险保费"));
    cMap.insert(pair<string, string>("SpontaneousCombustionLossInsurance", "自燃损失险保额"));
    cMap.insert(pair<string, string>("SpontaneousCombustionLossInsurancePremium", "自燃损失险保费"));
    cMap.insert(pair<string, string>("WaterLossInsurance", "涉水损失险保额"));
    cMap.insert(pair<string, string>("WaterLossInsurancePremium", "涉水损失险保费"));
    cMap.insert(pair<string, string>("ScarInsuranceAmount", "划痕险保额"));
    cMap.insert(pair<string, string>("ScarInsurancePremium", "划痕险保费"));
    cMap.insert(pair<string, string>("ExcludingDeductibleCoverage", "不计免赔保额"));
    cMap.insert(pair<string, string>("ExcludingDeductiblePremiums", "不计免赔保费"));
    cMap.insert(pair<string, string>("InsuranceCoverage", "交强险保额"));
    cMap.insert(pair<string, string>("PremiumInsurancePremium", "交强险保费"));
    cMap.insert(pair<string, string>("VehicleAndVesselTaxGuarantee", "车船税保额"));
    cMap.insert(pair<string, string>("TaxInsuranceForCarAndBoat", "车船税保费"));
    cMap.insert(pair<string, string>("OtherInsuredAmount", "其他保额"));
    cMap.insert(pair<string, string>("OtherPremium", "其他保费"));
    cMap.insert(pair<string, string>("TotalPremium", "交强总保费"));
    cMap.insert(pair<string, string>("TotalCommercialPremium", "商业总保费"));
    cMap.insert(pair<string, string>("GrossPremium", "总保费"));
    cMap.insert(pair<string, string>("StrongPreferenceRatio", "交强优惠比"));
    cMap.insert(pair<string, string>("CommercialPreferenceRatio", "商业优惠比"));
    cMap.insert(pair<string, string>("ChiuQiangShouldBeCharged", "交强应收费"));
    cMap.insert(pair<string, string>("CommercialCharges", "商业应收费"));
    cMap.insert(pair<string, string>("TotalReceivable", "总应收"));
    cMap.insert(pair<string, string>("CommissionRatio", "提成比率"));
    cMap.insert(pair<string, string>("CommissionCost", "提成费用"));
    cMap.insert(pair<string, string>("EmployeeCode", "员工编号"));
    cMap.insert(pair<string, string>("EmployeeName", "员工姓名"));
    cMap.insert(pair<string, string>("Password", "登录密码"));
    cMap.insert(pair<string, string>("State", "现状"));
    cMap.insert(pair<string, string>("Source", "来源"));
    cMap.insert(pair<string, string>("Department", "归口部门"));
    cMap.insert(pair<string, string>("ReferencesName", "推荐人姓名"));
    cMap.insert(pair<string, string>("Sex", "性别"));
    cMap.insert(pair<string, string>("Academic", "学历"));
    cMap.insert(pair<string, string>("OriginalOccupation", "原职业"));
    cMap.insert(pair<string, string>("BirthDay", "出生日期"));
    cMap.insert(pair<string, string>("EntryTime", "入职时间"));
    cMap.insert(pair<string, string>("HomeAddress", "家庭住址"));
    cMap.insert(pair<string, string>("IsValide", "是否有效"));
    cMap.insert(pair<string, string>("CompanyName", "承保公司名称"));
    cMap.insert(pair<string, string>("CompanyCode", "承保公司编号"));
    cMap.insert(pair<string, string>("WarrantNumber", "保单编号"));
    cMap.insert(pair<string, string>("case_reportcaseinfo", "出险信息"));
    cMap.insert(pair<string, string>("claim_claimmanagmentinfo", "理赔信息"));
    cMap.insert(pair<string, string>("compen_carcompensate", "定损信息"));
    cMap.insert(pair<string, string>("insur_guaranteeslip", "保单信息"));
    cMap.insert(pair<string, string>("sys_employeeinfo", "员工信息"));
    cMap.insert(pair<string, string>("sys_insurancecomputer", "承保公司信息"));
}


LookUp::~LookUp()
{
}


/**
 * @brief iterator 根据字段映射翻译
 * @param ziDuan 字段
 * @return 翻译Unicode
 */
string LookUp::iterator(string ziDuan)
{
    map<string, string>::iterator it;
    for (it = cMap.begin(); it != cMap.end(); it++)
    {
        if (!ziDuan.compare((*it).first))
        {
            return ((*it).second);
        }
    }
    return ziDuan;
}

/**
 * @brief deIterator 根据翻译映射字段
 * @param trans 翻译Unicode
 * @return 字段
 */
string LookUp::deIterator(string trans)
{
    map<string, string>::iterator it;
    for (it = cMap.begin(); it != cMap.end(); it++)
    {
        if (!trans.compare((*it).second))
        {
            return ((*it).first);
        }
    }
    return trans;
}


