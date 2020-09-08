#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <HellSolver/Games/Game.hpp>
#include <HellSolver/Test/Test.hpp>

using namespace hell_solver;

TEST_CASE("Simple Test")
{
    CHECK(Add(2, 3) == 5);
}

TEST_CASE("MAP 1 - LOADING")
{
    Game game(MAPS_DIR "1.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::WALL));
    CHECK(game.GetMap().At(6, 1).HasType(ObjectType::PLAYER));
    CHECK(game.GetMap().At(4, 2).HasType(ObjectType::UNDEAD));
    CHECK(game.GetMap().At(2, 5).HasType(ObjectType::ROCK));
}