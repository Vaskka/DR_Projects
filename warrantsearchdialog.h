#ifndef WARRANTSEARCHDIALOG_H
#define WARRANTSEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class WarrantSearchDialog;
}

/**
* @projectName   AutomobileInsurance
* @brief         保单查询接口
* @author        Vaskka
* @date          2018-7-28
*/
class WarrantSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarrantSearchDialog(QWidget *parent = nullptr);
    ~WarrantSearchDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::WarrantSearchDialog *ui;
};

#endif // WARRANTSEARCHDIALOG_H
