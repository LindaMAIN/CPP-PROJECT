#include "zone.h"
#include "ui_zone.h"

zone::zone(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zone)
{
    ui->setupUi(this);
}

zone::~zone()
{
    delete ui;
}
