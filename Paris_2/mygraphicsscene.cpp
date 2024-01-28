// mygraphicsscene.cpp
#include "mygraphicscene.h"

MyGraphicsScene::MyGraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
{
}


void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(event);  // Émettre le signal lors d'un clic
    QGraphicsScene::mousePressEvent(event);
}

