#ifndef EMPLOYEEINSERTDIALOG_H
#define EMPLOYEEINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class EmployeeInsertDialog;
}

class EmployeeInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeInsertDialog(QWidget *parent = nullptr);
    ~EmployeeInsertDialog();

private slots:
    void on_Admin_Return_clicked();

    void on_Admin_Reset_clicked();

    void on_Admin_Commit_clicked();

private:
    Ui::EmployeeInsertDialog *ui;
};

#endif // EMPLOYEEINSERTDIALOG_H
