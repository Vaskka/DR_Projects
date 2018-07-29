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

    ((MainWindow*) (this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);
    MainWindow::currentTable = "sys_employeeinfo";
    this->hide();

}
