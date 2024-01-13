#ifndef ZONES_H
#define ZONES_H

#include <QDialog>

namespace Ui {
class zones;
}

class zones : public QDialog
{
    Q_OBJECT

public:
    explicit zones(QWidget *parent = nullptr);
    void show();
    ~zones();

private:
    Ui::zones *ui;
};

#endif // ZONES_H
