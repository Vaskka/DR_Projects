#include "insertexecuter.h"
#include "logindialog.h"
#include "mymainwindow.h"
#include "queryset.h"
#include "selectexecuter.h"
#include "ui_logindialog.h"
#include <string>
#include <sstream>
#include <qmessagebox.h>

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
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_Login_LoginButton_clicked()
{
    QString number = this->ui->Login_UserNumberEdit->text();
    QString password = this->ui->Login_UserPasswordEdit->text();


    SelectExecuter sel = SelectExecuter("sys_employeeinfo");

    sel.filter.addFilter("EmployeeCode", number.toStdString());
    sel.filter.addFilter("Password", password.toStdString());


    vector<QuerySet> result = sel.doSelect();

    if (result.size() >= 1) {
        string name = result[0]["EmployeeName"];
        int access = 0;
        if (number == "root")
        {
            access = 1;
        }


        User *user = new User(name, number.toStdString(), access);
        MyMainWindow *main = new MyMainWindow(user, this);
        main->show();

        this->hide();
    }
    else {
        QMessageBox::information(nullptr, "登陆失败", "用户名或密码错误", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }



}

void LoginDialog::on_Login_Quit_clicked()
{
    qApp->quit();
}
