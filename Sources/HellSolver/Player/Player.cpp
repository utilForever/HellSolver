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
            y--;
            break;

        case Direction::DOWN:
            y++;
            break;

        case Direction::LEFT:
            x--;
            break;

        case Direction::RIGHT:
            x++;
            break;
    }

    moveCount--;
}
PlayerStatus Player::GetPlayerStatus()
{
    return status;
}

}  // namespace hell_solver