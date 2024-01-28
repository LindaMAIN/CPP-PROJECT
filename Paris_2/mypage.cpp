// mypage.cpp
#include "mypage.h"
#include <QVBoxLayout>

MyPage::MyPage(QWidget *parent) : QWidget(parent) ,
    customWidget (new CustomWidget(this)){

}

CustomWidget* MyPage::getCustomWidget() const
{
    return customWidget;
}
