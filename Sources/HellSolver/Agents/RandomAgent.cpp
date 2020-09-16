// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <HellSolver/Agents/RandomAgent.hpp>

#include <effolkronium/random.hpp>

namespace HellSolver
{
Direction RandomAgent::GetAction([[maybe_unused]] const Game& state)
{
    using Random = effolkronium::random_static;

    return static_cast<Direction>(
        Random::get(0, static_cast<int>(Direction::RIGHT)));
}
}  // namespace HellSolver