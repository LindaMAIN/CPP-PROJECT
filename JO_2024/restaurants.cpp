#include "restaurants.h"
#include "ui_restaurants.h"

RESTAURANTS::RESTAURANTS(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RESTAURANTS)
{
    ui->setupUi(this);
}

void RESTAURANTS::show(){
    QDialog::show();
}


RESTAURANTS::~RESTAURANTS()
{
    delete ui;
}
