#ifndef HELL_SOLVER_GAME_ENUMS_HPP
#define HELL_SOLVER_GAME_ENUMS_HPP

namespace hell_solver
{
enum class ObjectType
{
    FIXED_TYPE,   // 0
    EMPTY,        // 1
    WALL,         // 2
    DEVIL,        // 3
    SPIKE,        // 4
    KEY,          // 5
    LOCK,         // 6
    MOVING_TYPE,  // 7
    PLAYER,       // 8
    UNDEAD,       // 9
    ROCK,         // 10
    LURKER        // 11
};

enum class MoveState
{
    MOVE,
    STAND,
    STOP
};

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
