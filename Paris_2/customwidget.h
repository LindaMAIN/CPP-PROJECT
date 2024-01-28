// customwidget.h
#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

class QPushButton;

class CustomWidget : public QWidget {
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr);
    ~CustomWidget();

signals:
    void homeButtonClicked();
    void aboutUsButtonClicked();
    void joButtonClicked();
    void arrondissementButtonClicked();
    void simulationButtonClicked();

private:
    QPushButton *homeButton;
    QPushButton *aboutUsButton;
    QPushButton *joButton;
    QPushButton *arrondissementButton;
    QPushButton *simulationButton;
};

#endif // CUSTOMWIDGET_H
