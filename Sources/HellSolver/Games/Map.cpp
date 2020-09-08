//
// Created by flow on 2020-09-07.
//

#include <HellSolver/Games/Map.hpp>

#include <fstream>

namespace hell_solver
{
Map::Map(std::size_t width, std::size_t height, std::size_t count)
    : m_width(width), m_height(height), m_count(count)
{
    m_initCount = m_count;
    m_board.reserve(m_width * m_height);
    m_initBoard.reserve(m_width * m_height);

    for (size_t i = 0; i < m_width * m_height; ++i)
    {
        // TODO: Optimization
        m_board.emplace_back(Tile{ ObjectType::EMPTY, ObjectType::EMPTY });
        m_initBoard.emplace_back(Tile{ ObjectType::EMPTY, ObjectType::EMPTY });
    }

    m_key = false;
    m_lurker = true;
};

void Map::Reset()
{
    m_board = m_initBoard;
    m_count = m_initCount;
    m_key = false;
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

/*
bool Map::GetKey() const
{
    return m_key;
}

bool Map::GetLurker() const
{
    return m_lurker;
}
*/

void Map::Load(std::string_view filename)
{
    std::ifstream mapFile(filename.data());

    mapFile >> m_width >> m_height >> m_count;

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
            m_board[i].Add(static_cast<ObjectType>(val));
            m_initBoard[i].Add(static_cast<ObjectType>(val));
        }
    }
}

std::pair<std::size_t, std::size_t> Map::GetStartPoint() const
{
    for(std::size_t x = 0 ; x < m_width; x++){
        for(std::size_t y = 0; y<m_height; y++){
            if(At(x, y).HasType(ObjectType::PLAYER))
                return {x, y};
        }
    }

    return {0, 0};
}

Object& Map::At(std::size_t x, std::size_t y) const
{
    return const_cast<Object&>(m_board.at(x * m_width + y));
}
}  // namespace hell_solver