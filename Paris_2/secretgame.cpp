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
    QPixmap backgroundImage((":/images/images/wau.png"));
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
    QString executablePath = QDir(QCoreApplication::applicationDirPath()).filePath("Mario_Qt-Cpp/MarioQt");
    if (!QFile::exists(executablePath)) {
        qDebug() << "Executable does not exist:" << executablePath;
        return;
    }

    qDebug() << "Launching program:" << executablePath;
    QStringList arguments;
    bool launched = QProcess::startDetached(executablePath, arguments);

    if (!launched) {
        qDebug() << "Failed to launch the executable.";
    }
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
