// mygraphicscene.h
#ifndef MYGRAPHICSCENE_H
#define MYGRAPHICSCENE_H

#include <QGraphicsScene>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT  // Add this line
public:
    MyGraphicsScene(QObject *parent = nullptr);
signals:
    void clicked(QGraphicsSceneMouseEvent *event);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // MYGRAPHICSCENE_H
