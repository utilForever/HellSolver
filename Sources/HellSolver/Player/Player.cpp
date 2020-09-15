// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Player/Player.hpp>

#include <iostream>
#include <utility>

namespace HellSolver
{
Player::Player(Position pos, std::size_t moveCount)
    : m_pos(std::move(pos)), m_moveCount(moveCount)
{
    // Do nothing
}

void Player::Reset(Position pos, std::size_t moveCount)
{
    m_pos = pos;
    m_moveCount = moveCount;
}

Position Player::ProcessMove(Direction dir)
{
    switch (dir)
    {
        case Direction::UP:
            m_pos.first--;
            break;
        case Direction::DOWN:
            m_pos.first++;
            break;
        case Direction::LEFT:
            m_pos.second--;
            break;
        case Direction::RIGHT:
            m_pos.second++;
            break;
        case Direction::INVALID:
            break;
    }

    return m_pos;
}

PlayerStatus Player::GetPlayerStatus(bool isEndPoint) const
{
    if (isEndPoint)
    {
        return PlayerStatus::WIN;
    }

    if (!m_moveCount)
    {
        return PlayerStatus::LOST;
    }

    else
    {
        return PlayerStatus::PLAYING;
    }
}

std::size_t Player::GetMoveCount() const
{
    return m_moveCount;
}

bool Player::HasKey() const
{
    return m_hasKey;
}

void Player::SetKey()
{
    m_hasKey = true;
}

Position Player::GetPosition() const
{
    return m_pos;
}

void Player::DecreaseMoveCount()
{
    m_moveCount--;
}
}  // namespace HellSolver