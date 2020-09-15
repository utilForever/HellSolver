// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <HellSolver/Agents/RandomAgent.hpp>
#include <HellSolver/Games/Game.hpp>
#include <iostream>

using namespace HellSolver;

TEST_CASE("MAP 1 - SOLUTION")
{
    Game game(MAPS_DIR "1.txt");

    CHECK(game.GetMap().GetWidth() == 9);
    CHECK(game.GetMap().GetHeight() == 8);

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::WALL));
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

    CHECK(game.GetPlayer().GetMoveCount() == 0);

    game.Reset();
    CHECK(game.GetPlayer().GetMoveCount() == 23);
    CHECK(game.MovePlayer(Direction::INVALID) == PlayerStatus::PLAYING);
}

TEST_CASE("MAP 2 - SOLUTION")
{
    Game game(MAPS_DIR "2.txt");

    CHECK(game.GetMap().GetWidth() == 9);
    CHECK(game.GetMap().GetHeight() == 8);

    CHECK(game.GetMap().At(2, 2).HasType(ObjectType::UNDEAD));
    CHECK(game.GetMap().At(2, 4).HasType(ObjectType::SPIKE));
    CHECK(game.GetMap().At(6, 5).HasType(ObjectType::ENDPOINT));
    CHECK(game.GetPlayer().GetMoveCount() == 24);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 20);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 18);

    CHECK(game.GetMap().At(1, 2).HasType(ObjectType::UNDEAD));

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetMap().At(1, 2).HasType(ObjectType::UNDEAD));
    CHECK(game.GetPlayer().GetMoveCount() == 17);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 16);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 15);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.GetMap().At(2, 5).HasType(ObjectType::SPIKE));
    CHECK(game.GetPlayer().GetMoveCount() == 10);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("MAP 3 - SOLUTION")
{
    Game game(MAPS_DIR "3.txt");

    CHECK(game.GetMap().GetWidth() == 10);
    CHECK(game.GetMap().GetHeight() == 9);
    CHECK(game.GetPlayer().GetMoveCount() == 32);
    CHECK(game.GetMap().At(1, 7).HasType(ObjectType::ENDPOINT));
    CHECK(game.GetMap().At(2, 7).HasType(ObjectType::LOCK));

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::WIN);

    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("MAP 4 - SOLUTION")
{
    Game game(MAPS_DIR "4.txt");

    CHECK(game.GetMap().GetWidth() == 10);
    CHECK(game.GetMap().GetHeight() == 7);
    CHECK(game.GetPlayer().GetMoveCount() == 23);
    CHECK(game.GetMap().At(3, 7).HasType(ObjectType::ENDPOINT));
    CHECK(game.GetMap().At(2, 6).HasType(ObjectType::LOCK));

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);

    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("MAP 5 - SOLUTION")
{
    Game game(MAPS_DIR "5.txt");

    CHECK(game.GetMap().GetWidth() == 8);
    CHECK(game.GetMap().GetHeight() == 9);
    CHECK(game.GetPlayer().GetMoveCount() == 23);
    CHECK(game.GetMap().At(1, 5).HasType(ObjectType::ENDPOINT));
    CHECK(game.GetMap().At(2, 4).HasType(ObjectType::LOCK));
    CHECK(game.GetMap().At(5, 1).HasType(ObjectType::UNDEAD));

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetMap().At(6, 1).HasType(ObjectType::UNDEAD));

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 19);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.GetPlayer().HasKey());

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::WIN);

    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("MAP 6 - SOLUTION")
{
    Game game(MAPS_DIR "6.txt");

    CHECK(game.GetMap().GetWidth() == 9);
    CHECK(game.GetMap().GetHeight() == 10);
    CHECK(game.GetPlayer().GetMoveCount() == 43);
    CHECK(game.GetMap().At(8, 6).HasType(ObjectType::ENDPOINT));

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 32);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 24);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 22);
    CHECK(game.GetPlayer().HasKey());

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 16);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 13);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);

    CHECK(game.GetPlayer().GetMoveCount() == 1);
}

TEST_CASE("MAP 7 - SOLUTION")
{
    Game game(MAPS_DIR "7.txt");

    CHECK(game.GetMap().GetWidth() == 8);
    CHECK(game.GetMap().GetHeight() == 9);
    CHECK(game.GetPlayer().GetMoveCount() == 32);
    CHECK(game.GetMap().At(1, 5).HasType(ObjectType::ENDPOINT));

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 29);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 25);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 21);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 18);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 14);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().HasKey());
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 8);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 4);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::WIN);

    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("MAP 8 - SOLUTION")
{
    Game game(MAPS_DIR "8.txt");

    CHECK(game.GetMap().GetWidth() == 11);
    CHECK(game.GetMap().GetHeight() == 14);
    CHECK(game.GetPlayer().GetMoveCount() == 12);
    CHECK(game.GetMap().At(2, 5).HasType(ObjectType::UNDEAD));
    CHECK(game.GetMap().At(2, 5).GetTypes().second == ObjectType::ENDPOINT);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 2);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::WIN);

    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("MAP 9 - SOLUTION")
{
    Game game(MAPS_DIR "9.txt");

    CHECK(game.GetMap().GetWidth() == 11);
    CHECK(game.GetMap().GetHeight() == 8);
    CHECK(game.GetPlayer().GetMoveCount() == 33);
    CHECK(game.GetMap().At(0, 5).HasType(ObjectType::ENDPOINT));

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 30);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 26);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 22);

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 15);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 8);
    CHECK(game.GetPlayer().HasKey());

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 5);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::WIN);

    CHECK(game.GetPlayer().GetMoveCount() == 0);
}

TEST_CASE("TEST - CanMoveTestMap")
{
    Game game(TEST_MAPS_DIR "CanMoveTestMap.txt");

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

TEST_CASE("TEST - MinusCount")
{
    Game game(TEST_MAPS_DIR "CanMoveTestMap.txt");

    CHECK(game.GetMap().At(2, 3).HasType(ObjectType::EMPTY));

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::LOST);
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
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
}

TEST_CASE("TEST - UndeadWithLurker")
{
    Game game(TEST_MAPS_DIR "UndeadWithLurker.txt");

    CHECK(game.GetMap().GetWidth() == 5);
    CHECK(game.GetMap().GetHeight() == 5);

    CHECK(game.GetMap().At(1, 3).HasType(ObjectType::LURKER_TYPE));
    CHECK(game.GetMap().At(1, 2).HasType(ObjectType::UNDEAD));
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
}

TEST_CASE("TEST - UndeadCheckWithLurker")
{
    Game game(TEST_MAPS_DIR "UndeadCheckWithLurker.txt");

    CHECK(game.GetPlayer().GetMoveCount() == 6);

    CHECK(game.GetMap().At(1, 2).HasType(ObjectType::UNDEAD) == true);
    CHECK(game.GetMap().At(1, 3).HasType(ObjectType::UP) == true);
    CHECK(game.GetMap().CanLurkerAttackThisMove(game.GetMap().At(1, 3)) ==
          true);
    CHECK(game.GetMap().CanLurkerAttackNextMove(game.GetMap().At(1, 3)) ==
          false);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.GetMap().CanLurkerAttackThisMove(game.GetMap().At(1, 3)) ==
          false);
    CHECK(game.GetMap().At(1, 2).HasType(ObjectType::UNDEAD) == false);
    CHECK(game.GetMap().At(1, 3).HasType(ObjectType::UNDEAD) == true);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.GetMap().At(1, 3).HasType(ObjectType::UNDEAD) == false);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
}

TEST_CASE("RandomAgent - Basic")
{
    Game game(MAPS_DIR "1.txt");

    RandomAgent agent;

    std::vector<Direction> actions = { Direction::UP, Direction::DOWN,
                                       Direction::LEFT, Direction::RIGHT,
                                       Direction::INVALID };

    const Direction action = agent.GetAction(game);

    CHECK_NE(std::find(begin(actions), end(actions), action), end(actions));
}