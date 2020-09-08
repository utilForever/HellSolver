//
// Created by flow on 2020-09-07.
//

#include <HellSolver/Games/Game.hpp>

namespace hell_solver
{
Game::Game(std::string_view filename)
{
    m_map.Load(filename);
    std::pair<std::size_t, std::size_t> StartPoint = m_map.GetStartPoint();
    GamePlayer = new Player(StartPoint.first, StartPoint.second,
                            m_map.GetInitMoveCount());
}

void Game::Reset()
{
    delete (GamePlayer);
    std::pair<std::size_t, std::size_t> StartPoint = m_map.GetStartPoint();
    GamePlayer = new Player(StartPoint.first, StartPoint.second,
                            m_map.GetInitMoveCount());
}

Map& Game::GetMap()
{
    return m_map;
}

MoveState Game::CanMove(Direction dir)
{
    std::pair<std::size_t, std::size_t> position = GamePlayer->GetPosition();
    std::pair<std::size_t, std::size_t> d_pair =
        Move(position.first, position.second, dir);
    std::size_t _x = d_pair.first, _y = d_pair.second;

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

    // If encountered block is SPECIAL block,
    if (blockType.HasType(ObjectType::EMPTY) ||
        blockType.HasType(ObjectType::SPIKE) ||
        blockType.HasType(ObjectType::KEY))
    {
        return MoveState::MOVE;
    }

    // If encountered block is LOCK,
    if (blockType.HasType(ObjectType::LOCK))
    {
        if (GamePlayer->HasKey())
        {
            return MoveState::MOVE;
        }
        return MoveState::STOP;
    }

    // If encountered block is DEVIL,
    if (blockType.HasType(ObjectType::DEVIL))
    {
        return MoveState::MOVE;
    }

    return MoveState::STOP;
}

std::pair<std::size_t, std::size_t> Game::Move(std::size_t x, std::size_t y,
                                               Direction dir)
{
    std::size_t dx = x, dy = y;

    if (dir == Direction::UP)
        dx -= 1;
    else if (dir == Direction::DOWN)
        dx += 1;
    else if (dir == Direction::LEFT)
        dy -= 1;
    else if (dir == Direction::RIGHT)
        dy += 1;

    return std::make_pair(dx, dy);
}

}  // namespace hell_solver