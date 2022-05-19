
LIBFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
all:
	g++ -Isrc/include -Lsrc/lib -c main.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c game/botton.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c game/draw.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c game/gameplay.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c game/mouse.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c game/move.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c game/LoadImage.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c game/sound.cpp $(LIBFLAGS)
	g++ -Isrc/include -Lsrc/lib -c save/player.cpp $(LIBFLAGS)
	
	g++ -Isrc/include -Lsrc/lib main.o botton.o draw.o gameplay.o mouse.o move.o LoadImage.o sound.o player.o -o main $(LIBFLAGS)