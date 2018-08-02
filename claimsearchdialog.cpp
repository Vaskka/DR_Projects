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

	this->setStyleSheet("background-color:rgb(150,205,205)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 10, 75);
	ui->label_61->setFont(fontTitle);
	ui->label_61->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");
	ui->label_61->setAlignment(Qt::AlignHCenter);
	ui->label_59->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_62->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_63->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");

	ui->Main_Dateable->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");

	ui->Main_DateEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Main_NumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Main_CarNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");

	ui->pushButton->setFont(fontText);
	ui->pushButton_2->setFont(fontText);
	ui->Main_Dateable->setFont(fontText);
	ui->label_59->setFont(fontText);
	ui->label_62->setFont(fontText);
	ui->label_63->setFont(fontText);
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

    MainWindow::currentTable = "claim_claimmanagmentinfo";
    ((MainWindow*)(this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);

    this->hide();
}
