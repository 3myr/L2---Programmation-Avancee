CC = g++
CFLAGS = -W -Wall
LDFLAGS =
EXEC = rpg-app
SRC = main.cpp
DEPS = Vaisseau.cpp Player.cpp Enemi.cpp Projectile.cpp Background.cpp View.cpp Level.cpp Atq1.cpp Menu.cpp MainMenu.cpp Manage.cpp PauseMenu.cpp Interface.cpp Couche.cpp#Attaque.cpp
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
