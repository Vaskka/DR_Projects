#ifndef COMPENSATESEARCHDIALOG_H
#define COMPENSATESEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class CompensateSearchDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         定损查询图形接口
* @author        Vaskka
* @date          2018-7-
*/
class CompensateSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompensateSearchDialog(QWidget *parent = nullptr);
    ~CompensateSearchDialog();

private slots:
    /**
     * @brief on_pushButton_2_clicked 触返回的槽
     */
    void on_pushButton_2_clicked();

    /**
     * @brief on_pushButton_clicked 触发提交的槽
     */
    void on_pushButton_clicked();

private:
    Ui::CompensateSearchDialog *ui;
};

#endif // COMPENSATESEARCHDIALOG_H
