#include "warrantinsertdialog.h"
#include "ui_warrantinsertdialog.h"
#include "queryset.h"
#include "insertexecuter.h"
#include "constant.h"
#include <QMessageBox>
#include <string>
using namespace std;


WarrantInsertDialog::WarrantInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarrantInsertDialog)
{
	ui->setupUi(this);

	this->setStyleSheet("background-color:rgb(245,245,245)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 8, 75);





	ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_2->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_3->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_4->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_5->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_6->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_7->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_8->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_9->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");
	ui->label_13->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_10->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_11->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_12->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");
	ui->label_14->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_15->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_16->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");
	ui->label_17->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");
	ui->label_18->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_19->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_20->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_21->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_22->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_23->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_24->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_25->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_26->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_27->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_28->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_29->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_30->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_31->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_32->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_33->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_34->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_35->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_36->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_37->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_38->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_39->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_40->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_41->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_42->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_43->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_44->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_45->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_46->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_47->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_48->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_49->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_50->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_51->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_52->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_53->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_54->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_55->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_56->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");

	ui->label_57->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");


	ui->Main_CommitButton->setFont(fontText);
	ui->Main_CommitButton_2->setFont(fontText);
	ui->Main_CommitButton_3->setFont(fontText);


	ui->label_2->setFont(fontText);
	ui->label_3->setFont(fontText);
	ui->label_4->setFont(fontText);
	ui->label_5->setFont(fontText);
	ui->label_6->setFont(fontText);
	ui->label_7->setFont(fontText);
	ui->label_8->setFont(fontText);
	ui->label_9->setFont(fontText);
	ui->label->setFont(fontText);
	ui->label_11->setFont(fontText);
	ui->label_10->setFont(fontText);
	ui->label_12->setFont(fontText);
	ui->label_13->setFont(fontText);
	ui->label_14->setFont(fontText);
	ui->label_15->setFont(fontText);
	ui->label_16->setFont(fontText);
	ui->label_17->setFont(fontText);
	ui->label_18->setFont(fontText);
	ui->label_19->setFont(fontText);
	ui->label_20->setFont(fontText);
	ui->label_21->setFont(fontText);
	ui->label_22->setFont(fontText);
	ui->label_23->setFont(fontText);
	ui->label_24->setFont(fontText);
	ui->label_25->setFont(fontText);
	ui->label_26->setFont(fontText);
	ui->label_27->setFont(fontText);
	ui->label_28->setFont(fontText);
	ui->label_29->setFont(fontText);
	ui->label_30->setFont(fontText);
	ui->label_31->setFont(fontText);
	ui->label_32->setFont(fontText);
	ui->label_33->setFont(fontText);
	ui->label_34->setFont(fontText);
	ui->label_35->setFont(fontText);
	ui->label_36->setFont(fontText);
	ui->label_37->setFont(fontText);
	ui->label_38->setFont(fontText);
	ui->label_39->setFont(fontText);
	ui->label_40->setFont(fontText);
	ui->label_41->setFont(fontText);
	ui->label_42->setFont(fontText);
	ui->label_43->setFont(fontText);
	ui->label_44->setFont(fontText);
	ui->label_45->setFont(fontText);
	ui->label_46->setFont(fontText);
	ui->label_47->setFont(fontText);
	ui->label_48->setFont(fontText);
	ui->label_49->setFont(fontText);
	ui->label_50->setFont(fontText);
	ui->label_51->setFont(fontText);
	ui->label_52->setFont(fontText);
	ui->label_53->setFont(fontText);
	ui->label_54->setFont(fontText);
	ui->label_55->setFont(fontText);
	ui->label_56->setFont(fontText);
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

    ui->Insert_CarKindEdit->clear();
    ui->Insert_CarNumberEdit->clear();
    ui->Insert_CarPersonEdit->clear();
    ui->Insert_CarShipEdit->clear();
    ui->Insert_CarShipPreEdit->clear();

    ui->Insert_DeductibleEdit->clear();
    ui->Insert_DeductiblePreInsert->clear();
    ui->Insert_EngineNumberEdit->clear();

    ui->Insert_ForcePayEdit->clear();
    ui->Insert_ForcePayPreEdit->clear();

    ui->Insert_GrassEdit->clear();
    ui->Insert_GrassPreEdit->clear();
    ui->Insert_IncEdit->clear();
    ui->Insert_InsureDate->clear();
    ui->Insert_InsuredEdit->clear();
    ui->Insert_MainInsureEdit->clear();

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
    ui->Insert_WarrantNumberEdit->clear();
}

void WarrantInsertDialog::on_Main_CommitButton_clicked()
{
    string warrantNumber = ui->Insert_WarrantNumberEdit->text().toStdString();
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

    string carKind =  ui->Insert_CarKindEdit->text().toStdString();
    string carNumber =   ui->Insert_CarNumberEdit->text().toStdString();
    string carPerson = ui->Insert_CarPersonEdit->text().toStdString();
    string carShip = ui->Insert_CarShipEdit->text().toStdString();
    string carShipPre =  ui->Insert_CarShipPreEdit->text().toStdString();

    string deduct =  ui->Insert_DeductibleEdit->text().toStdString();
    string deductPre =  ui->Insert_DeductiblePreInsert->text().toStdString();
    string engineNumber =  ui->Insert_EngineNumberEdit->text().toStdString();

    string forcePay =  ui->Insert_ForcePayEdit->text().toStdString();
    string forcePayEdit =  ui->Insert_ForcePayPreEdit->text().toStdString();

    string grass =  ui->Insert_GrassEdit->text().toStdString();
    string grassPre =  ui->Insert_GrassPreEdit->text().toStdString();
    string mainInsure =  ui->Insert_MainInsureEdit->text().toStdString();

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

    string theft = ui->Insert_TheftEdit->text().toStdString();
    string  theftPre = ui->Insert_TheftPreEdit->text().toStdString();
    string third =  ui->Insert_ThirdEdit->text().toStdString();
    string thirdPre =  ui->Insert_ThirdPreEdit->text().toStdString();
    string ThroughDate =  ui->Insert_ThroughDate->text().toStdString();
    string vehicleLoss =  ui->Insert_VehicleLossEdit->text().toStdString();
    string vehicleLossPre = ui->Insert_VehicleLossPreEdit->text().toStdString();
    string water =  ui->Insert_WaterEdit->text().toStdString();
    string waterPre =  ui->Insert_WaterPreEdit->text().toStdString();
    // check
    if (!Constant::checkCarNumber(carNumber))
    {
        QMessageBox::information(this, "Opps", "请输入正确的车牌号", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    if (!Constant::checkTelNumber(tel))
    {
        QMessageBox::information(this, "Opps", "请输入正确的电话号", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    if (!Constant::checkPersonalNumber(personalNumber))
    {
        QMessageBox::information(this, "Opps", "请输入正确的身份证号码", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    if (!Constant::checkNumber(carShip) ||
        !Constant::checkNumber(carShipPre) ||
        !Constant::checkNumber(deduct) ||
        !Constant::checkNumber(deductPre) ||
        !Constant::checkNumber(forcePay) ||
        !Constant::checkNumber(forcePayEdit) ||
        !Constant::checkNumber(grass) ||
        !Constant::checkNumber(grassPre) ||
        !Constant::checkNumber(nature) ||
        !Constant::checkNumber(naturePre) ||
        !Constant::checkNumber(other) ||
        !Constant::checkNumber(otherPre) ||
        !Constant::checkNumber(Passenger) ||
        !Constant::checkNumber(PassengerPre) ||
        !Constant::checkNumber(scar) ||
        !Constant::checkNumber(scarPre) ||
        !Constant::checkNumber(theft) ||
        !Constant::checkNumber(theftPre) ||
        !Constant::checkNumber(third) ||
        !Constant::checkNumber(thirdPre) ||
        !Constant::checkNumber(vehicleLoss) ||
        !Constant::checkNumber(vehicleLossPre) ||
        !Constant::checkNumber(water) ||
        !Constant::checkNumber(waterPre))
    {
        QMessageBox::information(this, "Opps", "请输入正确的保额或保费", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    if (!Constant::checkFloat(moreRatio))
    {
        QMessageBox::information(this, "Opps", "请输入正确格式的提成比率", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    // 总保费
    int SumPre = Constant::toInt(carShipPre) +
            Constant::toInt(deductPre) +
            Constant::toInt(forcePayEdit) +
            Constant::toInt(grassPre) +
            Constant::toInt(naturePre) +
            Constant::toInt(otherPre) +
            Constant::toInt(PassengerPre) +
            Constant::toInt(scarPre) +
            Constant::toInt(theftPre) +
            Constant::toInt(thirdPre) +
            Constant::toInt(vehicleLossPre) +
            Constant::toInt(waterPre);


    // 商业优惠比
    float commialDownRatio = (Constant::getCarForceDownRatio(carNumber.c_str()));
   // 交强优惠比
    float forceDownRatio = (Constant::getCarCommcialDownRatio(carNumber.c_str()));

    // 交强总保费
    string sumForcePre = forcePayEdit;

    // 交强应收
    int forceShould = Constant::toInt(forcePayEdit) * forceDownRatio;

    // 商业总保费
    int sumCommcialPre = Constant::toInt(commci) * commialDownRatio;


    // 总应收
    int allShould = (sumCommcialPre + forceShould);

    // 提成费用
    float realMoreRatio;
    realMoreRatio = atof(moreRatio.c_str());
    int morePay = allShould * realMoreRatio;


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
    data.setValue("CommercialPreferenceRatio", Constant::fromFloatToString(commialDownRatio));
    data.setValue("ExcludingDeductibleCoverage", deduct);
    data.setValue("ExcludingDeductiblePremiums", deductPre);
    data.setValue("EngineNumber", engineNumber);
    data.setValue("StrongPreferenceRatio", Constant::fromFloatToString(forceDownRatio));
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
    data.setValue("WarrantNumber", warrantNumber);

    InsertExecuter ins = InsertExecuter("insur_guaranteeslip");
    QueryResult result = ins.doInsert(data);
    if (result.isQueryRight)
    {
        this->hide();
    }
    else
    {
        QMessageBox::information(this, "Opps", result.msg.c_str(), QMessageBox::Ok, QMessageBox::Ok);
    }

}
