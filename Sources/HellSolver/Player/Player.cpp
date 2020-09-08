#include <HellSolver/Player/Player.hpp>
#include <iostream>

namespace hell_solver
{
Player::Player(std::size_t initX, std::size_t initY, std::size_t initMoveCount)
    : x(initX), y(initY), moveCount(initMoveCount)
{
}

std::pair<std::size_t, std::size_t> Player::MovePlayer(Direction dir)
{
    // waiting for CanMove method
    std::cout << static_cast<std::underlying_type<Direction>::type>(dir)
              << std::endl;

    return std::make_pair(x, y);
}
void Player::ProcessMove(Direction dir)
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

    moveCount--;
}
PlayerStatus Player::GetPlayerStatus()
{
    return status;
}

bool Player::HasKey() const
{
    return key;
}

}  // namespace hell_solver