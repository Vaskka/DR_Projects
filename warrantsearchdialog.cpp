#include "warrantsearchdialog.h"
#include "ui_warrantsearchdialog.h"
#include "selectexecuter.h"
#include "mainwindow.h"
#include <string>
using namespace std;


WarrantSearchDialog::WarrantSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarrantSearchDialog)
{
    ui->setupUi(this);
}

WarrantSearchDialog::~WarrantSearchDialog()
{
    delete ui;
}

/**
 * @brief WarrantSearchDialog::on_pushButton_2_clicked 返回
 */
void WarrantSearchDialog::on_pushButton_2_clicked()
{
    this->hide();
}

/**
 * @brief WarrantSearchDialog::on_pushButton_clicked 执行查询
 */
void WarrantSearchDialog::on_pushButton_clicked()
{
    string carNumber = this->ui->Main_CarNumberEdit->text().toStdString();
    string date = this->ui->Main_DateEdit->date().toString().toStdString();
    string name = this->ui->Main_NameEdit->text().toStdString();
    string number = this->ui->Main_NumberEdit->text().toStdString();

    SelectExecuter sel = SelectExecuter("insur_guaranteeslip");

    if (ui->Main_Dateable->isChecked()) {
        sel.filter.addFilter("DateOfAcceptance", date);
    }
    if (carNumber != "") {
        sel.filter.addFilter("PlateNumber", carNumber);
    }
    if (name != "") {
        sel.filter.addFilter("Agent", carNumber);
    }
    if (number != "") {
        sel.filter.addFilter("WarrantNumber", number);
    }

    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();

    ((MainWindow*)(this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);
    MainWindow::currentTable = "insur_guaranteeslip";

    this->hide();
}
