import pyHell
import pyglet
import config
import render
import resources

from pyglet.window import key

level = 1

game = pyHell.Game(f"../../Resources/Maps/Level/{level}.txt")
(width, height) = (game.GetMap().GetWidth() * config.BLOCK_SIZE,
                   game.GetMap().GetHeight() * config.BLOCK_SIZE)


def CountDisplay(game):
    pyglet.text.Label(f'{game.GetPlayer().GetMoveCount()}',
                      font_size=36,
                      x=100, y=100
                      ).draw()


class pyHellWindow(pyglet.window.Window):
    def __init__(self):
        super(pyHellWindow, self).__init__(caption="pyglet example", width=1920, height=1080)

    def on_draw(self):
        self.clear()
        background = pyglet.sprite.Sprite(img=resources.background[level - 1])
        background.draw()
        render.render(game, level)
        CountDisplay(game)

    def on_key_press(self, symbol, modifiers):
        if symbol == key.LEFT:
            result = game.MovePlayer(pyHell.Direction.LEFT)
        elif symbol == key.UP:
            result = game.MovePlayer(pyHell.Direction.UP)
        elif symbol == key.DOWN:
            result = game.MovePlayer(pyHell.Direction.DOWN)
        elif symbol == key.RIGHT:
            result = game.MovePlayer(pyHell.Direction.RIGHT)

        render.render(game, level)
        pyglet.text.Label(f'{game.GetPlayer().GetMoveCount()}', x=window.width // 2, y=window.height // 2).draw()
        CountDisplay(game)

        print(result);


if __name__ == "__main__":
    window = pyHellWindow()

    time_step = 0
    game_over = False

    pyglet.app.run()
