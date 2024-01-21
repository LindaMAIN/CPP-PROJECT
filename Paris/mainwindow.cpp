#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
 //   parisDepartementInfo("Paris", "Description")
{
    ui->setupUi(this);

    // Créer une scène personnalisée + item svg
   scene = new MyGraphicsScene;
   svgItem = new QGraphicsSvgItem("/home/lilyn/Desktop/Paris/map.svg");
    //svgItem = new QGraphicsSvgItem("paris.svg");
    svgItem->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    scene->addItem(svgItem);

    // Associer à la vue ui graphicsView
    ui->graphicsView->setScene(scene);


}

MainWindow::~MainWindow()
{
    delete ui;
}
