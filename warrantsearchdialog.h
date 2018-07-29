#ifndef WARRANTSEARCHDIALOG_H
#define WARRANTSEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class WarrantSearchDialog;
}

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
