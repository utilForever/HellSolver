// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_GAME_ENUMS_HPP
#define HELL_SOLVER_GAME_ENUMS_HPP

#include <utility>

namespace hell_solver
{
enum class ObjectType
{
    FIXED_TYPE,   // 0 first
    EMPTY,        // 1 first
    WALL,         // 2 first
    DEVIL,        // 3 first
    SPIKE,        // 4 second
    KEY,          // 5 second
    LOCK,         // 6 first
    LURKER_TYPE,  // 7 second
    UP,           // 8 second
    DOWN,         // 9 second
    MOVING_TYPE,  // 10 first
    PLAYER,       // 11 first
    UNDEAD,       // 12 first
    ROCK,         // 13 first
    ENDPOINT      // 14 second
};

enum class MoveState
{
    MOVE,
    ROCK,
    UNDEAD,
    STAND,
    STOP,
    ENDPOINT
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
    RIGHT,
    INVALID
};

constexpr bool IsLurkerType(ObjectType type)
{
    return (type > ObjectType::LURKER_TYPE && type < ObjectType::MOVING_TYPE);
}

typedef std::pair<ObjectType, ObjectType> Tile;
typedef std::pair<std::size_t, std::size_t> Position;

}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_ENUMS_HPP
