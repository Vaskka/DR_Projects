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
	this->setStyleSheet("background-color:rgb(150,205,205)");
	QFont fontTitle("Microsoft YaHei", 20, 75);
	QFont fontText("Microsoft YaHei", 8, 75);

	ui->label_10->setFont(fontTitle);
	ui->label_10->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:2px groove grey");
	ui->label_10->setAlignment(Qt::AlignHCenter);

	ui->Insert_CaseNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_CarNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_AllEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_EngineEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_NumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_PayEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");


	ui->Insert_DescriptionEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_WindowEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_SingleEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
	ui->Insert_WheelEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");



	ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_2->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_3->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_4->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_5->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");

	ui->label_7->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_8->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_9->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border-radius:10px");
	ui->label_11->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
	ui->label_12->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");


	ui->Insert_Commit->setFont(fontText);
	ui->Insert_Reset->setFont(fontText);
	ui->Insert_Return->setFont(fontText);
	ui->label_6->setStyleSheet("background-color:rgb(102,139,139);border:3px groove grey");
	ui->label_13->setStyleSheet("background-color:rgb(102,139,139);border:3px groove grey");
	ui->label_14->setStyleSheet("background-color:rgb(102,139,139);border:3px groove grey");




	ui->label_2->setFont(fontText);
	ui->label_3->setFont(fontText);
	ui->label_4->setFont(fontText);
	ui->label_5->setFont(fontText);
	ui->label_6->setFont(fontText);
	ui->label_7->setFont(fontText);
	ui->label_8->setFont(fontText);
	ui->label_9->setFont(fontText);
	ui->label_11->setFont(fontText);
	ui->label_12->setFont(fontText);


	ui->label->setFont(fontText);
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

    // check
    if (!Constant::checkCarNumber(carNumber))
    {
        QMessageBox::information(this, "Opps", "请输入正确的车牌号", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }


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
    QueryResult resu = ins.doInsert(data);
    if (resu.isQueryRight)
    {
        this->hide();
    }
    else
    {
        QMessageBox::information(this, "Opps", resu.msg.c_str(), QMessageBox::Ok, QMessageBox::Ok);
    }

}
