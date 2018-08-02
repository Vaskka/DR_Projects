#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         登陆界面图形接口
* @author        Vaskka
* @date          2018-7-28
*/
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_Login_LoginButton_clicked();

    void on_Login_Quit_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
