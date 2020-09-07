#ifndef HELL_SOLVER_GAME_ENUMS_HPP
#define HELL_SOLVER_GAME_ENUMS_HPP

namespace hell_solver
{
enum class ObjectType
{
    FIXED_TYPE,
    EMPTY,
    WALL,
    DEVIL,
    SPIKE,
    KEY,
    LOCK,
    MOVING_TYPE,
    PLAYER,
    UNDEAD,
    ROCK,
    LURKER
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
