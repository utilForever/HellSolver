// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Agents/RandomAgent.hpp>
#include <HellSolver/Agents/RandomAgent.hpp>

using namespace hell_solver;

void AddRandomAgent(pybind11::module& m)
{
    pybind11::class_<RandomAgent>(m, "RandomAgent")
        .def("GetAction", static_cast<Direction (RandomAgent::*)(const Game&)>(
                              &RandomAgent::GetAction));
}