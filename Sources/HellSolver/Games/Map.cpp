// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Games/Map.hpp>

#include <fstream>

namespace HellSolver
{
void Map::Load(std::string_view filename)
{
    std::ifstream mapFile(filename.data());

    mapFile >> m_width >> m_height >> m_initMoveCount;
    mapFile >> m_startPos.first >> m_startPos.second;

    int val = 0;
    for (std::size_t i = 0; i < m_width * m_height; ++i)
    {
        mapFile >> val;

        m_board.emplace_back(
            Tile{ static_cast<ObjectType>(val), ObjectType::EMPTY });
        m_initBoard.emplace_back(
            Tile{ static_cast<ObjectType>(val), ObjectType::EMPTY });
    }

    mapFile >> val;

    if (val)
    {
        for (std::size_t i = 0; i < m_width * m_height; ++i)
        {
            mapFile >> val;
            auto type = static_cast<ObjectType>(val);

            m_board[i].Init(type);
            m_initBoard[i].Init(type);
        }
    }
}

void Map::Reset()
{
    m_board = m_initBoard;
    m_lurker = true;
}

std::size_t Map::GetWidth() const
{
    return m_width;
}

std::size_t Map::GetHeight() const
{
    return m_height;
}

Position Map::GetStartPos() const
{
    return m_startPos;
}

std::size_t Map::GetInitMoveCount() const
{
    return m_initMoveCount;
}

void Map::SetLurker()
{
    m_lurker = !m_lurker;
}

void Map::CheckUndead()
{
    for (std::size_t i = 0; i < m_width * m_height; ++i)
    {
        if (m_board[i].HasType(ObjectType::UNDEAD) &&
            IsLurkerAttack(m_board[i]))
        {
            m_board[i].Remove(ObjectType::UNDEAD);
        }
    }
}

bool Map::IsLurkerAttack(Object& object) const
{
    return (!m_lurker && object.HasType(ObjectType::DOWN)) ||
           (m_lurker && object.HasType(ObjectType::UP));
}

bool Map::IsLurkerNextAttack(Object& object) const
{
    return (m_lurker && object.HasType(ObjectType::DOWN)) ||
           (!m_lurker && object.HasType(ObjectType::UP));
}

Object& Map::At(std::size_t x, std::size_t y) const
{
    return const_cast<Object&>(m_board.at(x * m_width + y));
}
}  // namespace HellSolver