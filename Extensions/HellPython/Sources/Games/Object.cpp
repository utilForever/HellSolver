// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Games/Object.hpp>
#include <HellSolver/Games/Object.hpp>

using namespace HellSolver;

void AddObject(pybind11::module& m)
{
    pybind11::class_<Object>(m, "Object")
        .def(pybind11::init<>())
        .def(pybind11::init<Tile>())
        .def("Add", static_cast<void (Object::*)(ObjectType)>(&Object::Add))
        .def("Remove",
             static_cast<void (Object::*)(ObjectType)>(&Object::Remove))
        .def("Init", static_cast<void (Object::*)(ObjectType)>(&Object::Init))
        .def("GetTile", &Object::GetTile)
        .def("HasType",
             static_cast<bool (Object::*)(ObjectType) const>(&Object::HasType));
}