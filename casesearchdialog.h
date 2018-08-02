#ifndef CASESEARCHDIALOG_H
#define CASESEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class CaseSearchDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         出险查询图形接口
* @author        Vaskka
* @date          2018-7-
*/
class CaseSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CaseSearchDialog(QWidget *parent = nullptr);
    ~CaseSearchDialog();

private slots:

    /**
     * @brief on_pushButton_clicked 触发提交的槽
     */
    void on_pushButton_clicked();

    /**
     * @brief on_pushButton_2_clicked 触发返回的槽
     */
    void on_pushButton_2_clicked();

private:
    Ui::CaseSearchDialog *ui;
};

#endif // CASESEARCHDIALOG_H
