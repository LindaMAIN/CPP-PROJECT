// customwidget.cpp
#include "customwidget.h"
#include <QPushButton>
#include <QHBoxLayout>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent) {
    homeButton = new QPushButton("Home", this);
    aboutUsButton = new QPushButton("About Us", this);
    joButton = new QPushButton("Sites JO", this);
    arrondissementButton = new QPushButton("Arrondissement", this);
    simulationButton = new QPushButton("Simulation", this);

    // Connect buttons to signals
    connect(homeButton, &QPushButton::clicked, this, &CustomWidget::homeButtonClicked);
    connect(aboutUsButton, &QPushButton::clicked, this, &CustomWidget::aboutUsButtonClicked);
    connect(joButton, &QPushButton::clicked, this, &CustomWidget::joButtonClicked);
    connect(arrondissementButton, &QPushButton::clicked, this, &CustomWidget::arrondissementButtonClicked);
    connect(simulationButton, &QPushButton::clicked, this, &CustomWidget::simulationButtonClicked);

    // Layout
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(homeButton);
    layout->addWidget(aboutUsButton);
    layout->addWidget(joButton);
    layout->addWidget(arrondissementButton);
    layout->addWidget(simulationButton);
}

CustomWidget::~CustomWidget() {
    // Cleanup if needed
}
