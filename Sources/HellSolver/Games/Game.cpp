//
// Created by flow on 2020-09-07.
//

#include <HellSolver/Games/Game.hpp>

namespace hell_solver
{
Game::Game(std::string_view filename)
{
    m_map.Load(filename);

    m_playerStatus = PlayerStatus::PLAYING;
}

void Game::Reset()
{
    m_playerStatus = PlayerStatus::PLAYING;
}

MoveState Game::CanMove(std::size_t x, std::size_t y, Direction dir)
{
    std::pair<int, int> d_pair = Move(x, y, dir);
    int _x = d_pair.first, _y = d_pair.second;

    ObjectType blockType = m_map.At(_x, _y);

    // If encountered block is WALL, STOP.
    if (blockType == ObjectType::WALL)
    {
        return MoveState::STOP;
    }
    // If encountered block is ROCK,
    if (blockType == ObjectType::ROCK)
    {
        ObjectType nextType = m_map.At(_x, _y);

        // If the block behind ROCK
        if (nextType == ObjectType::EMPTY || nextType == ObjectType::KEY ||
            nextType == ObjectType::LURKER)
        {
            return MoveState::STAND;
        }
    }
    if (blockType == ObjectType::DEVIL)
    {
        return MoveState::STAND;
    }
    if (blockType == ObjectType::EMPTY || blockType == ObjectType::SPIKE ||
        blockType == ObjectType::KEY)
    {
        return MoveState::MOVE;
    }

    return MoveState::STOP;
}

// TODO: ProcessMove will be considered below:
//
void Game::ProcessMove(std::size_t x, std::size_t y, Direction dir)
{
    std::pair<int, int> d_pair = Move(x, y, dir);
}

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
        dy = -1;
    else if (dir == Direction::DOWN)
        dy = 1;
    else if (dir == Direction::LEFT)
        dx = -1;
    else if (dir == Direction::RIGHT)
        dx = 1;

    _x += dx;
    _y += dy;

    return std::make_pair(_x, _y);
}

}  // namespace hell_solver