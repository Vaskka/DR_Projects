#include "claimsearchdialog.h"
#include "ui_claimsearchdialog.h"

ClaimSearchDialog::ClaimSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClaimSearchDialog)
{
    ui->setupUi(this);
}

ClaimSearchDialog::~ClaimSearchDialog()
{
    delete ui;
}
