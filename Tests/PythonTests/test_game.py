import pyHell

def test_canMoveTestMap():
    game = pyHell.Game("Resources/Maps/1.txt")

    assert game.GetMap().At(2, 2).HasType(pyHell.ObjectType.PLAYER)
    assert game.GetMap().At(2, 3).HasType(pyHell.ObjectType.EMPTY);

    assert game.MovePlayer(pyHell.Direction.UP) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition().first == 2
    assert game.GetPlayer().GetPosition().second == 2

    assert game.MovePlayer(pyHell.Direction.RIGHT) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition().first == 2
    assert game.GetPlayer().GetPosition().second == 3

    assert game.MovePlayer(pyHell.Direction.LEFT) == pyHell.PlayerStatus.PLAYING;
    assert game.GetPlayer().GetPosition().first == 2
    assert game.GetPlayer().GetPosition().second == 2

    assert game.MovePlayer(pyHell.Direction.DOWN) == pyHell.PlayerStatus.PLAYING
    assert game.GetPlayer().GetPosition().first == 3
    assert game.GetPlayer().GetPosition().second == 2