// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Models/Map.hpp>
#include <Models/Map.hpp>

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
        .def("FlipLurkerFlag", &Map::FlipLurkerFlag)
        .def("ProcessUndeadObjects", &Map::ProcessUndeadObjects)
        .def("CanLurkerAttack", &Map::CanLurkerAttack)
        .def("Load", static_cast<void (Map::*)(std::string_view)>(&Map::Load))
        .def("At",
             static_cast<Object& (Map::*)(std::size_t, std::size_t) const>(
                 &Map::At));
}