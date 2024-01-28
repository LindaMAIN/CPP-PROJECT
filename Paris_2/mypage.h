// mypage.h
#ifndef MYPAGE_H
#define MYPAGE_H

#include <QWidget>
#include "customwidget.h"

class MyPage : public QWidget {
    Q_OBJECT

public:
    MyPage(QWidget *parent = nullptr);
    CustomWidget* getCustomWidget() const;

private:
    CustomWidget *customWidget;
    // Add other widgets specific to this page
};

#endif // MYPAGE_H
