//
// Created by flow on 2020-09-08.
//

#include <HellSolver/Games/Object.hpp>

namespace hell_solver
{
Object::Object(Tile tile) : objectTile(tile){};

void Object::Add(ObjectType type)
{
    if (type == ObjectType::KEY || type == ObjectType::SPIKE ||
        type == ObjectType::UP || type == ObjectType::DOWN)
    {
        objectTile.second = type;
    }
    else
    {
        objectTile.first = type;
    }
}

void Object::Remove(ObjectType type)
{
    if (type == ObjectType::KEY || type == ObjectType::SPIKE ||
        type == ObjectType::UP || type == ObjectType::DOWN)
    {
        objectTile.second = ObjectType::EMPTY;
    }
    else
    {
        objectTile.first = ObjectType::EMPTY;
    }
}

Tile Object::GetTypes() const
{
    return objectTile;
}

bool Object::HasType(ObjectType type) const
{
    if (objectTile.first == type || objectTile.second == type)
        return true;
    return false;
}

}  // namespace hell_solver