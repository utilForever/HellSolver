// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <HellSolver/Games/Game.hpp>

using namespace HellSolver;

TEST_CASE("[Game] - CanMove")
{
    Game game(TEST_MAPS_DIR "CanMoveTestMap.txt");

    CHECK(game.GetMap().At(2, 3).HasType(ObjectType::EMPTY));

    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().x == 2);
    CHECK(game.GetPlayer().GetPosition().y == 2);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().x == 3);
    CHECK(game.GetPlayer().GetPosition().y == 2);

    CHECK(game.MovePlayer(Direction::LEFT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().x == 2);
    CHECK(game.GetPlayer().GetPosition().y == 2);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetPosition().x == 2);
    CHECK(game.GetPlayer().GetPosition().y == 3);
}

TEST_CASE("[Game] - MinusCount")
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

TEST_CASE("[Game] - IsGameEnd")
{
    Game game(TEST_MAPS_DIR "IsGameEndTest.txt");

    CHECK(game.GetMap().At(1, 1).HasType(ObjectType::PLAYER));
    CHECK(game.GetMap().At(2, 1).HasType(ObjectType::SPIKE));
    CHECK(game.GetPlayer().GetMoveCount() == 10);
    CHECK(game.MovePlayer(Direction::UP) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 10);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.GetPlayer().GetMoveCount() == 8);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::WIN);
}

TEST_CASE("[Game] - Lurker")
{
    Game game(TEST_MAPS_DIR "LurkerTest.txt");

    CHECK(game.GetMap().At(8, 1).HasType(ObjectType::ENDPOINT));
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

TEST_CASE("[Game] - Lock")
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

TEST_CASE("[Game] - UndeadMakeDead")
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

TEST_CASE("[Game] - DancingRock")
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
    CHECK(game.GetMap().At(3, 1).HasType(ObjectType::ROCK));
}

TEST_CASE("[Game] - SlidingUndead")
{
    Game game(TEST_MAPS_DIR "SlidingUndead.txt");

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
}

TEST_CASE("[Game] - UndeadWithLurker")
{
    Game game(TEST_MAPS_DIR "UndeadWithLurker.txt");

    CHECK(game.GetMap().GetWidth() == 5);
    CHECK(game.GetMap().GetHeight() == 5);

    CHECK(game.GetMap().At(3, 1).HasType(ObjectType::LURKER_TYPE));
    CHECK(game.GetMap().At(2, 1).HasType(ObjectType::UNDEAD));
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
}

TEST_CASE("[Game] - UndeadCheckWithLurker")
{
    Game game(TEST_MAPS_DIR "UndeadCheckWithLurker.txt");

    CHECK(game.GetPlayer().GetMoveCount() == 6);

    CHECK(game.GetMap().At(2, 1).HasType(ObjectType::UNDEAD) == true);
    CHECK(game.GetMap().At(3, 1).HasType(ObjectType::UP) == true);
    CHECK(game.GetMap().CanLurkerAttack(game.GetMap().At(3, 1)) ==
          true);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.GetMap().CanLurkerAttack(game.GetMap().At(3, 1)) ==
          false);
    CHECK(game.GetMap().At(2, 1).HasType(ObjectType::UNDEAD) == false);
    CHECK(game.GetMap().At(3, 1).HasType(ObjectType::UNDEAD) == true);
    CHECK(game.MovePlayer(Direction::RIGHT) == PlayerStatus::PLAYING);

    CHECK(game.GetMap().At(3, 1).HasType(ObjectType::UNDEAD) == false);
    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::PLAYING);

    CHECK(game.MovePlayer(Direction::DOWN) == PlayerStatus::WIN);
}