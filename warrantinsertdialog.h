#ifndef WARRANTINSERTDIALOG_H
#define WARRANTINSERTDIALOG_H

#include <QDialog>

namespace Ui {
class WarrantInsertDialog;
}

class WarrantInsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarrantInsertDialog(QWidget *parent = nullptr);
    ~WarrantInsertDialog();

private:
    Ui::WarrantInsertDialog *ui;
};

#endif // WARRANTINSERTDIALOG_H
