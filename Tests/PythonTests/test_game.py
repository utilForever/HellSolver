import pyHell

def test_map1():
    game = pyHell.Game("Resources/Maps/Level/1.txt")

    assert game.GetMap().GetWidth() == 9
    assert game.GetMap().GetHeight() == 8

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.WALL)
    assert game.GetMap().At(2, 4).HasType(pyHell.ObjectType.UNDEAD)
    assert game.GetMap().At(5, 2).HasType(pyHell.ObjectType.ROCK)
    assert game.GetMap().At(6, 6).HasType(pyHell.ObjectType.ENDPOINT)

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 0

    game.Reset()
    assert game.GetPlayer().GetMoveCount() == 23

def test_map2():
    game = pyHell.Game("Resources/Maps/Level/2.txt")

    assert game.GetMap().GetWidth() == 9
    assert game.GetMap().GetHeight() == 8

    assert game.GetMap().At(2, 2).HasType(pyHell.ObjectType.UNDEAD)
    assert game.GetMap().At(2, 4).HasType(pyHell.ObjectType.SPIKE)
    assert game.GetMap().At(6, 5).HasType(pyHell.ObjectType.ENDPOINT)
    assert game.GetPlayer().GetMoveCount() == 24

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 20

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 18

    assert game.GetMap().At(1, 2).HasType(pyHell.ObjectType.UNDEAD)

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetMap().At(1, 2).HasType(pyHell.ObjectType.UNDEAD)
    assert game.GetPlayer().GetMoveCount() == 17

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 16

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 15

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.GetMap().At(2, 5).HasType(pyHell.ObjectType.SPIKE)
    assert game.GetPlayer().GetMoveCount() == 10

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN
    assert game.GetPlayer().GetMoveCount() == 0

def test_map3():
    game = pyHell.Game("Resources/Maps/Level/3.txt")

    assert game.GetMap().GetWidth() == 10
    assert game.GetMap().GetHeight() == 9
    assert game.GetPlayer().GetMoveCount() == 32
    assert game.GetMap().At(1, 7).HasType(pyHell.ObjectType.ENDPOINT)
    assert game.GetMap().At(2, 7).HasType(pyHell.ObjectType.LOCK)

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 0

def test_map4():
    game = pyHell.Game("Resources/Maps/Level/4.txt")

    assert game.GetMap().GetWidth() == 10
    assert game.GetMap().GetHeight() == 7
    assert game.GetPlayer().GetMoveCount() == 23
    assert game.GetMap().At(3, 7).HasType(pyHell.ObjectType.ENDPOINT)
    assert game.GetMap().At(2, 6).HasType(pyHell.ObjectType.LOCK)

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 0

def test_map5():
    game = pyHell.Game("Resources/Maps/Level/5.txt")

    assert game.GetMap().GetWidth() == 8
    assert game.GetMap().GetHeight() == 9
    assert game.GetPlayer().GetMoveCount() == 23
    assert game.GetMap().At(1, 5).HasType(pyHell.ObjectType.ENDPOINT)
    assert game.GetMap().At(2, 4).HasType(pyHell.ObjectType.LOCK)
    assert game.GetMap().At(5, 1).HasType(pyHell.ObjectType.UNDEAD)

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetMap().At(6, 1).HasType(pyHell.ObjectType.UNDEAD)

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 19

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.GetPlayer().HasKey()

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 0

def test_map6():
    game = pyHell.Game("Resources/Maps/Level/6.txt")

    assert game.GetMap().GetWidth() == 9
    assert game.GetMap().GetHeight() == 10
    assert game.GetPlayer().GetMoveCount() == 43
    assert game.GetMap().At(8, 6).HasType(pyHell.ObjectType.ENDPOINT)

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 32

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 24

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 22
    assert game.GetPlayer().HasKey()

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 16

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 13

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 1

def test_map7():
    game = pyHell.Game("Resources/Maps/Level/7.txt")

    assert game.GetMap().GetWidth() == 8
    assert game.GetMap().GetHeight() == 9
    assert game.GetPlayer().GetMoveCount() == 32
    assert game.GetMap().At(1, 5).HasType(pyHell.ObjectType.ENDPOINT)

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 29

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 25

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 21

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 18

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 14

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().HasKey()
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 8

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 4

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 0

def test_map8():
    game = pyHell.Game("Resources/Maps/Level/8.txt")

    assert game.GetMap().GetWidth() == 11
    assert game.GetMap().GetHeight() == 14
    assert game.GetPlayer().GetMoveCount() == 12
    assert game.GetMap().At(2, 5).HasType(pyHell.ObjectType.UNDEAD)
    assert game.GetMap().At(2, 5).GetTypes()[1] == pyHell.ObjectType.ENDPOINT

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 0

def test_map9():
    game = pyHell.Game("Resources/Maps/Level/9.txt")

    assert game.GetMap().GetWidth() == 11
    assert game.GetMap().GetHeight() == 8
    assert game.GetPlayer().GetMoveCount() == 33
    assert game.GetMap().At(0, 5).HasType(pyHell.ObjectType.ENDPOINT)

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 30

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 26

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 22

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 15

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 8
    assert game.GetPlayer().HasKey()

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 5
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.WIN

    assert game.GetPlayer().GetMoveCount() == 0

if __name__ == "__main__":
    test_map1()
    test_map2()
    test_map3()
    test_map4()
    test_map5()
    test_map6()
    test_map7()
    test_map8()
    test_map9()
