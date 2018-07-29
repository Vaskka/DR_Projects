#include "incinsertdialog.h"
#include "insertexecuter.h"
#include "queryset.h"
#include "ui_incinsertdialog.h"

#include <string>

using namespace std;

IncInsertDialog::IncInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncInsertDialog)
{
    ui->setupUi(this);
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
    ins.doInsert(data);

    this->hide();
}
