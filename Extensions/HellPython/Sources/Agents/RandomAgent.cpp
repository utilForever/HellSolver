//
// Created by flow on 2020-09-11.
//

#include <Agents/RandomAgent.hpp>
#include <HellSolver/Agents/RandomAgent.hpp>

using namespace hell_solver;

void AddRandomAgent(pybind11::module& m)
{
    pybind11::class_<RandomAgent>(m, "RandomAgent")
        .def("GetAction", static_cast<Direction (RandomAgent::*)(const Game&)>(
                              &RandomAgent::GetAction));
}