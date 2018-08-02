#ifndef COMPENINSERTDIALOG_H
#define COMPENINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class CompenInsertDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         定损登记图形接口
* @author        Vaskka
* @date          2018-7-
*/
class CompenInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompenInsertDialog(QWidget *parent = nullptr);
    ~CompenInsertDialog();

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
    Ui::CompenInsertDialog *ui;
};

#endif // COMPENINSERTDIALOG_H
