#include "insertexecuter.h"
#include "logindialog.h"
#include "mainwindow.h"
#include "queryset.h"
#include "selectexecuter.h"
#include "ui_logindialog.h"
#include "user.h"
#include <string>
#include <sstream>
#include <qmessagebox.h>
#include <QDebug>

/**
 * @brief L for debug
 * @param content info
 */
void _L(std::string content)
{
    QMessageBox::information(nullptr, "Title", content.c_str(), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}


/**
 * @brief intToString int convert into string
 * @param n int
 * @return string
 */
string intToString(int n) {

    std::stringstream ss;
    std::string str;
    ss<<n;
    ss>>str;
    return str;

}

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:rgb(150,205,205)");
    QFont fontTitle("Microsoft YaHei", 20, 75);
    QFont fontText("Microsoft YaHei", 8, 75);

    ui->Login_UserNumberEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
    ui->Login_UserPasswordEdit->setStyleSheet("background-color:rgb(245,245,245);color:rgb(0,0,0);border:3px groove grey");
    ui->Login_UserNumber_Label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->Login_UserPasswordLabel->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->label->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");
    ui->Login_LoginButton->setFont(fontText);
    ui->Login_Quit->setFont(fontText);
    ui->Login_UserPasswordLabel->setFont(fontText);
    ui->Login_UserNumber_Label->setFont(fontText);
    ui->label_2->setFont(fontTitle);
    ui->label_2->setAlignment(Qt::AlignHCenter);
    ui->label_2->setStyleSheet("background-color:rgb(102,139,139);color:rgb(255,250,205)");

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_Login_LoginButton_clicked()
{
    QString number = this->ui->Login_UserNumberEdit->text();
    QString password = this->ui->Login_UserPasswordEdit->text();

    qDebug() << Constant::host.c_str();
    qDebug() << Constant::database.c_str();

    qDebug() << Constant::password.c_str();
    qDebug() << Constant::user.c_str();
    qDebug() << Constant::port;

    SelectExecuter sel = SelectExecuter("user_info");

    sel.filter.addFilter("user_name", number.toStdString());
    sel.filter.addFilter("password", password.toStdString());


    vector<QuerySet> result = sel.doSelect();

    if (result.size() >= 1) {
        string name = result[0]["user_name"];
        int access = 1;
        if (QString::fromStdString(result[0]["authority"]).toInt() == 0)
        {
            // root 权限
            access = 0;
        }


        User *user = new User(name, number.toStdString(), access);
        MainWindow *main = new MainWindow(this, user);
        main->show();

        this->hide();
    }
    else {
        QMessageBox::information(this, "登陆失败", "用户名或密码错误", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }



}

void LoginDialog::on_Login_Quit_clicked()
{
    qApp->quit();
}


