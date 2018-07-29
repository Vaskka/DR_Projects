#include "caseinsertdialog.h"
#include "insertexecuter.h"
#include "queryset.h"
#include "ui_caseinsertdialog.h"

#include <string>

using namespace std;

CaseInsertDialog::CaseInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CaseInsertDialog)
{
    ui->setupUi(this);
}

CaseInsertDialog::~CaseInsertDialog()
{
    delete ui;
}

/**
 * @brief CaseInsertDialog::on_Insert_Reset_clicked 重置
 */
void CaseInsertDialog::on_Insert_Reset_clicked()
{
    ui->Insert_CarNumberEdit->clear();
    ui->Insert_CauseEdit->clear();
    ui->Insert_Date->clear();
    ui->Insert_NumberEdit->clear();
    ui->Insert_OtherEdit->clear();
    ui->Insert_PlaceEdit->clear();
    ui->Insert_SummartEdit->clear();
    ui->Insert_TelEdit->clear();
    ui->Insert_UnitEdit->clear();
}

/**
 * @brief CaseInsertDialog::on_Insert_Return_clicked 返回
 */
void CaseInsertDialog::on_Insert_Return_clicked()
{
    this->hide();
}

void CaseInsertDialog::on_Insert_Commit_clicked()
{
    // 拿到输入数据
    string carNumber = ui->Insert_CarNumberEdit->text().toStdString();
    string cause = ui->Insert_CauseEdit->text().toStdString();
    string date = ui->Insert_Date->text().toStdString();
    string number = ui->Insert_NumberEdit->text().toStdString();
    string other = ui->Insert_OtherEdit->toPlainText().toStdString();
    string place = ui->Insert_PlaceEdit->text().toStdString();
    string summary = ui->Insert_SummartEdit->text().toStdString();
    string tel = ui->Insert_TelEdit->text().toStdString();
    string unit = ui->Insert_UnitEdit->text().toStdString();


    QuerySet data = QuerySet();

    data.setValue("CaseNumber", number);
    data.setValue("PlateNumber", carNumber);
    data.setValue("ReportingUnitOrIndividual", unit);
    data.setValue("ReportingTelephone", tel);
    data.setValue("TimeOfOccurrenceOfCase", date);
    data.setValue("PlaceOfOccurrenceOfACase", place);
    data.setValue("CauseOfCase", cause);
    data.setValue("SummaryOfLosses", summary);
    data.setValue("Description", other);

    InsertExecuter ins = InsertExecuter("case_reportcaseinfo");
    ins.doInsert(data);

    this->hide();
}
