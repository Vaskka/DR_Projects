#include "compensatesearchdialog.h"
#include "mainwindow.h"
#include "selectexecuter.h"
#include "ui_compensatesearchdialog.h"
#include <string>
using namespace std;

CompensateSearchDialog::CompensateSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompensateSearchDialog)
{
    ui->setupUi(this);
}

CompensateSearchDialog::~CompensateSearchDialog()
{
    delete ui;
}

/**
 * @brief CompensateSearchDialog::on_pushButton_2_clicked 返回
 */
void CompensateSearchDialog::on_pushButton_2_clicked()
{
    this->hide();
}

/**
 * @brief CompensateSearchDialog::on_pushButton_clicked 执行查询
 */
void CompensateSearchDialog::on_pushButton_clicked()
{
    string carNumber = this->ui->Main_CarNumberEdit->text().toStdString();
    string number = this->ui->Main_NumberEdit->text().toStdString();

    SelectExecuter sel = SelectExecuter("compen_carcompensate");

    if (number != "") {
        sel.filter.addFilter("ClaimNumber", number);
    }

    if (carNumber != "") {
        sel.filter.addFilter("PlateNumber", carNumber);
    }

    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();

    ((MainWindow*)(this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);
    MainWindow::currentTable = "compen_carcompensate";
    this->hide();
}
