#include "mainwindow.h"
#include "ui_mainwindow.h"
//If problem of include correct path to build_etc which contains the header file
#include <QPixmap>
#include <QDir>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a QPixmap object and load the image
    QPixmap pix(QDir::currentPath()+"/image/image.png");

    // Create a QLabel, set the QPixmap to it, and add it to the layout
    label = new QLabel(this);
    label->setPixmap(pix.scaled(500, 370, Qt::KeepAspectRatio));
    ui->verticalLayout->addWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_submitButton_click(){
    if(!ui->restaurantLineEdit ->text().isEmpty()){
        QPixmap pix(QDir::currentPath()+"/image/restaurant.jpeg");
        label->setPixmap(pix.scaled(500, 370, Qt::KeepAspectRatio));
    }
}
