#ifndef INCSEARCHDIALOG_H
#define INCSEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class IncSearchDialog;
}

class IncSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IncSearchDialog(QWidget *parent = nullptr);
    ~IncSearchDialog();

private:
    Ui::IncSearchDialog *ui;
};

#endif // INCSEARCHDIALOG_H