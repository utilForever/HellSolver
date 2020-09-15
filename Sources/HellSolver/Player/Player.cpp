// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Player/Player.hpp>

#include <iostream>

namespace HellSolver
{
Player::Player(std::size_t initX, std::size_t initY, std::size_t initMoveCount)
    : m_x(initX), m_y(initY), m_moveCount(initMoveCount)
{
}

void Player::Reset(std::size_t initX, std::size_t initY,
                   std::size_t initMoveCount)
{
    m_x = initX;
    m_y = initY;
    m_moveCount = initMoveCount;
}

std::pair<std::size_t, std::size_t> Player::ProcessMove(Direction dir)
{
    switch (dir)
    {
        case Direction::UP:
            m_x--;
            break;

        case Direction::DOWN:
            m_x++;
            break;

        case Direction::LEFT:
            m_y--;
            break;

        case Direction::RIGHT:
            m_y++;
            break;

        case Direction::INVALID:
            break;
    }

    return { m_x, m_y };
}

PlayerStatus Player::GetPlayerStatus(bool isEndPoint) const
{
    if (isEndPoint)
    {
        return PlayerStatus::WIN;
    }

    else if (!m_moveCount)
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

std::pair<std::size_t, std::size_t> Player::GetPosition() const
{
    return { m_x, m_y };
}

void Player::DecreaseMoveCount()
{
    m_moveCount--;
}

}  // namespace HellSolver