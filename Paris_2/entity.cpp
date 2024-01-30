#include "entity.h"

Entity::Entity() : id(0), name("") {} // Default constructor

Entity::Entity(int id, const QString& name) : id(id), name(name) {}

Entity::~Entity() {}

int Entity::getID() const {
    return id;
}

QString Entity::getName() const {
    return name;
}
