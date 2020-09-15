// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Games/Object.hpp>

#include <utility>

namespace HellSolver
{
Object::Object(Tile tile) : m_tile(std::move(tile))
{
    // Do nothing
}

void Object::Add(ObjectType type)
{
    if (type == ObjectType::ROCK || type == ObjectType::PLAYER ||
        type == ObjectType::UNDEAD)
    {
        if (m_tile.first == ObjectType::EMPTY)
        {
            m_tile.first = type;
        }
    }
}

void Object::Remove(ObjectType type)
{
    if ((type == ObjectType::ROCK && m_tile.first == ObjectType::ROCK) ||
        (type == ObjectType::UNDEAD && m_tile.first == ObjectType::UNDEAD) ||
        (type == ObjectType::LOCK && m_tile.first == ObjectType::LOCK))
    {
        m_tile.first = ObjectType::EMPTY;
    }
    else if (type == ObjectType::KEY && m_tile.second == ObjectType::KEY)
    {
        m_tile.second = ObjectType::EMPTY;
    }
}

void Object::Init(ObjectType type)
{
    if (type == ObjectType::KEY || IsLurkerType(type) ||
        type == ObjectType::SPIKE || type == ObjectType::ENDPOINT)
    {
        m_tile.second = type;
    }
    else
    {
        m_tile.second = ObjectType::EMPTY;
    }
}

Tile Object::GetTile() const
{
    return m_tile;
}

bool Object::HasType(ObjectType type) const
{
    if (type == ObjectType::EMPTY)
    {
        return m_tile.first == ObjectType::EMPTY;
    }

    if (type == ObjectType::LURKER_TYPE)
    {
        return IsLurkerType(m_tile.second);
    }

    if (type == ObjectType::ENDPOINT)
    {
        return (m_tile.first == ObjectType::EMPTY ||
                m_tile.first == ObjectType::DEVIL) &&
               m_tile.second == ObjectType::ENDPOINT;
    }

    if (m_tile.first == type || m_tile.second == type)
    {
        return true;
    }

    return false;
}
}  // namespace HellSolver