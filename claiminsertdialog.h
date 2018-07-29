#ifndef CLAIMINSERTDIALOG_H
#define CLAIMINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class ClaimInsertDialog;
}

class ClaimInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClaimInsertDialog(QWidget *parent = nullptr);
    ~ClaimInsertDialog();

private slots:
    void on_Insert_Reset_clicked();

    void on_Insert_Return_clicked();

    void on_Insert_Commit_clicked();

private:
    Ui::ClaimInsertDialog *ui;
};

#endif // CLAIMINSERTDIALOG_H
