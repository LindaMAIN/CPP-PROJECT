#ifndef PLACE_H
#define PLACE_H

#include <QObject>

class Place : public QObject
{
    Q_OBJECT
public:
    //constructeur par default   Qobject *parent =nullptr est un pointeur vers l'object parent, si le parent suppr alors les childs aussi.
    //Dans ce cas précis on dit que les instances de places n'ont pas de parent
    explicit Place(Qobject *parent = nullptr, int maxCapacity = 100);
    int getCurrentNumber() const;
    int getMaxCapacity() const;


public slot:
    //On utilise public slot car il permet une meilleur connectivité avec l'application et les signaux
    void enterPeople(int people);
    void exitPeople(int people);
    

private:
    int number;
    const int max_capacity;
    
};

#endif // PLACE_H
