#include "warrantinsertdialog.h"
#include "ui_warrantinsertdialog.h"
#include "queryset.h"
#include "insertexecuter.h"
#include <string>
using namespace std;


WarrantInsertDialog::WarrantInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarrantInsertDialog)
{
    ui->setupUi(this);
}

WarrantInsertDialog::~WarrantInsertDialog()
{
    delete ui;
}

void WarrantInsertDialog::on_Main_CommitButton_3_clicked()
{
    this->hide();
}

/**
 * @brief WarrantInsertDialog::on_Main_CommitButton_2_clicked 重置
 */
void WarrantInsertDialog::on_Main_CommitButton_2_clicked()
{

    ui->Insert_AgentEdit->clear();
    ui->Insert_BrandEdit->clear();
    ui->Insert_CommciEdit->clear();
    ui->Insert_ContactEdit->clear();
    ui->Insert_ForceEdit->clear();
    ui->Insert_IncEdit->clear();
    ui->Insert_InsureDate->clear();
    ui->Insert_InsuredEdit->clear();
    ui->Insert_NewCarPayEdit->clear();
    ui->Insert_OverDate->clear();
    ui->Insert_PayDate->clear();
    ui->Insert_PersonalNumberEdit->clear();
    ui->Insert_SeatingEdit->clear();
    ui->Insert_StatusEdit->clear();
    ui->Insert_TelEdit->clear();
    ui->Insert_ThroughDate->clear();
    ui->Insert_AllShouldEdit->clear();
    ui->Insert_CarKindEdit->clear();
    ui->Insert_CarNumberEdit->clear();
    ui->Insert_CarPersonEdit->clear();
    ui->Insert_CarShipEdit->clear();
    ui->Insert_CarShipPreEdit->clear();
    ui->Insert_CommicalDownRatioEdit->clear();
    ui->Insert_DeductibleEdit->clear();
    ui->Insert_DeductiblePreInsert->clear();
    ui->Insert_EngineNumberEdit->clear();
    ui->Insert_ForceDownRatioEdit->clear();
    ui->Insert_ForcePayEdit->clear();
    ui->Insert_ForcePayPreEdit->clear();
    ui->Insert_ForceShouldEdit->clear();
    ui->Insert_GrassEdit->clear();
    ui->Insert_GrassPreEdit->clear();
    ui->Insert_IncEdit->clear();
    ui->Insert_InsureDate->clear();
    ui->Insert_InsuredEdit->clear();
    ui->Insert_MainInsureEdit->clear();
    ui->Insert_MorePayEdit->clear();
    ui->Insert_MoreRatioEdit->clear();
    ui->Insert_NatureEdit->clear();
    ui->Insert_NaturePreEdit->clear();
    ui->Insert_NewCarPayEdit->clear();
    ui->Insert_OtherEdit->clear();
    ui->Insert_OtherPreEdit->clear();
    ui->Insert_OtherText->clear();
    ui->Insert_OverDate->clear();
    ui->Insert_PassengerEdit->clear();
    ui->Insert_PassengerPreEdit->clear();
    ui->Insert_PayDate->clear();
    ui->Insert_PayWayEdit->clear();
    ui->Insert_PersonalNumberEdit->clear();
    ui->Insert_ScarEdit->clear();
    ui->Insert_ScarPreInsert->clear();
    ui->Insert_SeatingEdit->clear();
    ui->Insert_StatusEdit->clear();
    ui->Insert_SumCommcialPreEdit->clear();
    ui->Insert_SumForcePreEdit->clear();
    ui->Insert_SumPreEdit->clear();
    ui->Insert_TelEdit->clear();
    ui->Insert_TheftEdit->clear();
    ui->Insert_TheftPreEdit->clear();
    ui->Insert_ThirdEdit->clear();
    ui->Insert_ThirdPreEdit->clear();
    ui->Insert_ThroughDate->clear();
    ui->Insert_VehicleLossEdit->clear();
    ui->Insert_VehicleLossPreEdit->clear();
    ui->Insert_WaterEdit->clear();
    ui->Insert_WaterPreEdit->clear();
}

void WarrantInsertDialog::on_Main_CommitButton_clicked()
{
    // 待完善保险算法

    string agent = ui->Insert_AgentEdit->text().toStdString();
    string brand =  ui->Insert_BrandEdit->text().toStdString();
    string commci =  ui->Insert_CommciEdit->text().toStdString();
    string contact =  ui->Insert_ContactEdit->text().toStdString();
    string force =  ui->Insert_ForceEdit->text().toStdString();
    string inc =  ui->Insert_IncEdit->text().toStdString();
    string insureDate =  ui->Insert_InsureDate->text().toStdString();
    string insured =  ui->Insert_InsuredEdit->text().toStdString();
    string newCarPay =  ui->Insert_NewCarPayEdit->text().toStdString();
    string overDate =   ui->Insert_OverDate->text().toStdString();
    string payDate =   ui->Insert_PayDate->text().toStdString();
    string personalNumber =  ui->Insert_PersonalNumberEdit->text().toStdString();
    string seating =  ui->Insert_SeatingEdit->text().toStdString();
    string status =  ui->Insert_StatusEdit->text().toStdString();
    string tel =   ui->Insert_TelEdit->text().toStdString();
    string throughDate =  ui->Insert_ThroughDate->text().toStdString();
    string allShould =  ui->Insert_AllShouldEdit->text().toStdString();
    string carKind =  ui->Insert_CarKindEdit->text().toStdString();
    string carNumber =   ui->Insert_CarNumberEdit->text().toStdString();
    string carPerson = ui->Insert_CarPersonEdit->text().toStdString();
    string carShip = ui->Insert_CarShipEdit->text().toStdString();
    string carShipPre =  ui->Insert_CarShipPreEdit->text().toStdString();
    string commialDownRatio =  ui->Insert_CommicalDownRatioEdit->text().toStdString();
    string deduct =  ui->Insert_DeductibleEdit->text().toStdString();
    string deductPre =  ui->Insert_DeductiblePreInsert->text().toStdString();
    string engineNumber =  ui->Insert_EngineNumberEdit->text().toStdString();
    string forceDownRatio =  ui->Insert_ForceDownRatioEdit->text().toStdString();
    string forcePay =  ui->Insert_ForcePayEdit->text().toStdString();
    string forcePayEdit =  ui->Insert_ForcePayPreEdit->text().toStdString();
    string forceShould =   ui->Insert_ForceShouldEdit->text().toStdString();
    string grass =  ui->Insert_GrassEdit->text().toStdString();
    string grassPre =  ui->Insert_GrassPreEdit->text().toStdString();
    string mainInsure =  ui->Insert_MainInsureEdit->text().toStdString();
    string morePay =   ui->Insert_MorePayEdit->text().toStdString();
    string moreRatio =  ui->Insert_MoreRatioEdit->text().toStdString();
    string nature =  ui->Insert_NatureEdit->text().toStdString();
    string naturePre =  ui->Insert_NaturePreEdit->text().toStdString();
    string other =  ui->Insert_OtherEdit->text().toStdString();
    string otherPre =  ui->Insert_OtherPreEdit->text().toStdString();
    string otherText =  ui->Insert_OtherText->toPlainText().toStdString();
    string Passenger =  ui->Insert_PassengerEdit->text().toStdString();
    string PassengerPre =  ui->Insert_PassengerPreEdit->text().toStdString();
    string payWay =  ui->Insert_PayWayEdit->text().toStdString();
    string scar =  ui->Insert_ScarEdit->text().toStdString();
    string scarPre =  ui->Insert_ScarPreInsert->text().toStdString();
    string sumCommcialPre =  ui->Insert_SumCommcialPreEdit->text().toStdString();
    string sumForcePre =  ui->Insert_SumForcePreEdit->text().toStdString();
    string SumPre = ui->Insert_SumPreEdit->text().toStdString();
    string theft = ui->Insert_TheftEdit->text().toStdString();
    string  theftPre = ui->Insert_TheftPreEdit->text().toStdString();
    string third =  ui->Insert_ThirdEdit->text().toStdString();
    string thirdPre =  ui->Insert_ThirdPreEdit->text().toStdString();
    string ThroughDate =  ui->Insert_ThroughDate->text().toStdString();
    string vehicleLoss =  ui->Insert_VehicleLossEdit->text().toStdString();
    string vehicleLossPre = ui->Insert_VehicleLossPreEdit->text().toStdString();
    string water =  ui->Insert_WaterEdit->text().toStdString();
    string waterPre =  ui->Insert_WaterPreEdit->text().toStdString();


    QuerySet data = QuerySet();



    data.setValue("Agent", agent);
    data.setValue("CarBrand", brand);
    data.setValue("CommercialRiskCode", commci);
    data.setValue("Contacts", contact);
    data.setValue("TrafficRiskCode", force);
    data.setValue("InsuranceCompany", inc);
    data.setValue("InsuranceStartDate", insureDate);
    data.setValue("InsurancedPerson", insured);
    data.setValue("NewCarPurchasePrice", newCarPay);
    data.setValue("InsuranceEndDate", overDate);
    data.setValue("InsurancePaymentDate", payDate);
    data.setValue("IdCard", personalNumber);
    data.setValue("SeatingNumber", seating);
    data.setValue("PaymentState", status);
    data.setValue("InsurancePaymentDate", throughDate);
    data.setValue("TotalReceivable", allShould);
    data.setValue("MotorcycleType", carKind);
    data.setValue("PlateNumber", carNumber);
    data.setValue("CarOwner", carPerson);
    data.setValue("VehicleAndVesselTaxGuarantee", carShip);
    data.setValue("TaxInsuranceForCarAndBoat", carShipPre);
    data.setValue("CommercialPreferenceRatio", commialDownRatio);
    data.setValue("ExcludingDeductibleCoverage", deduct);
    data.setValue("ExcludingDeductiblePremiums", deductPre);
    data.setValue("EngineNumber", engineNumber);
    data.setValue("StrongPreferenceRatio", forceDownRatio);
    data.setValue("InsuranceCoverage", forcePay);
    data.setValue("PremiumInsurancePremium", forcePayEdit);
    data.setValue("ChiuQiangShouldBeCharged", forceShould);
    data.setValue("CoverageForSeparateBreakageOfGlass", grass);
    data.setValue("PremiumForSeparateBreakageOfGlass", grassPre);
    data.setValue("PolicyHolder", mainInsure);
    data.setValue("CommissionCost", morePay);
    data.setValue("CommissionRatio", moreRatio);
    data.setValue("SpontaneousCombustionLossInsurance", nature);
    data.setValue("SpontaneousCombustionLossInsurancePremium", naturePre);
    data.setValue("OtherInsuredAmount", other);
    data.setValue("OtherPremium", otherPre);
    data.setValue("Description", otherText);
    data.setValue("SeatInsuranceCoverageForOnboardPersonnel", Passenger);
    data.setValue("PassengerSeatInsurancePremium", PassengerPre);
    data.setValue("PaymentMethod", payWay);
    data.setValue("ScarInsuranceAmount", scar);
    data.setValue("ScarInsurancePremium", scarPre);
    data.setValue("TotalCommercialPremium", sumCommcialPre);
    data.setValue("TotalPremium", sumForcePre);
    data.setValue("GrossPremium", SumPre);
    data.setValue("Telephone", tel);
    data.setValue("TheWholeCarTheftEmergencyInsuranceAmount", theft);
    data.setValue("CarTheftInsurancePremium", theftPre);
    data.setValue("ThirdPartyLiabilityCoverage", third);
    data.setValue("ThirdPartyLiabilityInsurancePremium", thirdPre);
    data.setValue("InsurancePaymentDate", ThroughDate);
    data.setValue("VehicleLossInsurance", vehicleLoss);
    data.setValue("InsurancePremiumPorLossOfVehicle", vehicleLossPre);
    data.setValue("WaterLossInsurancePremium", waterPre);
    data.setValue("WaterLossInsurance", water);

    InsertExecuter ins = InsertExecuter("insur_guaranteeslip");
    ins.doInsert(data);

    this->hide();

}
