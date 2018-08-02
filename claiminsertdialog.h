#ifndef CLAIMINSERTDIALOG_H
#define CLAIMINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class ClaimInsertDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         理赔登记图形接口
* @author        Vaskka
* @date          2018-7-27
*/
class ClaimInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClaimInsertDialog(QWidget *parent = nullptr);
    ~ClaimInsertDialog();

private slots:
    /**
     * @brief on_Insert_Reset_clicked 触发重置的槽
     */
    void on_Insert_Reset_clicked();

    /**
     * @brief on_Insert_Return_clicked 触发返回的槽
     */
    void on_Insert_Return_clicked();

    /**
     * @brief on_Insert_Commit_clicked 触发提交的槽
     */
    void on_Insert_Commit_clicked();

private:
    Ui::ClaimInsertDialog *ui;
};

#endif // CLAIMINSERTDIALOG_H
