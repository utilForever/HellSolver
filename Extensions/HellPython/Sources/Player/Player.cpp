//
// Created by flow on 2020-09-11.
//

#include <HellSolver/Player/Player.hpp>
#include <Player/Player.hpp>

using namespace hell_solver;

void AddPlayer(pybind11::module& m)
{
    pybind11::class_<Player>(m, "Player")
        .def(pybind11::init<>())
        .def(pybind11::init<std::size_t, std::size_t, std::size_t>())
        .def("Reset",
             static_cast<void (Player::*)(std::size_t, std::size_t,
                                          std::size_t)>(&Player::Reset))
        .def("Processmove",
             static_cast<Position (Player::*)(Direction)>(&Player::ProcessMove))
        .def("GetPlayerStatus",
             static_cast<PlayerStatus (Player::*)(bool) const>(
                 &Player::GetPlayerStatus))
        .def("GetMoveCount", &Player::GetMoveCount)
        .def("HasKey", &Player::HasKey)
        .def("SetKey", &Player::SetKey)
        .def("GetPosition", &Player::GetPosition)
        .def("DecreaseMoveCount", &Player::DecreaseMoveCount);
}