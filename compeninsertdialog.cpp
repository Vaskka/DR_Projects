#include "compeninsertdialog.h"
#include "insertexecuter.h"
#include "selectexecuter.h"
#include "ui_compeninsertdialog.h"

#include <QMessageBox>
#include <string>
using namespace std;

CompenInsertDialog::CompenInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompenInsertDialog)
{
    ui->setupUi(this);
}

CompenInsertDialog::~CompenInsertDialog()
{
    delete ui;
}

/**
 * @brief CompenInsertDialog::on_Insert_Reset_clicked 重置
 */
void CompenInsertDialog::on_Insert_Reset_clicked()
{
    ui->Insert_AllEdit->clear();
    ui->Insert_CarNumberEdit->clear();
    ui->Insert_CaseNumberEdit->clear();
    ui->Insert_DescriptionEdit->clear();
    ui->Insert_EngineEdit->clear();
    ui->Insert_NumberEdit->clear();
    ui->Insert_PayEdit->clear();
    ui->Insert_SingleEdit->clear();
    ui->Insert_WheelEdit->clear();
    ui->Insert_WindowEdit->clear();


}

/**
 * @brief CompenInsertDialog::on_Insert_Return_clicked 返回
 */
void CompenInsertDialog::on_Insert_Return_clicked()
{
    this->hide();
}

void CompenInsertDialog::on_Insert_Commit_clicked()
{
    string all =  ui->Insert_AllEdit->text().toStdString();
    string carNumber =  ui->Insert_CarNumberEdit->text().toStdString();
    string caseNumber =  ui->Insert_CaseNumberEdit->text().toStdString();
    string description =  ui->Insert_DescriptionEdit->toPlainText().toStdString();
    string engine =  ui->Insert_EngineEdit->text().toStdString();
    string number =  ui->Insert_NumberEdit->text().toStdString();
    string pay =  ui->Insert_PayEdit->text().toStdString();
    string single =  ui->Insert_SingleEdit->text().toStdString();
    string wheel =  ui->Insert_WheelEdit->text().toStdString();
    string window =  ui->Insert_WindowEdit->text().toStdString();

    // 检查出险
    SelectExecuter sel = SelectExecuter("case_reportcaseinfo");

    sel.filter.addFilter("PlateNumber", carNumber);
    vector<QuerySet> result = sel.doSelect();
    if (result.size() < 1) {
        QMessageBox::information(this, "Opps!", "请先填写当前车的出险信息", QMessageBox::Ok, QMessageBox::Yes);
        return ;
    }

    // 插入数据
    QuerySet data = QuerySet();

    data.setValue("PlateNumber", carNumber);
    data.setValue("CaseNumber", caseNumber);
    data.setValue("ClaimNumber", number);
    data.setValue("BodyOfCarValue", pay);
    data.setValue("TyreValue", wheel);
    data.setValue("CarWindowValue", window);
    data.setValue("CarEngineValue", engine);
    data.setValue("InsideValue", single);
    data.setValue("TotalValue", all);
    data.setValue("Description", description);


    InsertExecuter ins = InsertExecuter("compen_carcompensate");
    ins.doInsert(data);
    this->hide();

}
