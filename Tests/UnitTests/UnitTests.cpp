//
// Created by flow on 2020-09-07.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

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

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().first == 2);
    CHECK(game.GetPlayer().GetPosition().second == 2);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().first == 2);
    CHECK(game.GetPlayer().GetPosition().second == 3);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().first == 2);
    CHECK(game.GetPlayer().GetPosition().second == 2);

    CHECK(game. MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().first == 3);
    CHECK(game.GetPlayer().GetPosition().second == 2);
}

TEST_CASE("TEST - IsGameEndTest")
{
    Game game(TEST_MAPS_DIR "IsGameEndTest.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::PLAYER));
    CHECK(game.GetPlayer().GetMoveCount() == 10);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 10);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 8);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::WIN);
}