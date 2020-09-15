// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Player/Player.hpp>
#include <Player/Player.hpp>

using namespace HellSolver;

void AddPlayer(pybind11::module& m)
{
    pybind11::class_<Player>(m, "Player")
        .def(pybind11::init<>())
        .def(pybind11::init<Position, std::size_t>())
        .def("Reset", static_cast<void (Player::*)(Position, std::size_t)>(
                          &Player::Reset))
        .def("Processmove",
             static_cast<Position (Player::*)(Direction)>(&Player::ProcessMove))
        .def("GetStatus", static_cast<PlayerStatus (Player::*)(bool) const>(
                              &Player::GetStatus))
        .def("GetMoveCount", &Player::GetMoveCount)
        .def("HasKey", &Player::HasKey)
        .def("SetKey", &Player::SetKey)
        .def("GetPosition", &Player::GetPosition)
        .def("DecreaseMoveCount", &Player::DecreaseMoveCount);
}