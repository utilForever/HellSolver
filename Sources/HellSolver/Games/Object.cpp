//
// Created by flow on 2020-09-08.
//

#include <HellSolver/Games/Map.hpp>

#include <utility>

namespace hell_solver
{
Object::Object(Tile tile) : o_tile(std::move(tile)){};

void Object::Add(ObjectType type)
{
    if (type == ObjectType::ROCK || type == ObjectType::PLAYER ||
        type == ObjectType::UNDEAD)
    {
        if (o_tile.first == ObjectType::EMPTY)
        {
            o_tile.first = type;
        }
    }
}

void Object::Remove(ObjectType type)
{
    if ((type == ObjectType::ROCK && o_tile.first == ObjectType::ROCK) ||
        (type == ObjectType::PLAYER && o_tile.first == ObjectType::PLAYER) ||
        (type == ObjectType::UNDEAD && o_tile.first == ObjectType::UNDEAD) ||
        (type == ObjectType::LOCK && o_tile.first == ObjectType::LOCK))
    {
        o_tile.first = ObjectType::EMPTY;
    }
    else if (type == ObjectType::KEY && o_tile.second == ObjectType::KEY)
    {
        o_tile.second = ObjectType::EMPTY;
    }
}

void Object::Init(ObjectType type)
{
    if (type == ObjectType::KEY || IsLurkerType(type) ||
        type == ObjectType::SPIKE || type == ObjectType::ENDPOINT)
    {
        o_tile.second = type;
    }
}

Tile Object::GetTypes() const
{
    return o_tile;
}

bool Object::HasType(ObjectType type) const
{
    if (type == ObjectType::EMPTY)
    {
        return o_tile.first == ObjectType::EMPTY;
    }
    if (type == ObjectType::LURKER_TYPE)
    {
        return IsLurkerType(o_tile.second);
    }
    if (o_tile.first == type || o_tile.second == type)
    {
        return true;
    }
    return false;
}
}  // namespace hell_solver