#ifndef COMPENINSERTDIALOG_H
#define COMPENINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class CompenInsertDialog;
}

class CompenInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompenInsertDialog(QWidget *parent = nullptr);
    ~CompenInsertDialog();

private slots:
    void on_Insert_Reset_clicked();

    void on_Insert_Return_clicked();

    void on_Insert_Commit_clicked();

private:
    Ui::CompenInsertDialog *ui;
};

#endif // COMPENINSERTDIALOG_H
