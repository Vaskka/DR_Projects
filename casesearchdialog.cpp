#include "casesearchdialog.h"
#include "mainwindow.h"
#include "selectexecuter.h"
#include "ui_casesearchdialog.h"
#include <string>
using namespace std;

CaseSearchDialog::CaseSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CaseSearchDialog)
{
    ui->setupUi(this);
}

CaseSearchDialog::~CaseSearchDialog()
{
    delete ui;
}

void CaseSearchDialog::on_pushButton_clicked()
{

    string number = this->ui->Main_CarNumberEdit->text().toStdString();
    string date = this->ui->Main_CaseDateEdit->date().toString().toStdString();

    SelectExecuter sel = SelectExecuter("case_reportcaseinfo");

    if (number != "") {
        sel.filter.addFilter("PlateNumber", number);
    }
    if (ui->Main_Dateable->isChecked()) {
        sel.filter.addFilter("TimeOfOccurrenceOfCase", date);
    }


    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();


    ((MainWindow*)(this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);
    MainWindow::currentTable = "case_reportcaseinfo";
    this->hide();
}

/**
 * @brief CaseSearchDialog::on_pushButton_2_clicked 返回
 */
void CaseSearchDialog::on_pushButton_2_clicked()
{
    this->hide();
}
