//
// Created by flow on 2020-09-08.
//

#include <HellSolver/Games/Map.hpp>
#include <HellSolver/Games/Object.hpp>

#include <utility>

namespace hell_solver
{
Object::Object(Tile tile) : objectTile(std::move(tile)){};

void Object::Add(ObjectType type)
{
    if (type == ObjectType::KEY || type == ObjectType::SPIKE ||
        type == ObjectType::UP || type == ObjectType::DOWN ||
        type == ObjectType::ENDPOINT)
    {
        objectTile.second = type;
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
    if (type == ObjectType::EMPTY)
    {
        return objectTile.first == ObjectType::EMPTY;
    }
    if (type == ObjectType::LURKER_TYPE)
    {
        return IsLurkerType(objectTile.second);
    }
    if (objectTile.first == type || objectTile.second == type)
    {
        return true;
    }
    return false;
}

bool Object::HasType(const Tile& tile, ObjectType type)
{
    if (tile.first == type || tile.second == type)
    {
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace hell_solver