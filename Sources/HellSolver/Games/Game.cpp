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

    Position startPos = m_map.GetStartPos();
    m_gamePlayer = std::make_unique<Player>(startPos, m_map.GetInitMoveCount());
}

void Game::Reset()
{
    m_map.Reset();

    const Position startPos = m_map.GetStartPos();
    m_gamePlayer->Reset(startPos, m_map.GetInitMoveCount());
}

Map& Game::GetMap()
{
    return m_map;
}

Player& Game::GetPlayer() const
{
    return *m_gamePlayer;
}

PlayerStatus Game::MovePlayer(Direction dir)
{
    Position pos = m_gamePlayer->GetPosition();
    const MoveState result = CanMove(pos, dir);

    switch (result)
    {
        case MoveState::STOP:
            break;
        case MoveState::MOVE:
            pos = m_gamePlayer->ProcessMove(dir);
            m_gamePlayer->DecreaseMoveCount();
            m_map.FlipLurkerFlag();
            break;
        case MoveState::ROCK:
            PushRock(pos, dir);
            m_gamePlayer->DecreaseMoveCount();
            m_map.FlipLurkerFlag();
            break;
        case MoveState::UNDEAD:
            PushUndead(pos, dir);
            m_gamePlayer->DecreaseMoveCount();
            m_map.FlipLurkerFlag();
            break;
        case MoveState::ENDPOINT:
            pos = m_gamePlayer->ProcessMove(dir);
            m_gamePlayer->DecreaseMoveCount();
            m_map.FlipLurkerFlag();
            break;
        case MoveState::STAND:
            m_gamePlayer->DecreaseMoveCount();
            m_map.FlipLurkerFlag();
            break;
    }

    Object block = m_map.At(pos.x, pos.y);
    if (block.HasType(ObjectType::KEY))
    {
        m_gamePlayer->SetKey();
        m_map.At(pos.x, pos.y).Remove(ObjectType::KEY);
    }
    else if (block.HasType(ObjectType::LOCK))
    {
        m_map.At(pos.x, pos.y).Remove(ObjectType::LOCK);
    }
    else if (block.HasType(ObjectType::SPIKE) ||
             m_map.CanLurkerAttackThisMove(block))
    {
        m_gamePlayer->DecreaseMoveCount();
    }

    m_map.ProcessUndeadObjects();

    return m_gamePlayer->GetStatus(result == MoveState::ENDPOINT);
}

MoveState Game::CanMove(Position pos, Direction dir) const
{
    const Position nextPos = Move(pos, dir);
    const std::size_t nextX = nextPos.x, nextY = nextPos.y;
    const Object blockType = m_map.At(nextX, nextY);

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

Position Game::Move(Position pos, Direction dir)
{
    std::size_t dx = pos.x, dy = pos.y;

    if (dir == Direction::UP)
    {
        dy -= 1;
    }
    else if (dir == Direction::DOWN)
    {
        dy += 1;
    }
    else if (dir == Direction::LEFT)
    {
        dx -= 1;
    }
    else if (dir == Direction::RIGHT)
    {
        dx += 1;
    }

    return { dx, dy };
}

void Game::PushRock(Position pos, Direction dir) const
{
    const Position curRockPos = Move(pos, dir);
    const Position nextRockPos = Move(curRockPos, dir);

    const Object nextRockPosObject = m_map.At(nextRockPos.x, nextRockPos.y);

    if (!nextRockPosObject.HasType(ObjectType::WALL, ObjectType::DEVIL,
                                   ObjectType::LOCK, ObjectType::UNDEAD,
                                   ObjectType::ROCK))
    {
        m_map.At(curRockPos.x, curRockPos.y).Remove(ObjectType::ROCK);
        m_map.At(nextRockPos.x, nextRockPos.y).Add(ObjectType::ROCK);
    }
}

void Game::PushUndead(Position pos, Direction dir) const
{
    const Position curUndeadPos = Move(pos, dir);
    const Position nextUndeadPos = Move(curUndeadPos, dir);

    const Object nextUndeadPosObject =
        m_map.At(nextUndeadPos.x, nextUndeadPos.y);

    if (nextUndeadPosObject.HasType(ObjectType::WALL, ObjectType::DEVIL,
                                    ObjectType::LOCK, ObjectType::UNDEAD,
                                    ObjectType::ROCK))
    {
        m_map.At(curUndeadPos.x, curUndeadPos.y).Remove(ObjectType::UNDEAD);
    }
    else
    {
        m_map.At(curUndeadPos.x, curUndeadPos.y).Remove(ObjectType::UNDEAD);
        m_map.At(nextUndeadPos.x, nextUndeadPos.y).Add(ObjectType::UNDEAD);
    }
}
}  // namespace HellSolver