#include <HellSolver/Player/Player.hpp>
#include <iostream>

namespace hell_solver
{
Player::Player(std::size_t initX, std::size_t initY, std::size_t initMoveCount)
    : x(initX), y(initY), moveCount(initMoveCount)
{
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

}  // namespace hell_solver