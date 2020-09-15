// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Games/Game.hpp>

namespace HellSolver
{
Game::Game(std::string_view filename)
{
    m_map.Load(filename);
    Position StartPoint = m_map.GetStartPoint();
    m_gamePlayer = std::make_unique<Player>(StartPoint.first, StartPoint.second,
                                            m_map.GetInitMoveCount());
}

void Game::Reset()
{
    m_map.Reset();
    Position StartPoint = m_map.GetStartPoint();
    m_gamePlayer->Reset(StartPoint.first, StartPoint.second,
                        m_map.GetInitMoveCount());
}

Map& Game::GetMap()
{
    return m_map;
}

PlayerStatus Game::MovePlayer(Direction dir)
{
    Position position = m_gamePlayer->GetPosition();

    MoveState result = CanMove(position.first, position.second, dir);

    switch (result)
    {
        case MoveState::STOP:
            break;

        case MoveState::MOVE:
            position = m_gamePlayer->ProcessMove(dir);
            m_gamePlayer->DecreaseMoveCount();
            m_map.SetLurker();
            break;

        case MoveState::ROCK:
            PushRock(position.first, position.second, dir);
            m_gamePlayer->DecreaseMoveCount();
            m_map.SetLurker();
            break;

        case MoveState::UNDEAD:
            PushUndead(position.first, position.second, dir);
            m_gamePlayer->DecreaseMoveCount();
            m_map.SetLurker();
            break;

        case MoveState::ENDPOINT:
            position = m_gamePlayer->ProcessMove(dir);

        case MoveState::STAND:
            m_gamePlayer->DecreaseMoveCount();
            m_map.SetLurker();
            break;
    }

    Object block = m_map.At(position.first, position.second);
    if (block.HasType(ObjectType::KEY))
    {
        m_gamePlayer->SetKey();
        m_map.At(position.first, position.second).Remove(ObjectType::KEY);
    }
    else if (block.HasType(ObjectType::LOCK))
    {
        m_map.At(position.first, position.second).Remove(ObjectType::LOCK);
    }
    else if (block.HasType(ObjectType::SPIKE) || m_map.IsLurkerAttack(block))
    {
        m_gamePlayer->DecreaseMoveCount();
    }

    m_map.CheckUndead();

    return m_gamePlayer->GetPlayerStatus(result == MoveState::ENDPOINT);
}

void Game::PushRock(std::size_t x, std::size_t y, Direction dir)
{
    Position curRockPosition = Move(x, y, dir);
    Position nextRockPosition =
        Move(curRockPosition.first, curRockPosition.second, dir);

    Object nextRockPositionObject =
        m_map.At(nextRockPosition.first, nextRockPosition.second);

    if (!nextRockPositionObject.HasType(ObjectType::WALL, ObjectType::DEVIL,
                                        ObjectType::LOCK, ObjectType::UNDEAD,
                                        ObjectType::ROCK))
    {
        m_map.At(curRockPosition.first, curRockPosition.second)
            .Remove(ObjectType::ROCK);
        m_map.At(nextRockPosition.first, nextRockPosition.second)
            .Add(ObjectType::ROCK);
    }
}

void Game::PushUndead(std::size_t x, std::size_t y, Direction dir)
{
    Position curUndeadPosition = Move(x, y, dir);
    Position nextUndeadPosition =
        Move(curUndeadPosition.first, curUndeadPosition.second, dir);

    Object nextUndeadPositionObject =
        m_map.At(nextUndeadPosition.first, nextUndeadPosition.second);

    if (nextUndeadPositionObject.HasType(ObjectType::WALL, ObjectType::DEVIL,
                                         ObjectType::LOCK, ObjectType::UNDEAD,
                                         ObjectType::ROCK))
    {
        m_map.At(curUndeadPosition.first, curUndeadPosition.second)
            .Remove(ObjectType::UNDEAD);
    }
    else
    {
        m_map.At(curUndeadPosition.first, curUndeadPosition.second)
            .Remove(ObjectType::UNDEAD);
        m_map.At(nextUndeadPosition.first, nextUndeadPosition.second)
            .Add(ObjectType::UNDEAD);
    }
}

MoveState Game::CanMove(std::size_t x, std::size_t y, Direction dir)
{
    Position d_pair = Move(x, y, dir);
    std::size_t _x = d_pair.first, _y = d_pair.second;

    Object blockType = m_map.At(_x, _y);

    // If encountered block is ENDPOINT, without any other objects.
    if (blockType.HasType(ObjectType::ENDPOINT))
    {
        return MoveState::ENDPOINT;
    }

    // If encountered block is SPECIAL block,
    if (blockType.HasType(ObjectType::EMPTY))
    {
        return MoveState::MOVE;
    }

    // If encountered block is LOCK,
    if (blockType.HasType(ObjectType::LOCK))
    {
        if (m_gamePlayer->HasKey())
        {
            return MoveState::MOVE;
        }
        return MoveState::STAND;
    }

    // If encountered block is UNDEAD,
    if (blockType.HasType(ObjectType::UNDEAD))
    {
        return MoveState::UNDEAD;
    }

    // If encountered block is ROCK,
    if (blockType.HasType(ObjectType::ROCK))
    {
        return MoveState::ROCK;
    }

    return MoveState::STOP;
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
    return *m_gamePlayer;
}

}  // namespace HellSolver