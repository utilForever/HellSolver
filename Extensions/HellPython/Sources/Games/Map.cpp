// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Map.hpp>
#include <HellSolver/Games/Map.hpp>

using namespace HellSolver;

void AddMap(pybind11::module& m)
{
    pybind11::class_<Map>(m, "Map")
        .def(pybind11::init<>())
        .def("Reset", &Map::Reset)
        .def("GetWidth", &Map::GetWidth)
        .def("GetHeight", &Map::GetHeight)
        .def("GetStartPos", &Map::GetStartPos)
        .def("GetInitMoveCount", &Map::GetInitMoveCount)
        .def("SetLurker", &Map::SetLurker)
        .def("CheckUndead", &Map::CheckUndead)
        .def("IsLurkerAttack", &Map::IsLurkerAttack)
        .def("IsLurkerNextAttack", &Map::IsLurkerNextAttack)
        .def("Load", static_cast<void (Map::*)(std::string_view)>(&Map::Load))
        .def("At",
             static_cast<Object& (Map::*)(std::size_t, std::size_t) const>(
                 &Map::At));
}