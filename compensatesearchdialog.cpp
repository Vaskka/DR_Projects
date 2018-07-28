#include "compensatesearchdialog.h"
#include "ui_compensatesearchdialog.h"

CompensateSearchDialog::CompensateSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompensateSearchDialog)
{
    ui->setupUi(this);
}

CompensateSearchDialog::~CompensateSearchDialog()
{
    delete ui;
}
