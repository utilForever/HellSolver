// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Game.hpp>
#include <HellSolver/Games/Game.hpp>

using namespace hell_solver;

void AddGame(pybind11::module& m)
{
    pybind11::class_<Game>(m, "Game")
        .def(pybind11::init<std::string_view>())
        .def("Reset", &Game::Reset)
        .def("GetMap", &Game::GetMap)
        .def("GetPlayer", &Game::GetPlayer)
        .def("MovePlayer",
             static_cast<PlayerStatus (Game::*)(Direction)>(&Game::MovePlayer));
}