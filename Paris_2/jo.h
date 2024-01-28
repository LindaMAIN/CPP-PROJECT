#ifndef JO_H
#define JO_H

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
class JO;
}

class JO : public QMainWindow
{
    Q_OBJECT
private slots:
    //void handleArrondissementButton();
    void on_arrondissementButton_clicked();
    //void on_JOButton_clicked();
   // void on_AboutUSButton_clicked();
    //void on_zonesButton_clicked();
    void on_simButton_clicked();


public:
    explicit JO(QWidget *parent = nullptr);
    ~JO();

private:
    Ui::JO *ui;
    QGraphicsSvgItem *svgItem;
    QGraphicsItem *item;
    QGraphicsPixmapItem pixmapItem ;
    MyGraphicsScene *scene;

};

#endif // JO_H


