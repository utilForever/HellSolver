import pyHell
import pyglet
import render
import resources

from pyglet.window import key

level = 3

game = pyHell.Game(f"../../Resources/Maps/Level/{level}.txt")

window = pyglet.window.Window(caption="HellSolver", width=1600, height=900)


@window.event
def on_draw():
    window.clear()
    pyglet.sprite.Sprite(img=resources.background[level - 1]).draw()
    CountDisplay()
    render.render(game, level)


@window.event
def on_key_press(symbol, modifiers):
    result = 0

    if symbol == key.LEFT:
        result = game.MovePlayer(pyHell.Direction.LEFT)
    elif symbol == key.UP:
        result = game.MovePlayer(pyHell.Direction.UP)
    elif symbol == key.DOWN:
        result = game.MovePlayer(pyHell.Direction.DOWN)
    elif symbol == key.RIGHT:
        result = game.MovePlayer(pyHell.Direction.RIGHT)

    if result == pyHell.PlayerStatus.WIN or result == pyHell.PlayerStatus.LOST:
        game.Reset()

    print(result)


def CountDisplay():
    pyglet.text.Label(f'{game.GetPlayer().GetMoveCount()}',
                      font_size=36,
                      x=100, y=100
                      ).draw()


if __name__ == "__main__":
    time_step = 0
    game_over = False

    pyglet.app.run()
