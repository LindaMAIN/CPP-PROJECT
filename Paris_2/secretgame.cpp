#include "secretgame.h"
#include "ui_secretgame.h"
#include <QMessageBox>
#include "mainwindow.h"

secretgame::secretgame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::secretgame)
{
    ui->setupUi(this);
    QString imagePath = "/home/lilyn/Downloads/secretgame.png";  // Remplacez cela par le chemin de votre image
    setStyleSheet("QMainWindow { background-image: url(" + imagePath + "); background-repeat: no-repeat; background-position: center;}");
}

secretgame::~secretgame()
{
    delete ui;
}

void secretgame::showSecretMessage(const QString &message)
{
    QMessageBox::information(this, "Message Secret", message);
}

void secretgame::on_okButton_clicked()
{
    static int messageIndex = 0;

    // Liste de messages secrets
    QStringList secretMessages;
    secretMessages << "Vous avez débloqué le niveau secret 1."
                   << "Félicitations pour avoir atteint le niveau secret 2."
                   << "Vous êtes un explorateur expert !";

    // Afficher le prochain message secret
    if (messageIndex < secretMessages.size()) {
        showSecretMessage(secretMessages.at(messageIndex));
        messageIndex++;
    } else {
        close();
    }
}
/*
void arrondissement::goToMainWindow()
{
    // Créez une instance de MainWindow et montrez-la
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Fermez la fenêtre actuelle (arrondissement)
    this->close();
}
*/
