#include "secretgame.h"
#include "ui_secretgame.h"
#include <QMessageBox>
#include <QProcess>
#include "mainwindow.h"
#include <QDir>
#include <QDebug>
secretgame::secretgame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::secretgame)
{
    ui->setupUi(this);
    QPixmap backgroundImage(QDir::currentPath()+"/images/games.png");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);
    connect(ui->onHomeButton, &QPushButton::clicked, this, &secretgame::goToMainWindow);
    //connect(ui->onGameButton, &QPushButton::clicked, this, &secretgame::on_gameDialogButton_clicked);
    connect(ui->onGameButton, &QPushButton::clicked, this, &secretgame::onButtonClicked);

}

secretgame::~secretgame()
{
    delete ui;
}

void secretgame::onButtonClicked()
{
    QString program = QDir::currentPath()+"/Mario_Qt-Cpp/MarioQt";
    qDebug()<<program;
    QStringList arguments;
    QProcess::startDetached(program, arguments);
}

void secretgame::showSecretMessage(const QString &message)
{
    QMessageBox::information(this, "Message Secret", message);
}

void secretgame::goToMainWindow()
{
   hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();


}

void secretgame::on_gameDialogButton_clicked() {
    QMessageBox::information(this, tr("Jeu Secret"), tr("Bienvenue dans le jeu secret !"));
}
