#include "incsearchdialog.h"
#include "mainwindow.h"
#include "selectexecuter.h"
#include "ui_incsearchdialog.h"
#include <string>
#include <vector>

using namespace std;

IncSearchDialog::IncSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncSearchDialog)
{
    ui->setupUi(this);
}

IncSearchDialog::~IncSearchDialog()
{
    delete ui;
}

/**
 * @brief IncSearchDialog::on_pushButton_3_clicked 执行查询
 */
void IncSearchDialog::on_pushButton_3_clicked()
{


    string number = this->ui->Main_IncSearchNumberEdit->text().toStdString();
    string name = this->ui->Main_IncSearchNameEdit->text().toStdString();

    SelectExecuter sel = SelectExecuter("sys_insurancecomputer");


    if (number != "") {
        sel.filter.addFilter("CompanyCode", number);
    }
    if (name != "") {
        sel.filter.addFilter("CompanyName", name);
    }


    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();

    ((MainWindow*)(this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);
    MainWindow::currentTable = "sys_insurancecomputer";
    this->hide();

}

/**
 * @brief IncSearchDialog::on_pushButton_2_clicked 执行返回
 */
void IncSearchDialog::on_pushButton_2_clicked()
{
    this->hide();
}
