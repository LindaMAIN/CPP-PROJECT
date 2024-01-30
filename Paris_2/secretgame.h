// secretgame.h
#ifndef SECRETGAME_H
#define SECRETGAME_H

#include <QMainWindow>

namespace Ui {
class secretgame;
}

class secretgame : public QMainWindow
{
    Q_OBJECT

public:
    explicit secretgame(QWidget *parent = nullptr);
    ~secretgame();
    void goToMainWindow();

    // Ajoutez ces déclarations
    void showSecretMessage(const QString &message);

private slots:
    void on_okButton_clicked();

private:
    Ui::secretgame *ui;
};

#endif // SECRETGAME_H
