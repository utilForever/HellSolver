// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Player/Player.hpp>
#include <iostream>

#include <cassert>

namespace HellSolver
{
Player::Player(std::size_t initX, std::size_t initY, std::size_t initMoveCount)
    : x(initX), y(initY), moveCount(initMoveCount)
{
}

void Player::Reset(std::size_t initX, std::size_t initY, std::size_t initMoveCount){
    x = initX;
    y = initY;
    moveCount = initMoveCount;
}

std::pair<std::size_t, std::size_t> Player::ProcessMove(Direction dir)
{
    switch (dir)
    {
        case Direction::UP:
            x--;
            break;

        case Direction::DOWN:
            x++;
            break;

        case Direction::LEFT:
            y--;
            break;

        case Direction::RIGHT:
            y++;
            break;
            
        case Direction::INVALID:
            break;
    }

    return { x, y };
}

PlayerStatus Player::GetPlayerStatus(bool isEndPoint) const
{
    if (isEndPoint)
    {
        return PlayerStatus::WIN;
    }

    else if (!moveCount)
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
    return moveCount;
}

bool Player::HasKey() const
{
    return hasKey;
}

void Player::SetKey()
{
    hasKey = true;
}

std::pair<std::size_t, std::size_t> Player::GetPosition() const
{
    return { x, y };
}

void Player::DecreaseMoveCount()
{
    moveCount--;
}

}  // namespace HellSolver