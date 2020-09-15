// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "doctest_proxy.hpp"

#include <HellSolver/Games/Game.hpp>

using namespace HellSolver;

TEST_CASE("[Map] - 1")
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

TEST_CASE("[Map] - 2")
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

TEST_CASE("[Map] - 3")
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

TEST_CASE("[Map] - 4")
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

TEST_CASE("[Map] - 5")
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

TEST_CASE("[Map] - 6")
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

TEST_CASE("[Map] - 7")
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

TEST_CASE("[Map] - 8")
{
    Game game(MAPS_DIR "8.txt");

    CHECK(game.GetMap().GetWidth() == 11);
    CHECK(game.GetMap().GetHeight() == 14);
    CHECK(game.GetPlayer().GetMoveCount() == 12);
    CHECK(game.GetMap().At(2, 5).HasType(ObjectType::UNDEAD));
    CHECK(game.GetMap().At(2, 5).GetTile().second == ObjectType::ENDPOINT);

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

TEST_CASE("[Map] - 9")
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