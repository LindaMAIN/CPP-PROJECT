#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTranslator>
#include <QLocale>
#include <QCoreApplication>

namespace Ui {
class AboutUS;
}

class AboutUS : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutUS(QWidget *parent = nullptr);
    ~AboutUS();
    void goToMainWindow();
private slots:
    void on_JOButton_clicked();
    void on_arrondissementButton_clicked();
    void on_simButton_clicked();

    void on_gameButton_clicked();

private:
    Ui::AboutUS *ui;


};

#endif // ABOUTUS_H
