#ifndef CLAIMSEARCHDIALOG_H
#define CLAIMSEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class ClaimSearchDialog;
}

class ClaimSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClaimSearchDialog(QWidget *parent = nullptr);
    ~ClaimSearchDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ClaimSearchDialog *ui;
};

#endif // CLAIMSEARCHDIALOG_H
