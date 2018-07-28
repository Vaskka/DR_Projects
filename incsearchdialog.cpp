#include "incsearchdialog.h"
#include "ui_incsearchdialog.h"

IncSearchDialog::IncSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncSearchDialog)
{
    ui->setupUi(this);
}

IncSearchDialog::~IncSearchDialog()
{
    delete ui;
}
