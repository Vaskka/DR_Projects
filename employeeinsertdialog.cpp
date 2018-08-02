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

	this->setStyleSheet("background-color:rgb(150,205,205)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 8, 75);


	ui->Admin_DecriptionText->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeAdressEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeBirthdayDate->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeComeDate->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeEducationEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeNameEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeOkEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeePersonalNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeRecommandEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeSexEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeSourceEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeStatusEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeSourceWorkEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeTelEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmployeeUnitEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");




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
	ui->label_11->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_12->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");
	ui->label_14->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_15->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_16->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");
	ui->label_17->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");


	ui->Admin_Commit->setFont(fontText);
	ui->Admin_Reset->setFont(fontText);
	ui->Admin_Return->setFont(fontText);
	ui->label_10->setStyleSheet("background-color:rgb(102,139,139);border:2px groove grey");
	ui->label_18->setStyleSheet("background-color:rgb(102,139,139);border:2px groove grey");





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
	ui->label_12->setFont(fontText);
	ui->label_13->setFont(fontText);
	ui->label_14->setFont(fontText);
	ui->label_15->setFont(fontText);
	ui->label_16->setFont(fontText);
	ui->label_17->setFont(fontText);

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
