#ifndef ZONE_H
#define ZONE_H

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
class zone;
}

class zone : public QMainWindow
{
    Q_OBJECT

public:
    explicit zone(QWidget *parent = nullptr);
    ~zone();

private:
    Ui::zone *ui;

};

#endif // ZONE_H


