//
// Created by flow on 2020-09-10.
//

#include <Games/Game.hpp>

#include <pybind11/pybind11.h>

PYBIND11_MODULE(HellPython, m){
    m.doc() = R"pbdoc(Helltaker simulator with some reinforcement learning)pbdoc"

    AddGame(m);
}
