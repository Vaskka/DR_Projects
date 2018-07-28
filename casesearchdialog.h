#ifndef CASESEARCHDIALOG_H
#define CASESEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class CaseSearchDialog;
}

class CaseSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CaseSearchDialog(QWidget *parent = nullptr);
    ~CaseSearchDialog();

private:
    Ui::CaseSearchDialog *ui;
};

#endif // CASESEARCHDIALOG_H
