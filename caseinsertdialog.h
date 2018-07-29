#ifndef CASEINSERTDIALOG_H
#define CASEINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class CaseInsertDialog;
}

class CaseInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CaseInsertDialog(QWidget *parent = nullptr);
    ~CaseInsertDialog();

private slots:
    void on_Insert_Reset_clicked();

    void on_Insert_Return_clicked();

    void on_Insert_Commit_clicked();

private:
    Ui::CaseInsertDialog *ui;
};

#endif // CASEINSERTDIALOG_H
