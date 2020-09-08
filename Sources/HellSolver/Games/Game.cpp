//
// Created by flow on 2020-09-07.
//

#include <HellSolver/Games/Game.hpp>

namespace hell_solver
{
Game::Game(std::string_view filename)
{
    m_map.Load(filename);
    Position StartPoint = m_map.GetStartPoint();
    GamePlayer = new Player(StartPoint.first, StartPoint.second,
                            m_map.GetInitMoveCount());
}

void Game::Reset()
{
    delete (GamePlayer);
    Position StartPoint = m_map.GetStartPoint();
    GamePlayer = new Player(StartPoint.first, StartPoint.second,
                            m_map.GetInitMoveCount());
}

Map& Game::GetMap()
{
    return m_map;
}

MoveState Game::CanMove(Direction dir){
    Position position = GamePlayer->GetPosition();
    return CanMove(position.first, position.second, dir);
}

MoveState Game::CanMove(size_t x, size_t y, Direction dir)
{
    Position d_pair = Move(x, y, dir);
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
        else
        {
            return MoveState::STOP;
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

PlayerStatus Game::MovePlayer(Direction dir)
{
    Position position = GamePlayer->GetPosition();

    MoveState result = CanMove(position.first, position.second, dir);

    switch (result)
    {
        case MoveState::MOVE:
            position = GamePlayer->ProcessMove(dir);

        case MoveState::STAND:
            GamePlayer->DecreaseMoveCount();
            m_map.SetLurker();
            break;

        case MoveState::STOP:
            break;
    }

    Tile tile = m_map.At(position.first, position.second).GetTypes();
    if (Object::HasType(tile, ObjectType::KEY))
    {
        GamePlayer->SetKey();
        m_map.At(position.first, position.second).Remove(ObjectType::KEY);
    }
    if (Object::HasType(tile, ObjectType::SPIKE) ||
        (!m_map.GetLurker() && Object::HasType(tile, ObjectType::DOWN)) ||
        (m_map.GetLurker() && Object::HasType(tile, ObjectType::UP)))
    {
        GamePlayer->DecreaseMoveCount();
    }
    
    return GamePlayer->GetPlayerStatus(Object::HasType(tile, ObjectType::ENDPOINT));
}

Position Game::Move(std::size_t x, std::size_t y, Direction dir)
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

Player& Game::GetPlayer()
{
    return *GamePlayer;
}

}  // namespace hell_solver