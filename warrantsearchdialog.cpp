#include "warrantsearchdialog.h"
#include "ui_warrantsearchdialog.h"
#include "selectexecuter.h"
#include "mainwindow.h"
#include <string>
using namespace std;


WarrantSearchDialog::WarrantSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarrantSearchDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:rgb(150,205,205)");
    QFont fontTitle("Microsoft YaHei", 20, 75);
    QFont fontText("Microsoft YaHei", 10, 75);
    ui->label_61->setFont(fontTitle);
    ui->label_61->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");
    ui->label_61->setAlignment(Qt::AlignHCenter);
    ui->label_59->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->label_57->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->label_58->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->label_60->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205);border:3px groove grey");


    ui->Main_NumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
    ui->Main_CarNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
    ui->Main_DateEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
    ui->Main_Dateable->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->Main_NameEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");

    ui->pushButton->setFont(fontText);
    ui->pushButton_2->setFont(fontText);

    ui->Main_Dateable->setFont(QFont("Microsoft YaHei", 8, 75));
    ui->label_57->setFont(fontText);
    ui->label_58->setFont(fontText);
    ui->label_59->setFont(fontText);
    ui->label_60->setFont(fontText);
}

WarrantSearchDialog::~WarrantSearchDialog()
{
    delete ui;
}

/**
 * @brief WarrantSearchDialog::on_pushButton_2_clicked 返回
 */
void WarrantSearchDialog::on_pushButton_2_clicked()
{
    this->hide();
}

/**
 * @brief WarrantSearchDialog::on_pushButton_clicked 执行查询
 */
void WarrantSearchDialog::on_pushButton_clicked()
{
    string carNumber = this->ui->Main_CarNumberEdit->text().toStdString();
    string date = this->ui->Main_DateEdit->date().toString().toStdString();
    string name = this->ui->Main_NameEdit->text().toStdString();
    string number = this->ui->Main_NumberEdit->text().toStdString();

    SelectExecuter sel = SelectExecuter("insur_guaranteeslip");

    if (ui->Main_Dateable->isChecked()) {
        sel.filter.addFilter("DateOfAcceptance", date);
    }
    if (carNumber != "") {
        sel.filter.addFilter("PlateNumber", carNumber);
    }
    if (name != "") {
        sel.filter.addFilter("Agent", carNumber);
    }
    if (number != "") {
        sel.filter.addFilter("WarrantNumber", number);
    }

    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();
    MainWindow::currentTable = "insur_guaranteeslip";
    ((MainWindow*)(this->parentWidget()))->drawInfoOnTableWidgetWithOperator(result);


    this->hide();
}
