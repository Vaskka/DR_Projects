#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

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
