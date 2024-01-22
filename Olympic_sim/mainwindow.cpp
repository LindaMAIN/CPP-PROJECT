#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui/QPixmap>
#include <QtWidgets/QLabel>
#include <QtWidgets/QAction>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDir>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainStackedWidget = ui->mainStackedWidget;

    // MAP display
    QPixmap pix(QDir::currentPath() + "/images/paris_map.png");

    if (pix.isNull()) {
        qDebug() << "Failed to load image file";
    } else {
        QLabel *mapLabel = new QLabel(this);

        // Set the aspect ratio policy to keep the image's aspect ratio
        mapLabel->setScaledContents(true);

        // Set the alignment to center the image
        mapLabel->setAlignment(Qt::AlignCenter);

        // Set the pixmap to the label
        mapLabel->setPixmap(pix);

        // Add the QLabel to your layout
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(mapLabel);
        ui->verticalLayout_map->addLayout(layout);


    }

    // Create an action with the menu
    QAction *accueilAction = ui->menuMenu->addAction("Accueil Page");
    QAction *settingsAction = ui->menuMenu->addAction("Simulation Settings Page");
    QAction *analyseAction = ui->menuMenu->addAction("Analyse Page");
    QAction *overviewAction = ui->menuMenu->addAction("Overview Page");

    connect(accueilAction, &QAction::triggered, this, &MainWindow::showFirstPage);
    connect(settingsAction, &QAction::triggered, this, &MainWindow::showMainPage);
    connect(analyseAction, &QAction::triggered, this, &MainWindow::showAnalysePage);
    connect(overviewAction, &QAction::triggered, this, &MainWindow::showOverviewPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Index set to alphabetical order
void MainWindow::showFirstPage()
{
    mainStackedWidget->setCurrentIndex(0);
}

void MainWindow::showOverviewPage()
{
    mainStackedWidget->setCurrentIndex(1);
}

void MainWindow::showAnalysePage()
{
    mainStackedWidget->setCurrentIndex(2);
}

void MainWindow::showMainPage()
{
    mainStackedWidget->setCurrentIndex(3);
}
