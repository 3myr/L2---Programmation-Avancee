CC = g++
CFLAGS = -W -Wall
LDFLAGS =
EXEC = rpg-app
SRC = main.cpp
DEPS = Map.cpp Animation.cpp Player.cpp Monster.cpp Camera.cpp Collide.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ = $(SRC: .cpp=.o)

main: $(OBJ)
	clear
	$(CC) -c $(DEPS) $(SRC)
	$(CC) $(OBJ) -o $(EXEC) $(LIBS)

clean:
	rm -rf *.o *~
	clear

mrproper:
	cleanrm -rf $(EXEC)
