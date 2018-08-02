#ifndef EMPLOYEEINSERTDIALOG_H
#define EMPLOYEEINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class EmployeeInsertDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         员工信息登记
* @author        Vaskka
* @date          2018-7-28
*/
class EmployeeInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeInsertDialog(QWidget *parent = nullptr);
    ~EmployeeInsertDialog();

private slots:
    /**
     * @brief on_Admin_Return_clicked 触发返回的槽
     */
    void on_Admin_Return_clicked();

    /**
     * @brief on_Admin_Reset_clicked 触发重置的槽
     */
    void on_Admin_Reset_clicked();

    /**
     * @brief on_Admin_Commit_clicked 触发提交的槽
     */
    void on_Admin_Commit_clicked();

private:
    Ui::EmployeeInsertDialog *ui;
};

#endif // EMPLOYEEINSERTDIALOG_H
