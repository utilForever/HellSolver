//
// Created by flow on 2020-09-11.
//

#include <Games/Object.hpp>
#include <HellSolver/Games/Object.hpp>

using namespace hell_solver;

void AddObject(pybind11::module& m)
{
    pybind11::class_<Object>(m, "Object")
        .def(pybind11::init<>())
        .def(pybind11::init<Tile>())
        .def("Add", static_cast<void (Object::*)(ObjectType)>(&Object::Add))
        .def("Remove",
             static_cast<void (Object::*)(ObjectType)>(&Object::Remove))
        .def("Init", static_cast<void (Object::*)(ObjectType)>(&Object::Init))
        .def("GetTypes", &Object::GetTypes)
        .def("HasType",
             static_cast<bool (Object::*)(ObjectType) const>(&Object::HasType));
}