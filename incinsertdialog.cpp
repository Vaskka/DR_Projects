#include "incinsertdialog.h"
#include "insertexecuter.h"
#include "queryset.h"
#include "ui_incinsertdialog.h"

#include <QMessageBox>
#include <QMessageBox>
#include <string>

using namespace std;

IncInsertDialog::IncInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncInsertDialog)
{
	ui->setupUi(this);
	this->setStyleSheet("background-color:rgb(150,205,205)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 10, 75);
	ui->label_10->setFont(fontTitle);
	ui->label_10->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");
	ui->label_10->setAlignment(Qt::AlignHCenter);
	ui->label_11->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_2->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_3->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);");

	ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");


	ui->Insert_DescriptionEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_NumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_NameEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");



	ui->Insert_Commit->setFont(fontText);
	ui->Insert_Reset->setFont(fontText);
	ui->Insert_Return->setFont(fontText);

	ui->label_11->setFont(fontText);
	ui->label_2->setFont(fontText);
	ui->label_3->setFont(fontText);
}
IncInsertDialog::~IncInsertDialog()
{
    delete ui;
}

/**
 * @brief IncInsertDialog::on_Insert_Return_clicked 返回
 */
void IncInsertDialog::on_Insert_Return_clicked()
{
    this->hide();
}

/**
 * @brief IncInsertDialog::on_Insert_Reset_clicked 重置
 */
void IncInsertDialog::on_Insert_Reset_clicked()
{
    ui->Insert_DescriptionEdit->clear();
    ui->Insert_NameEdit->clear();
    ui->Insert_NumberEdit->clear();

}

void IncInsertDialog::on_Insert_Commit_clicked()
{
    string description = ui->Insert_DescriptionEdit->toPlainText().toStdString();
    string name = ui->Insert_NameEdit->text().toStdString();
    string number = ui->Insert_NumberEdit->text().toStdString();

    QuerySet data = QuerySet();

    data.setValue("CompanyCode", number);
    data.setValue("CompanyName", name);
    data.setValue("Description", description);

    InsertExecuter ins = InsertExecuter("sys_insurancecomputer");
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
