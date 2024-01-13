#include "zones.h"
#include "ui_zones.h"

zones::zones(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::zones)
{
    ui->setupUi(this);
}

void zones::show(){
    QDialog::show();
}

zones::~zones()
{
    delete ui;
}
