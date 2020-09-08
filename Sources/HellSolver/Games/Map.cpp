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

    for (std::size_t i = 0; i < m_width * m_height; ++i)
    {
        m_initBoard.emplace_back(std::vector<ObjectType>{ ObjectType::EMPTY });
        m_board.emplace_back(std::vector<ObjectType>{ ObjectType::EMPTY });
    }
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

std::size_t Map::GetKey() const
{
    return m_key;
}

std::size_t Map::GetLurker() const
{
    return m_lurker;
}

void Map::Load(std::string_view filename)
{
    std::ifstream mapFile(filename.data());

    mapFile >> m_width >> m_height >> m_count;

    int val = 0;
    for (size_t i = 0; i < m_width * m_height; ++i)
    {
        mapFile >> val;

        m_initBoard.emplace_back(std::vector<ObjectType>{ static_cast<ObjectType>(val) });
        m_board.emplace_back(std::vector<ObjectType>{ static_cast<ObjectType>(val) });
    }
}

std::vector<ObjectType>& Map::At(std::size_t x, std::size_t y) const
{
    return m_board[y * m_width + x];
}
}  // namespace hell_solver