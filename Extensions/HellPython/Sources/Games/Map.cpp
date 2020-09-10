//
// Created by flow on 2020-09-11.
//

#include <Games/Map.hpp>
#include <HellSolver/Games/Map.hpp>

using namespace hell_solver;

void AddMap(pybind11::module& m)
{
    pybind11::class_<Map>(m, "Map")
        .def(pybind11::init<>())
        .def(pybind11::init<std::size_t, std::size_t, std::size_t>())
        .def("Reset", &Map::Reset)
        .def("GetWidth", &Map::GetWidth)
        .def("GetHeight", &Map::GetHeight)
        .def("GetStartPoint", &Map::GetStartPoint)
        .def("GetInitMoveCount", &Map::GetInitMoveCount)
        .def("GetLurker", &Map::GetLurker)
        .def("SetLurker", &Map::SetLurker)
        .def("CheckUndead", &Map::CheckUndead)
        .def("IsLurkerAttack", &Map::IsLurkerAttack)
        .def("Load", static_cast<void (Map::*)(std::string_view)>(&Map::Load))
        .def("At",
             static_cast<Object& (Map::*)(std::size_t, std::size_t) const>(
                 &Map::At));
}