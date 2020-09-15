// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <HellSolver/Agents/RandomAgent.hpp>

using namespace HellSolver;

TEST_CASE("[RandomAgent] - Basic")
{
    const Game game(MAPS_DIR "1.txt");

    RandomAgent agent;

    std::vector<Direction> actions = { Direction::UP, Direction::DOWN,
                                       Direction::LEFT, Direction::RIGHT,
                                       Direction::INVALID };

    const Direction action = agent.GetAction(game);

    CHECK_NE(std::find(begin(actions), end(actions), action), end(actions));
}