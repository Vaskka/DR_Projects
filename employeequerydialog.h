#ifndef EMPLOYEEQUERYDIALOG_H
#define EMPLOYEEQUERYDIALOG_H

#include <QDialog>

namespace Ui {
class EmployeeQueryDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         员工查询图形接口
* @author        Vaskka
* @date          2018-7-28
*/
class EmployeeQueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeQueryDialog(QWidget *parent = nullptr);
    ~EmployeeQueryDialog();

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
     * @brief on_Admin_Query_clicked 触发查询的槽
     */
    void on_Admin_Query_clicked();

private:
    Ui::EmployeeQueryDialog *ui;
};

#endif // EMPLOYEEQUERYDIALOG_H
