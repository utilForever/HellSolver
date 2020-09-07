#include <HellSolver/Player/Player.hpp>
#include <iostream>

namespace hell_solver{
Player::Player(int initX, int initY, int initMoveCount) : x(initX), y(initY), moveCount(initMoveCount) {}

std::pair<int, int> Player::MovePlayer(Direction dir)
{
    // waiting for CanMove method
    std::cout << static_cast<std::underlying_type<Direction>::type>(dir) << std::endl;

    return std::make_pair(x, y);
}
void Player::ProcessMove(Direction dir)
{
    switch(dir) {
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
}
PlayerStatus Player::GetPlayerStatus()
{
    return status;
}

}