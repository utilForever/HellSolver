// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_PYTHON_GAME_ENUMS_HPP
#define HELL_PYTHON_GAME_ENUMS_HPP

#include <pybind11/pybind11.h>

void AddGameEnums(pybind11::module& m);
void AddGameEnumsUtils(pybind11::module& m);

#endif  // HELL_PYTHON_GAME_ENUMS_HPP
