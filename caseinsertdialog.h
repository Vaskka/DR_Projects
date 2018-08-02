#ifndef CASEINSERTDIALOG_H
#define CASEINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class CaseInsertDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         出险查询图形接口
* @author        Vaskka
* @date          2018-7-27
*/
class CaseInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CaseInsertDialog(QWidget *parent = nullptr);
    ~CaseInsertDialog();

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
    Ui::CaseInsertDialog *ui;
};

#endif // CASEINSERTDIALOG_H
