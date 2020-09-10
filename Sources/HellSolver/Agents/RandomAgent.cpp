//
// Created by flow on 2020-09-10.
//

#include <HellSolver/Agents/RandomAgent.hpp>

#include <effolkronium/random.hpp>

namespace hell_solver
{
Direction RandomAgent::GetAction([[maybe_unused]] const Game& state)
{
    using Random = effolkronium::random_static;

    return static_cast<Direction>(
        Random::get(0, static_cast<int>(Direction::RIGHT)));
}
}  // namespace hell_solver