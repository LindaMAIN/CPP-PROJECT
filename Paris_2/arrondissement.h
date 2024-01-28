#ifndef ARRONDISSEMENT_H
#define ARRONDISSEMENT_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTranslator>
#include <QLocale>
#include <QCoreApplication>
#include "mygraphicscene.h"


namespace Ui {
class arrondissement;
}

class arrondissement : public QMainWindow
{
    Q_OBJECT



public:
    explicit arrondissement(QWidget *parent = nullptr);
    ~arrondissement();

private slots:
    //void handleArrondissementButton();
    //void on_arrondissementButton_clicked();
    void on_JOButton_clicked();
   // void on_AboutUSButton_clicked();
    //void on_zonesButton_clicked();
    void on_simButton_clicked();
private:
    Ui::arrondissement *ui;
    QGraphicsSvgItem *svgItem;
    QGraphicsItem *item;
    QGraphicsPixmapItem pixmapItem ;
    MyGraphicsScene *scene;

};

#endif // ARRONDISSEMENT_H


