#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <ui_restaurants.h>
#include <ui_zones.h>
#include "zones.h"
#include "restaurants.h"
#include "ZoneDetailsDialog.h"
#include "villagejodetailsdialog.h"


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
    void addEmojiToArrondissement(QLabel* label, const QString& emojiPath);
    void connectArrondissementLabel(QLabel* label);
    QString getArrondissementInfo(QLabel* label);
protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
private slots:
    void onHomeButtonClicked();
    void onJOButtonClicked();
    void onUsButtonClicked();
    void onRestaurantsButtonClicked();
    void onzonesButtonClicked();
    void onArrondissementClicked();
    void onLieuxButtonClicked();
    void onSearchTextChanged(const QString &text);
    void onVillageJOButtonClick();

private:
    Ui::MainWindow *ui;
    zones* ptrzone;
    RESTAURANTS* ptrRestaurant;
    ZoneDetailsDialog* ptrZoneDetailsDialog;
    VillageJODetailsDialog* ptrVillageJODetailsDialog;
};
#endif // MAINWINDOW_H
