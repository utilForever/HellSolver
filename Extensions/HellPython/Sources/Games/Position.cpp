// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Position.hpp>
#include <HellSolver/Games/Position.hpp>

#include <pybind11/stl.h>

using namespace HellSolver;

void AddPosition(pybind11::module& m)
{
    pybind11::class_<Position>(m, "Position")
        .def_readwrite("x", &Position::x)
        .def_readwrite("y", &Position::y);
}