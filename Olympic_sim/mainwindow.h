#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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
    void showFirstPage();
    void showMainPage();
    void showAnalysePage();
    void showOverviewPage();

private:
    Ui::MainWindow *ui;
    QStackedWidget *mainStackedWidget;



};
#endif // MAINWINDOW_H
