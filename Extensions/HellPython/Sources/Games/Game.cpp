//
// Created by flow on 2020-09-10.
//

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