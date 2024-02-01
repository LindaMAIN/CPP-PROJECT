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
#include "citymodel.h"

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
    void goToMainWindow();
    void on_AboutUSButton_clicked();
    //void on_zonesButton_clicked();
    //void on_simButton_clicked();

    //Simul interaction
    void startSimulation();
    void oneStepSimulation();
    void endSimulation();
    //Display function for table
    void displayPlacesAndStats();

    void onJsonFileSelected(const QString &filename);


private:
    Ui::simul *ui;
    QGraphicsSvgItem *svgItem;
    QGraphicsItem *item;
    QGraphicsPixmapItem pixmapItem ;
    MyGraphicsScene *scene;
    CityModel *cityModel;
    QString selectedJsonFilePath;

};

#endif // SIMUL_H


