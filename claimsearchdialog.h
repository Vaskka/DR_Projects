#ifndef CLAIMSEARCHDIALOG_H
#define CLAIMSEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class ClaimSearchDialog;
}


/**
* @projectName   AutomobileInsurance
* @brief         理赔查询图形接口
* @author        Vaskka
* @date          2018-7-
*/
class ClaimSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClaimSearchDialog(QWidget *parent = nullptr);
    ~ClaimSearchDialog();

private slots:
    /**
     * @brief on_pushButton_2_clicked 触发返回的槽
     */
    void on_pushButton_2_clicked();

    /**
     * @brief on_pushButton_clicked 触发查询的槽
     */
    void on_pushButton_clicked();

private:
    Ui::ClaimSearchDialog *ui;
};

#endif // CLAIMSEARCHDIALOG_H
