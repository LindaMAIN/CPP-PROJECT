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
     void goToMainWindow();
    void on_JOButton_clicked();
    void on_AboutUSButton_clicked();
    void on_simButton_clicked();
    void on_pushButton_8_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


private:
    Ui::arrondissement *ui;
    QGraphicsSvgItem *svgItem;
    QGraphicsItem *item;
    QGraphicsPixmapItem pixmapItem ;
    MyGraphicsScene *scene;

};

#endif // ARRONDISSEMENT_H


