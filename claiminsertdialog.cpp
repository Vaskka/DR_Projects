#include "claiminsertdialog.h"
#include "insertexecuter.h"
#include "selectexecuter.h"
#include "ui_claiminsertdialog.h"

#include <QMessageBox>
#include <string>
using namespace std;

ClaimInsertDialog::ClaimInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClaimInsertDialog)
{
    ui->setupUi(this);
}

ClaimInsertDialog::~ClaimInsertDialog()
{
    delete ui;
}

/**
 * @brief ClaimInsertDialog::on_Insert_Reset_clicked 重置
 */
void ClaimInsertDialog::on_Insert_Reset_clicked()
{
    ui->Insert_CarNumberEdit->clear();
    ui->Insert_CaseNumberEdit->clear();
    ui->Insert_ClaimStatusEdit->clear();
    ui->Insert_CostEdit->clear();
    ui->Insert_DamangeEdit->clear();
    ui->Insert_Date->clear();
    ui->Insert_DescriptionEdit->clear();
    ui->Insert_IncNumberEdit->clear();
    ui->Insert_LoseEdit->clear();
    ui->Insert_NumberEdit->clear();
    ui->Insert_PersonEdit->clear();
    ui->Insert_TelEdit->clear();
    ui->Insert_ThirdIncIEdit->clear();

}

/**
 * @brief ClaimInsertDialog::on_Insert_Return_clicked 返回
 */
void ClaimInsertDialog::on_Insert_Return_clicked()
{
    this->hide();
}

void ClaimInsertDialog::on_Insert_Commit_clicked()
{
    string carNumber = ui->Insert_CarNumberEdit->text().toStdString();
    string caseNumber = ui->Insert_CaseNumberEdit->text().toStdString();
    string claimStatus = ui->Insert_ClaimStatusEdit->text().toStdString();
    string cost = ui->Insert_CostEdit->text().toStdString();
    string damage = ui->Insert_DamangeEdit->toPlainText().toStdString();
    string date = ui->Insert_Date->text().toStdString();
    string description =  ui->Insert_DescriptionEdit->toPlainText().toStdString();
    string incNumber =  ui->Insert_IncNumberEdit->text().toStdString();
    string lose = ui->Insert_LoseEdit->text().toStdString();
    string number =  ui->Insert_NumberEdit->text().toStdString();
    string person = ui->Insert_PersonEdit->text().toStdString();
    string tel = ui->Insert_TelEdit->text().toStdString();
    string third = ui->Insert_ThirdIncIEdit->text().toStdString();
    string status = ui->Insert_StatusEdit->text().toStdString();
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





    // 检查出险
    SelectExecuter sel = SelectExecuter("case_reportcaseinfo");

    sel.filter.addFilter("PlateNumber", carNumber);
    vector<QuerySet> result = sel.doSelect();
    if (result.size() < 1) {
        QMessageBox::information(this, "Opps!", "请先填写当前车的出险信息", QMessageBox::Ok, QMessageBox::Yes);
        return ;
    }

    // 检查定损
    SelectExecuter anotherSel = SelectExecuter("compen_carcompensate");

    anotherSel.filter.addFilter("PlateNumber", carNumber);
    vector<QuerySet> anotherResult = sel.doSelect();
    if (anotherResult.size() < 1) {
        QMessageBox::information(this, "Opps!", "请先填写当前车的定损信息", QMessageBox::Ok, QMessageBox::Yes);
        return ;
    }

    // 插入数据
    QuerySet data = QuerySet();

    data.setValue("ClaimNumber", number);
    data.setValue("PlateNumber", carNumber);
    data.setValue("CaseNumber", caseNumber);
    data.setValue("DateOfAcceptance", date);
    data.setValue("DamageExpectancy", damage);
    data.setValue("ActualClaimAmount", cost);
    data.setValue("TypeOfInsurance", claimStatus);
    data.setValue("ComputerCode", incNumber);
    data.setValue("ClaimState", status);
    data.setValue("Telephone", tel);
    data.setValue("Insurant", person);

    data.setValue("ThreeOwnerOfResponsibilitycompany", third);
    data.setValue("ClaimDescription", damage);
    data.setValue("CompensateDescription", description);

    InsertExecuter ins = InsertExecuter("claim_claimmanagmentinfo");
    QueryResult resu = ins.doInsert(data);
    if (resu.isQueryRight)
    {
        this->hide();
    }
    else
    {
        QMessageBox::information(this, "Opps", resu.msg.c_str(), QMessageBox::Ok, QMessageBox::Ok);
    }
}
