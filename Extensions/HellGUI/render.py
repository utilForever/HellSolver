import pyHell
import pyglet
import resources

offset = [(510, -60), (510, -60), (460, -120)]

def render(game: pyHell.Game, level: int):
    map = game.GetMap()

    def drawer(img, x, y):
        return pyglet.sprite.Sprite(img=img, x=y * 100 + offset[level - 1][0], y=map.GetWidth() * 100 - x * 100 + offset[level - 1][1])

    for _x in range(map.GetHeight()):
        for _y in range(map.GetWidth()):
            if map.At(_x, _y).HasType(pyHell.ObjectType.SPIKE):
                spike = drawer(resources.spike_image, _x, _y)
                spike.draw()

            if (map.At(_x, _y).HasType(pyHell.ObjectType.UP) and map.GetLurker()) or \
                    (map.At(_x, _y).HasType(pyHell.ObjectType.DOWN) and not map.GetLurker()):
                lurker = drawer(resources.spike_image, _x, _y)
                lurker.draw()
            elif (map.At(_x, _y).HasType(pyHell.ObjectType.UP) and not map.GetLurker()) or \
                    (map.At(_x, _y).HasType(pyHell.ObjectType.DOWN) and map.GetLurker()):
                lurker = drawer(resources.down_image, _x, _y)
                lurker.draw()

            if map.At(_x, _y).HasType(pyHell.ObjectType.ROCK):
                rock = drawer(resources.rock_image, _x, _y)
                rock.draw()

            if map.At(_x, _y).HasType(pyHell.ObjectType.KEY):
                key = drawer(resources.key_image, _x, _y)
                key.draw()

            if map.At(_x, _y).HasType(pyHell.ObjectType.DEVIL):
                devil = drawer(resources.devil_image, _x, _y)
                devil.draw()

            if map.At(_x, _y).HasType(pyHell.ObjectType.UNDEAD):
                undead = drawer(resources.undead_image, _x, _y)
                undead.draw()

            if map.At(_x, _y).HasType(pyHell.ObjectType.LOCK):
                lock = drawer(resources.lock_image, _x, _y)
                lock.draw()

    player = drawer(resources.character_image, game.GetPlayer().GetPosition()[0], game.GetPlayer().GetPosition()[1])
    player.draw()
