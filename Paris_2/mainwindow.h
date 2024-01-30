
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTranslator>
#include <QLocale>
#include <QLineEdit>
#include <QCoreApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include "mygraphicscene.h"
#include "arrondissement.h"
#include "jo.h"
#include "aboutus.h"
#include "simul.h"
#include "zone.h"

//#include "departement.h"
//#include "departementinfodialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    //void playVideo();

public slots:
    void goToHome();
    void arrondissementButton();
    void zonesButton();
    void AboutUSButton();
    void JOButton();



private:
    Ui::MainWindow *ui;
    QGraphicsSvgItem *svgItem;
    QGraphicsItem *item;
    QGraphicsPixmapItem pixmapItem ;
    MyGraphicsScene *scene;
    arrondissement *arrondissements;
    JO *jo;
    AboutUS *ABoutUs;
    simul *simulation;
    zone *zones;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QLineEdit *lineEdit;




private slots:
    void handleArrondissementButton();
    void on_arrondissementButton_clicked();
    void on_JOButton_clicked();
    void on_AboutUSButton_clicked();
    void on_zonesButton_clicked();
    void on_simButton_clicked();
    void onLanguageChanged(int index);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void playVideo();

    void on_playVideoButton_clicked();
};

#endif // MAINWINDOW_H
