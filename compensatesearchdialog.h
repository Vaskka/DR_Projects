#ifndef COMPENSATESEARCHDIALOG_H
#define COMPENSATESEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class CompensateSearchDialog;
}

class CompensateSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompensateSearchDialog(QWidget *parent = nullptr);
    ~CompensateSearchDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CompensateSearchDialog *ui;
};

#endif // COMPENSATESEARCHDIALOG_H
