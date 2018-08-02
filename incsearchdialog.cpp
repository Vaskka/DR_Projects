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
	this->setStyleSheet("background-color:rgb(150,205,205)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 10, 75);
	ui->label_61->setFont(fontTitle);
	ui->label_61->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");
	ui->label_61->setAlignment(Qt::AlignHCenter);
	ui->label_59->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_62->setStyleSheet("background-color:rgb(102,139,13arch);color:rgb(255,250,205)");
	ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");


	ui->Main_IncSearchNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Main_IncSearchNameEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");

	ui->pushButton_3->setFont(fontText);
	ui->pushButton_2->setFont(fontText);

	ui->label_59->setFont(fontText);
	ui->label_62->setFont(fontText);
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
