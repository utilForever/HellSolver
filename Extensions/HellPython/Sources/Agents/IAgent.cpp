//
// Created by flow on 2020-09-11.
//

#include <Agents/IAgent.hpp>
#include <HellSolver/Agents/IAgent.hpp>

using namespace hell_solver;

void AddIAgent(pybind11::module& m){
    pybind11::class_<IAgent>(m, "IAgent");
}