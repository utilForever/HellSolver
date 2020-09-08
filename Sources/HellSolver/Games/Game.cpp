//
// Created by flow on 2020-09-07.
//

#include <HellSolver/Games/Game.hpp>
#include <HellSolver/Player/Player.hpp>

namespace hell_solver
{
Game::Game(std::string_view filename)
{
    m_map.Load(filename);

    std::pair<std::size_t, std::size_t> StartPoint =  m_map.GetStartPoint();
    Player(StartPoint.first, StartPoint.second, m_map.GetMoveCount());
}

void Game::Reset()
{
    // Do nothing.
}

Map& Game::GetMap()
{
    return m_map;
}

const Map& Game::GetMap() const
{
    return m_map;
}

void Game::MovePlayer(Direction dir)
{
    auto position = m_player;
}

MoveState Game::CanMove(std::size_t x, std::size_t y, Direction dir)
{
    std::pair<int, int> d_pair = Move(x, y, dir);
    int _x = d_pair.first, _y = d_pair.second;

    Object blockType = m_map.At(_x, _y);

    // If encountered block is WALL, STOP.
    if (blockType.HasType(ObjectType::WALL))
    {
        return MoveState::STOP;
    }
    // If encountered block is ROCK,
    if (blockType.HasType(ObjectType::ROCK))
    {
        Object nextType = m_map.At(_x, _y);

        // If the block behind ROCK is EMPTY or KEY or LURKER
        if (nextType.HasType(ObjectType::EMPTY) ||
            nextType.HasType(ObjectType::KEY) ||
            nextType.HasType(ObjectType::LURKER_TYPE))
        {
            return MoveState::STAND;
        }
    }
    // If encountered block is UNDEAD,
    if (blockType.HasType(ObjectType::UNDEAD))
    {
        return MoveState::STAND;
    }
    if (blockType.HasType(ObjectType::EMPTY) ||
        blockType.HasType(ObjectType::SPIKE) ||
        blockType.HasType(ObjectType::KEY))
    {
        return MoveState::MOVE;
    }

    // If encountered block is DEVIL,
    if (blockType.HasType(ObjectType::DEVIL))
    {
        m_playerStatus = PlayerStatus::WIN;
        return MoveState::MOVE;
    }

    return MoveState::STOP;
}

// TODO: ProcessMove will be considered below;
//
// void Game::ProcessMove(std::size_t x, std::size_t y, Direction dir);

PlayerStatus Game::GetPlayerStatus() const
{
    return m_playerStatus;
}

std::pair<int, int> Game::Move(std::size_t x, std::size_t y, Direction dir)
{
    int _x = static_cast<int>(x);
    int _y = static_cast<int>(y);

    int dx, dy;
    dx = dy = 0;

    if (dir == Direction::UP)
        dx = -1;
    else if (dir == Direction::DOWN)
        dx = 1;
    else if (dir == Direction::LEFT)
        dy = -1;
    else if (dir == Direction::RIGHT)
        dy = 1;

    _x += dx;
    _y += dy;

    return std::make_pair(_x, _y);
}

}  // namespace hell_solver