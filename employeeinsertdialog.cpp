#include "employeeinsertdialog.h"
#include "insertexecuter.h"
#include "queryset.h"
#include "ui_employeeinsertdialog.h"

#include <QMessageBox>
#include <string>
using namespace std;

EmployeeInsertDialog::EmployeeInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInsertDialog)
{
    ui->setupUi(this);
}

EmployeeInsertDialog::~EmployeeInsertDialog()
{
    delete ui;
}

/**
 * @brief EmployeeInsertDialog::on_Admin_Return_clicked 返回
 *
 */
void EmployeeInsertDialog::on_Admin_Return_clicked()
{
    this->hide();
}

/**
 * @brief EmployeeInsertDialog::on_Admin_Reset_clicked 重置
 */
void EmployeeInsertDialog::on_Admin_Reset_clicked()
{
    ui->Admin_EmployeeAdressEdit->clear();
    ui->Admin_EmployeeBirthdayDate->clear();
    ui->Admin_EmployeeComeDate->clear();
    ui->Admin_EmployeeEducationEdit->clear();
    ui->Admin_EmployeeNameEdit->clear();
    ui->Admin_EmployeeNumberEdit->clear();
    ui->Admin_EmployeeOkEdit->clear();
    ui->Admin_EmployeePersonalNumberEdit->clear();
    ui->Admin_EmployeeRecommandEdit->clear();
    ui->Admin_EmployeeSexEdit->clear();
    ui->Admin_EmployeeSourceEdit->clear();
    ui->Admin_EmployeeSourceWorkEdit->clear();
    ui->Admin_EmployeeStatusEdit->clear();
    ui->Admin_EmployeeTelEdit->clear();
    ui->Admin_EmployeeUnitEdit->clear();
    ui->Admin_DecriptionText->clear();

}


/**
 * @brief EmployeeInsertDialog::on_Admin_Commit_clicked 提交
 */
void EmployeeInsertDialog::on_Admin_Commit_clicked()
{
    string address  = ui->Admin_EmployeeAdressEdit->text().toStdString();
    string birth =  ui->Admin_EmployeeBirthdayDate->text().toStdString();
    string comeDate =  ui->Admin_EmployeeComeDate->text().toStdString();
    string edu =  ui->Admin_EmployeeEducationEdit->text().toStdString();
    string name =  ui->Admin_EmployeeNameEdit->text().toStdString();
    string number =  ui->Admin_EmployeeNumberEdit->text().toStdString();
    string ok =  ui->Admin_EmployeeOkEdit->text().toStdString();
    string pn =  ui->Admin_EmployeePersonalNumberEdit->text().toStdString();
    string recommand =  ui->Admin_EmployeeRecommandEdit->text().toStdString();
    string sex =  ui->Admin_EmployeeSexEdit->text().toStdString();
    string source = ui->Admin_EmployeeSourceEdit->text().toStdString();
    string sourceWork =  ui->Admin_EmployeeSourceWorkEdit->text().toStdString();
    string status =  ui->Admin_EmployeeStatusEdit->text().toStdString();
    string tel = ui->Admin_EmployeeTelEdit->text().toStdString();
    string unit =  ui->Admin_EmployeeUnitEdit->text().toStdString();
    string description =  ui->Admin_DecriptionText->toPlainText().toStdString();

    // check

    if (!Constant::checkTelNumber(tel))
    {
        QMessageBox::information(this, "Opps", "请输入正确的电话号", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    // 构造包含插入数据的QuerySet类，列名为key，数据为值
    QuerySet data = QuerySet();

    data.setValue("EmployeeCode", number);
    data.setValue("EmployeeName", name);
    data.setValue("State", status);
    data.setValue("Source", source);
    data.setValue("Department", unit);
    data.setValue("ReferencesName", recommand);
    data.setValue("Sex", sex);
    data.setValue("Academic", edu);
    data.setValue("IdCard", pn);
    data.setValue("OriginalOccupation", sourceWork);
    data.setValue("BirthDay", birth);
    data.setValue("Telephone", tel);
    data.setValue("EntryTime", comeDate);
    data.setValue("HomeAddress", address);
    data.setValue("IsValide", ok);
    data.setValue("Description", description);

    InsertExecuter ins = InsertExecuter("sys_employeeinfo");
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
