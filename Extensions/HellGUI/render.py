import pyHell
import pyglet
import resources

offset = [(510, -60), (510, -60), (460, -120)]


def render(game: pyHell.Game, level: int):
    game_map = game.GetMap()

    def drawer(img, x, y):
        return pyglet.sprite.Sprite(img=img, x=y * 100 + offset[level - 1][0],
                                    y=game_map.GetWidth() * 100 - x * 100 + offset[level - 1][1])

    for _x in range(game_map.GetHeight()):
        for _y in range(game_map.GetWidth()):
            if game_map.At(_x, _y).HasType(pyHell.ObjectType.SPIKE):
                spike = drawer(resources.spike_image, _x, _y)
                spike.draw()

            if (game_map.At(_x, _y).HasType(pyHell.ObjectType.UP) and game_map.GetLurker()) or \
                    (game_map.At(_x, _y).HasType(pyHell.ObjectType.DOWN) and not game_map.GetLurker()):
                lurker = drawer(resources.spike_image, _x, _y)
                lurker.draw()
            elif (game_map.At(_x, _y).HasType(pyHell.ObjectType.UP) and not game_map.GetLurker()) or \
                    (game_map.At(_x, _y).HasType(pyHell.ObjectType.DOWN) and game_map.GetLurker()):
                lurker = drawer(resources.down_image, _x, _y)
                lurker.draw()

            if game_map.At(_x, _y).HasType(pyHell.ObjectType.ROCK):
                rock = drawer(resources.rock_image, _x, _y)
                rock.draw()

            if game_map.At(_x, _y).HasType(pyHell.ObjectType.KEY):
                key = drawer(resources.key_image, _x, _y)
                key.draw()

            if game_map.At(_x, _y).HasType(pyHell.ObjectType.DEVIL):
                devil = drawer(resources.devil_image, _x, _y)
                devil.draw()

            if game_map.At(_x, _y).HasType(pyHell.ObjectType.UNDEAD):
                undead = drawer(resources.undead_image, _x, _y)
                undead.draw()

            if game_map.At(_x, _y).HasType(pyHell.ObjectType.LOCK):
                lock = drawer(resources.lock_image, _x, _y)
                lock.draw()

    player = drawer(resources.character_image, game.GetPlayer().GetPosition()[0], game.GetPlayer().GetPosition()[1])
    player.draw()
