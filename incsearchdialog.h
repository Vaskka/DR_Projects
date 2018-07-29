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

private slots:
    /**
     * @brief on_pushButton_3_clicked 执行查询
     */
    void on_pushButton_3_clicked();

    /**
     * @brief on_pushButton_2_clicked 执行返回
     */
    void on_pushButton_2_clicked();

private:
    Ui::IncSearchDialog *ui;
};

#endif // INCSEARCHDIALOG_H
