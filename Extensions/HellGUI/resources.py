import pyglet

background = [pyglet.image.load('assets/background1.png'),
              pyglet.image.load('assets/background2.png'),
              pyglet.image.load('assets/background3.png'),
              pyglet.image.load('assets/background4.png'),
              pyglet.image.load('assets/background5.png'),
              pyglet.image.load('assets/background6.png'),
              pyglet.image.load('assets/background7.png'),
              ]

rock_image = pyglet.image.load('assets/rock.png')
rock_image.anchor_y = 60

character_image = pyglet.image.load('assets/player.png')
character_image.anchor_y = 60

devil_image = pyglet.image.load('assets/devil.png')
devil_image.anchor_y = -10

spike_image = pyglet.image.load('assets/spike.png')
spike_image.anchor_y = 60

undead_image = pyglet.image.load('assets/undead.png')
undead_image.anchor_y = 60

key_image = pyglet.image.load('assets/key.png')
key_image.anchor_y = 60

up_image = pyglet.image.load('assets/spike.png')
up_image.anchor_y = 60

down_image = pyglet.image.load('assets/down.png')
down_image.anchor_y = 60

lock_image = pyglet.image.load('assets/lock.png')
