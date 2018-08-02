#include "employeequerydialog.h"
#include "mainwindow.h"
#include "selectexecuter.h"
#include "ui_employeequerydialog.h"

#include <string>
using namespace std;


EmployeeQueryDialog::EmployeeQueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeQueryDialog)
{

	ui->setupUi(this);
	this->setStyleSheet("background-color:rgb(150,205,205)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 10, 75);
	ui->label->setFont(fontTitle);
	ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");
	ui->label->setAlignment(Qt::AlignHCenter);
	ui->label_2->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_3->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_4->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_5->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_6->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");


	ui->Admin_EmplyeeNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_PersonalNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmplyeeNameEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Admin_EmplyeeUnitEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");

	ui->Admin_Query->setFont(fontText);
	ui->Admin_Return->setFont(fontText);
	ui->Admin_Reset->setFont(fontText);


	ui->label_2->setFont(fontText);
	ui->label_3->setFont(fontText);
	ui->label_4->setFont(fontText);
	ui->label_5->setFont(fontText);
}

EmployeeQueryDialog::~EmployeeQueryDialog()
{
    delete ui;
}

/**
 * @brief EmployeeQueryDialog::on_Admin_Return_clicked 返回
 */
void EmployeeQueryDialog::on_Admin_Return_clicked()
{
    this->hide();
}

/**
 * @brief EmployeeQueryDialog::on_Admin_Reset_clicked 重置
 */
void EmployeeQueryDialog::on_Admin_Reset_clicked()
{
    ui->Admin_EmplyeeNameEdit->clear();
    ui->Admin_EmplyeeNumberEdit->clear();
    ui->Admin_EmplyeeUnitEdit->clear();
    ui->Admin_PersonalNumberEdit->clear();
}



/**
 * @brief EmployeeQueryDialog::on_Admin_Query_clicked 查询
 */
void EmployeeQueryDialog::on_Admin_Query_clicked()
{
    string name = ui->Admin_EmplyeeNameEdit->text().toStdString();
    string number = ui->Admin_EmplyeeNumberEdit->text().toStdString();
    string unit = ui->Admin_EmplyeeUnitEdit->text().toStdString();
    string pn = ui->Admin_PersonalNumberEdit->text().toStdString();

    SelectExecuter sel = SelectExecuter("sys_employeeinfo");


    if (name != "")
    {
        sel.filter.addFilter("EmployeeName", name);

    }
    if (number != "")
    {
        sel.filter.addFilter("EmployeeCode", number);
    }
    if (unit != "")
    {
        sel.filter.addFilter("Department", unit);
    }
    if (pn != "") {
        sel.filter.addFilter("IdCard", pn);
    }

    vector<QuerySet> result = sel.doSelect();

    MainWindow::currentTable = "sys_employeeinfo";
    ((MainWindow*) (this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);

    this->hide();

}
