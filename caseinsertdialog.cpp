#include "caseinsertdialog.h"
#include "insertexecuter.h"
#include "queryset.h"
#include "ui_caseinsertdialog.h"

#include <qmessagebox.h>
#include <string>

using namespace std;

CaseInsertDialog::CaseInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CaseInsertDialog)
{
    ui->setupUi(this);
	
	this->setStyleSheet("background-color:rgb(150,205,205)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 8, 75);
	ui->label_10->setFont(fontTitle);
	ui->label_10->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_10->setAlignment(Qt::AlignHCenter);

	ui->Insert_CauseEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_CarNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_OtherEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_PlaceEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_NumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_SummartEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_TelEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_Date->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_UnitEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");



	ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_2->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_3->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_4->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_5->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_6->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_7->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_8->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_9->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");

	ui->Insert_Commit->setFont(fontText);
	ui->Insert_Reset->setFont(fontText);
	ui->Insert_Return->setFont(fontText);
	ui->label_11->setStyleSheet("background-color:rgb(102,139,139);border:2px groove grey");
	ui->label_13->setStyleSheet("background-color:rgb(102,139,139);border:2px groove grey");
	ui->label_14->setStyleSheet("background-color:rgb(102,139,139);border:2px groove grey");


	ui->label_12->setStyleSheet("background-color:rgb(102,139,139)");

	ui->label_2->setFont(fontText);
	ui->label_3->setFont(fontText);
	ui->label_4->setFont(fontText);
	ui->label_5->setFont(fontText);
	ui->label_6->setFont(fontText);
	ui->label_7->setFont(fontText);
	ui->label_8->setFont(fontText);
	ui->label_9->setFont(fontText);
	ui->label->setFont(fontText);
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
    string cause = ui->Insert_CauseEdit->toPlainText().toStdString();
    string date = ui->Insert_Date->text().toStdString();
    string number = ui->Insert_NumberEdit->text().toStdString();
    string other = ui->Insert_OtherEdit->toPlainText().toStdString();
    string place = ui->Insert_PlaceEdit->text().toStdString();
    string summary = ui->Insert_SummartEdit->toPlainText().toStdString();
    string tel = ui->Insert_TelEdit->text().toStdString();
    string unit = ui->Insert_UnitEdit->text().toStdString();

    // check
    if (!Constant::checkCarNumber(carNumber))
    {
        QMessageBox::information(this, "Opps", "请输入正确的车牌号", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    if (!Constant::checkTelNumber(tel))
    {
        QMessageBox::information(this, "Opps", "请输入正确的电话号", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }


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
