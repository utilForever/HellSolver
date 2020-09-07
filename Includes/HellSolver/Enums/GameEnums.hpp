#ifndef HELL_SOLVER_GAME_ENUMS_HPP
#define HELL_SOLVER_GAME_ENUMS_HPP

namespace hell_solver
{
enum class PlayerStatus
{
    PLAYING,
    WIN,
    LOST,
    INVALID
};

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_ENUMS_HPP
