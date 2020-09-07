#ifndef HELL_SOLVER_PLAYER_HPP
#define HELL_SOLVER_PLAYER_HPP

#include <utility>
#include <HellSolver/Enums/GameEnums.hpp>

namespace hell_solver
{
class Player
{
public:
    Player() = default;
    Player(int moveCount, int x, int y);

    [[nodiscard]] std::pair<int, int> MovePlayer(Direction dir);

    void ProcessMove(Direction dir);

    [[nodiscard]] PlayerStatus GetPlayerStatus();

private:
    int x = 0;
    int y = 0;
    int  moveCount = 0;
    PlayerStatus status = PlayerStatus::INVALID;
};
}  // namespace hell_solver

#endif  // !HELL_SOLVER_PLAYER_HPP
