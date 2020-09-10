import pyHell

def isGameEndTest():
    game = pyHell.Game("Resources/Map/Test/IsGameEndTest.txt")

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetMap().At(1, 2).HasType(pyHell.ObjectType.SPIKE)
    assert game.GetPlayer().GetMoveCount() == 10
    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 10
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 8
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN

def canMoveTestMap():
    game = pyHell.Game("Resources/Maps/Test/CanMoveTestMap.txt")

    assert game.GetMap().At(2, 2).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetMap().At(2, 3).HasType(pyHell.ObjectType.EMPTY)

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition() == (2, 2)

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition() == (2, 3)

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition() == (2, 2)

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition() == (3, 2)

def lurkerTest():
    game = pyHell.Game("Resources/Maps/Test/LurkerTest.txt")

    assert game.GetMap().At(1, 8).HasType(pyHell.ObjectType.ENDPOINT)
    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetPlayer().GetMoveCount() == 9
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 8
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 6
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 3
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 1
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN


def lockTest():
    game = pyHell.Game("Resources/Maps/Test/LockTest.txt")

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.KEY)
    assert game.GetPlayer().GetMoveCount() == 8
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 7
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 6
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 5
    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().HasKey() == True
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 3
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 1
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN
    assert game.GetPlayer().GetMoveCount() == 0


def undeadMakeDead():
    game = pyHell.Game("Resources/Maps/Test/UndeadMakeDead.txt")

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.WIN
    assert game.GetPlayer().GetMoveCount() == 0


def dancingRock():
    game = pyHell.Game("Resources/Maps/Test/DancingRock.txt")

    assert game.GetMap().At(1, 1).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetPlayer().GetMoveCount() == 4
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetMoveCount() == 2
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN
    assert game.GetPlayer().GetMoveCount() == 0
    assert game.GetMap().At(1, 3).HasType(pyHell.ObjectType.ROCK)


def slidingUndead():
    game = pyHell.Game("Resources/Maps/Test/SlidingUndead.txt")

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN


def undeadWithLurker():
    game = pyHell.Game("Resources/Maps/Test/UndeadWithLurker.txt")

    assert game.GetMap().GetWidth() == 5
    assert game.GetMap().GetHeight() == 5

    assert game.GetMap().At(1, 2).HasType(pyHell.ObjectType.UNDEAD)
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN


def undeadCheckWithLurker():
    game = pyHell.Game("Resources/Maps/Test/UndeadCheckWithLurker.txt")

    assert game.GetPlayer().GetMoveCount() == 6

    assert game.GetMap().At(1, 2).HasType(pyHell.ObjectType.UNDEAD) == True
    assert game.GetMap().At(1, 3).HasType(pyHell.ObjectType.UP) == True
    assert game.GetMap().IsLurkerAttack(game.GetMap().At(1, 3)) == True
    assert game.GetMap().IsLurkerNextAttack(game.GetMap().At(1, 3)) == False
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.GetMap().IsLurkerAttack(game.GetMap().At(1, 3)) == False
    assert game.GetMap().At(1, 2).HasType(pyHell.ObjectType.UNDEAD) == False
    assert game.GetMap().At(1, 3).HasType(pyHell.ObjectType.UNDEAD) == True
    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING

    assert game.GetMap().At(1, 3).HasType(pyHell.ObjectType.UNDEAD) == False
    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.WIN


if __name__ == "__main__":
    isGameEndTest()
    canMoveTestMap()
    lurkerTest()
    lockTest()
    undeadMakeDead()
    dancingRock()
    slidingUndead()
    undeadWithLurker()
    undeadCheckWithLurker()
