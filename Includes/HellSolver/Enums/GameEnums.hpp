#ifndef HELL_SOLVER_GAME_ENUMS_HPP
#define HELL_SOLVER_GAME_ENUMS_HPP

#include <utility>

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
    LURKER_TYPE,  // 7
    UP,           // 8
    DOWN,         // 9
    MOVING_TYPE,  // 10
    PLAYER,       // 11
    UNDEAD,       // 12
    ROCK,         // 13

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

constexpr bool IsFixedType(ObjectType type){
    return (type > ObjectType::FIXED_TYPE && type < ObjectType::LURKER_TYPE);
}

constexpr bool IsLurkerType(ObjectType type){
    return (type > ObjectType::LURKER_TYPE && type < ObjectType::MOVING_TYPE);
}

constexpr bool IsMovingType(ObjectType type){
    return type > ObjectType::MOVING_TYPE;
}


typedef std::pair<ObjectType, ObjectType> Tile;
}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_ENUMS_HPP
