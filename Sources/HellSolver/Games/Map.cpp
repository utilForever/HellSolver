// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Games/Map.hpp>

#include <fstream>

namespace hell_solver
{
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

bool Map::GetLurker() const
{
    return m_lurker;
}

void Map::SetLurker()
{
    m_lurker = !GetLurker();
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
    return (!GetLurker() && object.HasType(ObjectType::DOWN)) ||
           (GetLurker() && object.HasType(ObjectType::UP));
}

bool Map::IsLurkerNextAttack(Object& object) const
{
    return (GetLurker() && object.HasType(ObjectType::DOWN)) ||
           (!GetLurker() && object.HasType(ObjectType::UP));
}

void Map::Load(std::string_view filename)
{
    std::ifstream mapFile(filename.data());

    mapFile >> m_width >> m_height >> m_initCount;

    mapFile >> m_startPoint.first >> m_startPoint.second;

    int val = 0;
    for (size_t i = 0; i < m_width * m_height; ++i)
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
        for (size_t i = 0; i < m_width * m_height; ++i)
        {
            mapFile >> val;
            auto type = static_cast<ObjectType>(val);

            m_board[i].Init(type);
            m_initBoard[i].Init(type);
        }
    }
}

std::pair<std::size_t, std::size_t> Map::GetStartPoint() const
{
    return m_startPoint;
}

std::size_t Map::GetInitMoveCount() const
{
    return m_initCount;
}

Object& Map::At(std::size_t x, std::size_t y) const
{
    return const_cast<Object&>(m_board.at(x * m_width + y));
}
}  // namespace hell_solver