// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Agents/IAgent.hpp>
#include <HellSolver/Agents/IAgent.hpp>

using namespace HellSolver;

void AddIAgent(pybind11::module& m){
    pybind11::class_<IAgent>(m, "IAgent");
}