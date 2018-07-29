#ifndef INCINSERTDIALOG_H
#define INCINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class IncInsertDialog;
}

class IncInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IncInsertDialog(QWidget *parent = nullptr);
    ~IncInsertDialog();

private slots:
    void on_Insert_Return_clicked();

    void on_Insert_Reset_clicked();

    void on_Insert_Commit_clicked();

private:
    Ui::IncInsertDialog *ui;
};

#endif // INCINSERTDIALOG_H
