#include "warrantsearchdialog.h"
#include "ui_warrantsearchdialog.h"

WarrantSearchDialog::WarrantSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarrantSearchDialog)
{
    ui->setupUi(this);
}

WarrantSearchDialog::~WarrantSearchDialog()
{
    delete ui;
}
