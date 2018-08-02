#ifndef WARRANTINSERTDIALOG_H
#define WARRANTINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class WarrantInsertDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         保单登记接口
* @author        Vaskka
* @date          2018-7-28
*/
class WarrantInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarrantInsertDialog(QWidget *parent = nullptr);
    ~WarrantInsertDialog();

private slots:
    void on_Main_CommitButton_3_clicked();

    void on_Main_CommitButton_2_clicked();

    void on_Main_CommitButton_clicked();

private:
    Ui::WarrantInsertDialog *ui;
};

#endif // WARRANTINSERTDIALOG_H
