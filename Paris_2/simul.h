#ifndef SIMUL_H
#define SIMUL_H

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
class simul;
}

class simul : public QMainWindow
{
    Q_OBJECT

public:
    explicit simul(QWidget *parent = nullptr);
    ~simul();
private slots:
    //void handleArrondissementButton();
    void on_arrondissementButton_clicked();
    void on_JOButton_clicked();
    //void on_AboutUSButton_clicked();
    //void on_zonesButton_clicked();
    //void on_simButton_clicked();


private:
    Ui::simul *ui;
    QGraphicsSvgItem *svgItem;
    QGraphicsItem *item;
    QGraphicsPixmapItem pixmapItem ;
    MyGraphicsScene *scene;

};

#endif // SIMUL_H


