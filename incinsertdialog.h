#ifndef INCINSERTDIALOG_H
#define INCINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class IncInsertDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         承包公司录入图形接口
* @author        Vaskka
* @date          2018-7-28
*/
class IncInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IncInsertDialog(QWidget *parent = nullptr);
    ~IncInsertDialog();

private slots:
    /**
     * @brief on_Insert_Return_clicked 返回槽
     */
    void on_Insert_Return_clicked();

    /**
     * @brief on_Insert_Reset_clicked 重置槽
     */
    void on_Insert_Reset_clicked();

    /**
     * @brief on_Insert_Commit_clicked 提交槽
     */
    void on_Insert_Commit_clicked();

private:
    Ui::IncInsertDialog *ui;
};

#endif // INCINSERTDIALOG_H
