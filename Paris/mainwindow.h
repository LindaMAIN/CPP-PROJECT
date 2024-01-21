// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include "mygraphicscene.h"
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

private:
    Ui::MainWindow *ui;
    QGraphicsSvgItem *svgItem;
    MyGraphicsScene *scene;
/*    QGraphicsSvgItem *parisDepartement;
    Departement parisDepartementInfo;
    QString getTextAtPosition(const QPoint &position);
 */
};

#endif // MAINWINDOW_H
