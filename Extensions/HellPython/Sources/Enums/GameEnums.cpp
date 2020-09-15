// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Enums/GameEnums.hpp>
#include <HellSolver/Enums/GameEnums.hpp>

using namespace hell_solver;

void AddGameEnums(pybind11::module& m)
{
    pybind11::enum_<ObjectType>(m, "ObjectType")
        .value("FIXED_TYPE", ObjectType::FIXED_TYPE)
        .value("EMPTY", ObjectType::EMPTY)
        .value("WALL", ObjectType::WALL)
        .value("DEVIL", ObjectType::DEVIL)
        .value("SPIKE", ObjectType::SPIKE)
        .value("KEY", ObjectType::KEY)
        .value("LOCK", ObjectType::LOCK)
        .value("LURKER_TYPE", ObjectType::LURKER_TYPE)
        .value("UP", ObjectType::UP)
        .value("DOWN", ObjectType::DOWN)
        .value("MOVING_TYPE", ObjectType::MOVING_TYPE)
        .value("PLAYER", ObjectType::PLAYER)
        .value("UNDEAD", ObjectType::UNDEAD)
        .value("ROCK", ObjectType::ROCK)
        .value("ENDPOINT", ObjectType::ENDPOINT)
        .export_values();

    pybind11::enum_<MoveState>(m, "MoveState")
        .value("MOVE", MoveState::MOVE)
        .value("ROCK", MoveState::ROCK)
        .value("UNDEAD", MoveState::UNDEAD)
        .value("STAND", MoveState::STAND)
        .value("STOP", MoveState::STOP)
        .value("ENDPOINT", MoveState::ENDPOINT)
        .export_values();

    pybind11::enum_<PlayerStatus>(m, "PlayerStatus")
        .value("PLAYING", PlayerStatus::PLAYING)
        .value("WIN", PlayerStatus::WIN)
        .value("LOST", PlayerStatus::LOST)
        .value("INVALID", PlayerStatus::INVALID)
        .export_values();

    pybind11::enum_<Direction>(m, "Direction")
        .value("UP", Direction::UP)
        .value("DOWN", Direction::DOWN)
        .value("LEFT", Direction::LEFT)
        .value("RIGHT", Direction::RIGHT)
        .value("INVALID", Direction::INVALID);
}

void AddGameEnumsUtils(pybind11::module& m){
    m.def("IsLurkerType", IsLurkerType);
}