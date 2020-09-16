// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Agents/IAgent.hpp>
#include <Agents/RandomAgent.hpp>
#include <Enums/GameEnums.hpp>
#include <Games/Game.hpp>
#include <Models/Map.hpp>
#include <Models/Object.hpp>
#include <Models/Player.hpp>
#include <Models/Position.hpp>

#include <pybind11/pybind11.h>

PYBIND11_MODULE(pyHell, m)
{
    m.doc() =
        R"pbdoc(Helltaker simulator with some reinforcement learning)pbdoc";

    AddIAgent(m);
    AddRandomAgent(m);

    AddGameEnums(m);
    AddGameEnumsUtils(m);

    AddGame(m);

    AddMap(m);
    AddObject(m);
    AddPosition(m);
    AddPlayer(m);
}