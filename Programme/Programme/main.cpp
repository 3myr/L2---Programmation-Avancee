//SUPPRIMER LE MAIN DU FICHIER "Test_OpenGL_Install.cpp" POUR EVITER LE CONFLIT


#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML | Tileset"); // Permet d'afficher une fenetre de 200 par 200 pixels

	//sf::CircleShape shape(100.f); // Permet de dessiner un cercle de rayon 100 pixels
	//shape.setFillColor(sf::Color::Green); // Couleur du cercle

	// Taille de la carte
	int map_width = 10;
	int map_height = 10;

	// Variable affichant les textures choisit
	sf::Texture tileset_texture;
	sf::Sprite tileset_sprite;

	// Chargement des texture
	tileset_texture.loadFromFile("Background/tileTest2.png");
	tileset_sprite.setTexture(tileset_texture);

	//Tableau a 2 dimension représentant les differentes position des sprites sur la carte
	int map[] = {
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1,
		2, 1, 0, 8, 1, 2, 1, 0, 8, 1,
		4, 1, 1, 0, 1, 4, 1, 1, 0, 1,
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1,
		2, 1, 0, 8, 1, 2, 1, 0, 8, 1,
		4, 1, 1, 0, 1, 4, 1, 1, 0, 1,
	};

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}



		window.clear(); // Met la fenetre avec les memes pixel ( ecrasement des anciens pixels )

		// A commenter
		for (int y = 0; y < map_height ; ++y)
		{
			for (int x = 0; x < map_width ;  ++x)
			{
				int tilecount = x + y * 10;

				tileset_sprite.setPosition(x * 40.f, y * 40.f); // Position du sprite sur la carte
				tileset_sprite.setTextureRect(sf::IntRect(map[tilecount] * 40 , 0, 40, 40)); // Position de la texture correspondant au sprite dans le fichier PNG

				window.draw(tileset_sprite); // Affiche les sprites avec leur texture
			}
		}



		//window.draw(shape); // Affiche la forme avec sa couleur

		window.display(); // Affiche les pixels
	}
	return 0;
}