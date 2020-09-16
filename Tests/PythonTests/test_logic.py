import pyHell


def test_can_move():
    game = pyHell.Game("Resources/Maps/Test/CanMoveTestMap.txt")

    assert game.GetMap().At(3, 2).HasType(pyHell.ObjectType.EMPTY)

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition().x == 2
    assert game.GetPlayer().GetPosition().y == 2

    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition().x == 3
    assert game.GetPlayer().GetPosition().y == 2

    assert game.MovePlayer(
        pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition().x == 2
    assert game.GetPlayer().GetPosition().y == 2

    assert game.MovePlayer(
        pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition().x == 2
    assert game.GetPlayer().GetPosition().y == 3


def test_minus_count():
    game = pyHell.Game("Resources/Maps/Test/CanMoveTestMap.txt")

    assert game.GetMap().At(3, 2).HasType(pyHell.ObjectType.EMPTY)

    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.LOST


def test_is_game_end():
    game = pyHell.Game("Resources/Maps/Test/IsGameEndTest.txt")

    assert game.GetMap().At(2, 1).HasType(pyHell.ObjectType.SPIKE)
    assert game.GetPlayer().GetMoveCount() == 10
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 10
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 8
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN


def test_lurker():
    game = pyHell.Game("Resources/Maps/Test/LurkerTest.txt")

    assert game.GetMap().At(8, 1).HasType(pyHell.ObjectType.ENDPOINT)
    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetPlayer().GetMoveCount() == 9
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 8
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 6
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 3
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 1
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN


def test_lock():
    game = pyHell.Game("Resources/Maps/Test/LockTest.txt")

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.KEY)
    assert game.GetPlayer().GetMoveCount() == 8
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 7
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 6
    assert game.MovePlayer(
        pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 5
    assert game.MovePlayer(
        pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().HasKey() is True
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 3
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 1
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN
    assert game.GetPlayer().GetMoveCount() == 0


def test_undead_mark_dead():
    game = pyHell.Game("Resources/Maps/Test/UndeadMakeDead.txt")

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(
        pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN
    assert game.GetPlayer().GetMoveCount() == 0


def test_dancing_rock():
    game = pyHell.Game("Resources/Maps/Test/DancingRock.txt")

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(
        pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN
    assert game.GetPlayer().GetMoveCount() == 0
    assert game.GetMap().At(3, 1).HasType(pyHell.ObjectType.ROCK)


def test_sliding_undead():
    game = pyHell.Game("Resources/Maps/Test/SlidingUndead.txt")

    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN


def test_undead_with_lurker():
    game = pyHell.Game("Resources/Maps/Test/UndeadWithLurker.txt")

    assert game.GetMap().GetWidth() == 5
    assert game.GetMap().GetHeight() == 5

    assert game.GetMap().At(2, 1).HasType(pyHell.ObjectType.UNDEAD)
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(
        pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN


def test_undead_check_with_lurker():
    game = pyHell.Game("Resources/Maps/Test/UndeadCheckWithLurker.txt")

    assert game.GetPlayer().GetMoveCount() == 6

    assert game.GetMap().At(2, 1).HasType(pyHell.ObjectType.UNDEAD) is True
    assert game.GetMap().At(3, 1).HasType(pyHell.ObjectType.UP) is True
    assert game.GetMap().CanLurkerAttackThisMove(game.GetMap().At(3, 1)) is True
    assert game.GetMap().CanLurkerAttackNextMove(game.GetMap().At(3, 1)) is False
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.GetMap().CanLurkerAttackThisMove(game.GetMap().At(3, 1)) is False
    assert game.GetMap().At(2, 1).HasType(pyHell.ObjectType.UNDEAD) is False
    assert game.GetMap().At(3, 1).HasType(pyHell.ObjectType.UNDEAD) is True
    assert game.MovePlayer(
        pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.GetMap().At(3, 1).HasType(pyHell.ObjectType.UNDEAD) is False
    assert game.MovePlayer(
        pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN
