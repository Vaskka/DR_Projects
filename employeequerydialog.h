#ifndef EMPLOYEEQUERYDIALOG_H
#define EMPLOYEEQUERYDIALOG_H

#include <QDialog>

namespace Ui {
class EmployeeQueryDialog;
}

class EmployeeQueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeQueryDialog(QWidget *parent = nullptr);
    ~EmployeeQueryDialog();

private slots:
    void on_Admin_Return_clicked();

    void on_Admin_Reset_clicked();

    void on_Admin_Query_clicked();

private:
    Ui::EmployeeQueryDialog *ui;
};

#endif // EMPLOYEEQUERYDIALOG_H
