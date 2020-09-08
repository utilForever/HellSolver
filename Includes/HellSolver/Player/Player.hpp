#ifndef HELL_SOLVER_PLAYER_HPP
#define HELL_SOLVER_PLAYER_HPP

#include <HellSolver/Enums/GameEnums.hpp>
#include <utility>

namespace hell_solver
{
class Player
{
 public:
    Player() = default;

    ~Player() = default;

    Player(std::size_t initX, std::size_t initY, std::size_t moveCount);

    [[nodiscard]] std::pair<std::size_t, std::size_t> ProcessMove(Direction dir);

    [[nodiscard]] PlayerStatus GetPlayerStatus(bool isEndPoint) const;

    [[nodiscard]] std::size_t GetMoveCount() const;

    [[nodiscard]] bool HasKey() const;

    void SetKey();

    [[nodiscard]] std::pair<std::size_t, std::size_t> GetPosition() const;

    void DecreaseMoveCount();

  private:
    std::size_t x = 0;
    std::size_t y = 0;
    std::size_t moveCount = 0;
    bool hasKey = false;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_PLAYER_HPP
