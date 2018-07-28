#include "casesearchdialog.h"
#include "ui_casesearchdialog.h"

CaseSearchDialog::CaseSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CaseSearchDialog)
{
    ui->setupUi(this);
}

CaseSearchDialog::~CaseSearchDialog()
{
    delete ui;
}
