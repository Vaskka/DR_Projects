#include "claimsearchdialog.h"
#include "mainwindow.h"
#include "selectexecuter.h"
#include "ui_claimsearchdialog.h"

#include <string>
using namespace std;

ClaimSearchDialog::ClaimSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClaimSearchDialog)
{
    ui->setupUi(this);
}

ClaimSearchDialog::~ClaimSearchDialog()
{
    delete ui;
}

/**
 * @brief ClaimSearchDialog::on_pushButton_2_clicked 返回
 */
void ClaimSearchDialog::on_pushButton_2_clicked()
{
    this->hide();
}

/**
 * @brief ClaimSearchDialog::on_pushButton_clicked 查询
 */
void ClaimSearchDialog::on_pushButton_clicked()
{

    string carNumber = this->ui->Main_CarNumberEdit->text().toStdString();
    string date = this->ui->Main_DateEdit->date().toString().toStdString();
    string number = this->ui->Main_NumberEdit->text().toStdString();

    SelectExecuter sel = SelectExecuter("claim_claimmanagmentinfo");

    if (number != "") {
        sel.filter.addFilter("ClaimNumber", number);
    }
    if (ui->Main_Dateable->isChecked()) {
        sel.filter.addFilter("DateOfAcceptance", date);
    }
    if (carNumber != "") {
        sel.filter.addFilter("PlateNumber", carNumber);
    }

    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();
//    for (QuerySet q : result) {
//        q.L();
//    }


    ((MainWindow*)(this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);
    MainWindow::currentTable = "claim_claimmanagmentinfo";
    this->hide();
}
