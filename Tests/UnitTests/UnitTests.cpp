// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <HellSolver/Games/Game.hpp>
#include <iostream>

using namespace hell_solver;

TEST_CASE("MAP 1 - SOLUTION")
{
    Game game(MAPS_DIR "1.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::WALL));
    CHECK(game.GetMap().At(1, 6).HasType(ObjectType::PLAYER));
    CHECK(game.GetMap().At(2, 4).HasType(ObjectType::UNDEAD));
    CHECK(game.GetMap().At(5, 2).HasType(ObjectType::ROCK));
    CHECK(game.GetMap().At(6, 6).HasType(ObjectType::ENDPOINT));
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::WIN);
}

TEST_CASE("MAP 2 - SOLUTION")
{
    Game game(MAPS_DIR "2.txt");

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
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

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().first == 3);
    CHECK(game.GetPlayer().GetPosition().second == 2);
}

TEST_CASE("TEST - IsGameEndTest")
{
    Game game(TEST_MAPS_DIR "IsGameEndTest.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::PLAYER));
    CHECK(game.GetMap().At(1, 2).HasType(ObjectType::SPIKE));
    CHECK(game.GetPlayer().GetMoveCount() == 10);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 10);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 8);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::WIN);
}

TEST_CASE("TEST - LurkerTest")
{
    Game game(TEST_MAPS_DIR "LurkerTest.txt");

    CHECK(game.GetMap().At(1, 8).HasType(ObjectType::ENDPOINT));
    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::PLAYER));
    CHECK(game.GetPlayer().GetMoveCount() == 9);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 8);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 6);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 4);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 3);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 2);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 1);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::WIN);
}

TEST_CASE("TEST - LockTest")
{
    Game game(TEST_MAPS_DIR "LockTest.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::KEY));
    CHECK(game.GetPlayer().GetMoveCount() == 8);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 7);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 6);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 5);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().HasKey() == true);
    CHECK(game.GetPlayer().GetMoveCount() == 4);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 3);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 2);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 1);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::WIN);
    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("TEST - UndeadMakeDead")
{
    Game game(TEST_MAPS_DIR "UndeadMakeDead.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::PLAYER));
    CHECK(game.GetPlayer().GetMoveCount() == 4);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 2);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::WIN);
    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("TEST - DancingRock")
{
    Game game(TEST_MAPS_DIR "DancingRock.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::PLAYER));
    CHECK(game.GetPlayer().GetMoveCount() == 4);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 2);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
    CHECK(game.GetPlayer().GetMoveCount() == 0);
    CHECK(game.GetMap().At(1, 3).HasType(ObjectType::ROCK));
}

TEST_CASE("TEST - SlidingUndead")
{
    Game game(TEST_MAPS_DIR "SlidingUndead.txt");

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::LOST);
}
