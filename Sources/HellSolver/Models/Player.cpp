// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Models/Player.hpp>

namespace HellSolver
{
Player::Player(Position pos, std::size_t moveCount)
    : m_pos(pos), m_moveCount(moveCount)
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
            m_pos.y -= 1;
            break;
        case Direction::DOWN:
            m_pos.y += 1;
            break;
        case Direction::LEFT:
            m_pos.x -= 1;
            break;
        case Direction::RIGHT:
            m_pos.x += 1;
            break;
        case Direction::INVALID:
            break;
    }

    return m_pos;
}

PlayerStatus Player::GetStatus(bool isEndPoint) const
{
    if (isEndPoint)
    {
        return PlayerStatus::WIN;
    }

    if (!m_moveCount)
    {
        return PlayerStatus::LOST;
    }

    return PlayerStatus::PLAYING;
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