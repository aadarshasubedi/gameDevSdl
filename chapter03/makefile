CC=clang++
CFLAGS=-Wall -std=c++11 -std=gnu++11
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
LDFLAGS=-lSDL2 -lSDL2_image
SOURCES=TextureManager.cpp Game.cpp Player.cpp Enemy.cpp SDLGameObject.cpp main.cpp
EXECUTABLE=run

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)
# g++ -Wall YOURFILENAME.cpp -o SDL_Test -lSDL2
