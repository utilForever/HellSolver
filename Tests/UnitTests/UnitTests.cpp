//
// Created by flow on 2020-09-07.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <HellSolver/Games/Game.hpp>

using namespace hell_solver;

TEST_CASE("MAP 1 - LOADING")
{
Game game(MAPS_DIR "1.txt");

CHECK(game.GetMap().At(1, 1).HasType(ObjectType::WALL));
CHECK(game.GetMap().At(1, 6).HasType(ObjectType::PLAYER));
CHECK(game.GetMap().At(2, 4).HasType(ObjectType::UNDEAD));
CHECK(game.GetMap().At(5, 2).HasType(ObjectType::ROCK));
}

TEST_CASE("TEST - CanMoveTestMap")
{
    Game game(TEST_MAPS_DIR "CanMoveTestMap.txt");

    CHECK(game.GetMap().At(2, 2).HasType(ObjectType::PLAYER));
    CHECK(game.GetMap().At(2, 3).HasType(ObjectType::EMPTY));
    CHECK(game.CanMove(Direction::UP) == MoveState::MOVE);
}