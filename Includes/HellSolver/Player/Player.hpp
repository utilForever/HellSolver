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
    Player(std::size_t initX, std::size_t initY, std::size_t moveCount);

    [[nodiscard]] std::pair<std::size_t, std::size_t> MovePlayer(Direction dir);

    void ProcessMove(Direction dir);

    [[nodiscard]] PlayerStatus GetPlayerStatus();

private:
    std::size_t x = 0;
    std::size_t y = 0;
    std::size_t  moveCount = 0;
    PlayerStatus status = PlayerStatus::INVALID;
};
}  // namespace hell_solver

#endif  // !HELL_SOLVER_PLAYER_HPP
