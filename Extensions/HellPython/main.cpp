//
// Created by flow on 2020-09-11.
//

#include <Agents/IAgent.hpp>
#include <Agents/RandomAgent.hpp>
#include <Enums/GameEnums.hpp>
#include <Games/Game.hpp>
#include <Games/Map.hpp>
#include <Games/Object.hpp>
#include <Player/Player.hpp>

#include <pybind11/pybind11.h>

PYBIND11_MODULE(pyHell, m)
{
    m.doc() =
        R"pbdoc(Helltaker simulator with some reinforcement learning)pbdoc";

    AddGame(m);
    AddIAgent(m);
    AddRandomAgent(m);
    AddGameEnums(m);
    AddGameEnumsUtils(m);
    AddMap(m);
    AddObject(m);
    AddPlayer(m);
}