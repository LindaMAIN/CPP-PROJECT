#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include <QDialog>

namespace Ui {
class RESTAURANTS;
}

class RESTAURANTS : public QDialog
{
    Q_OBJECT

public:
    explicit RESTAURANTS(QWidget *parent = nullptr);
    void show();
    ~RESTAURANTS();

private:
    Ui::RESTAURANTS *ui;
};

#endif // RESTAURANTS_H
