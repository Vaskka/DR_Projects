#include "warrantinsertdialog.h"
#include "ui_warrantinsertdialog.h"

WarrantInsertDialog::WarrantInsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarrantInsertDialog)
{
    ui->setupUi(this);
}

WarrantInsertDialog::~WarrantInsertDialog()
{
    delete ui;
}
