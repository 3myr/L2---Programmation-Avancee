#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML | Tileset"); // Permet d'afficher une fenetre de 1280 par 720 pixels

	// Taille de la carte
	int map_width = 26; // reel 26
	int map_height = 30; // reel 30

	// Variable affichant les textures de la map
	sf::Texture tileset_texture;
	sf::Sprite tileset_sprite;

	// Chargement des texture pour le background
	tileset_texture.loadFromFile("Background/tileTest2.png");
	tileset_sprite.setTexture(tileset_texture);

	// Variable affichant les textures du personnage
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// Chargement des textures du personnage
	playerTexture.loadFromFile("Character/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(0.35f, 0.35f);
	playerSprite.setTextureRect(sf::IntRect(0, 0, 95, 103));
	//playerSprite.setPosition(window.getSize().x/2, window.getSize().y/2); //Place le sprite au milieu de la fenetre


	// Vitesse du joueur
	float playerMovementSpeed = 0.2;

	// Animation

	int animationCounter = 0;
	int animationFrameDuration = 15;
	int counterWalking = 0;
	sf::Clock clock;

	//Tableau a 2 dimension représentant les differentes position des sprites sur la carte
	int map[] = {
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0,
		2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2,
		4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4,
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1,	0, 1, 1, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1,	1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1,	0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0,
		2, 1, 0, 8, 1, 2, 1, 0, 8, 1,	2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2,
		4, 1, 1, 0, 1, 4, 1, 1, 0, 1,	4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4,
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0,
		2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2,
		4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4,
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1,	1, 2, 1, 1, 1, 1, 2, 1, 1, 1,	1, 2, 1, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1,	0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0,
		2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2,
		4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4,
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1,	0, 1, 1, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1,	1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
		0, 1, 4, 1, 1, 0, 1, 4, 1, 1,	0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0,
		2, 1, 0, 8, 1, 2, 1, 0, 8, 1,	2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2, 1, 0, 8, 1, 2,
		4, 1, 1, 0, 1, 4, 1, 1, 0, 1,	4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4, 1, 1, 0, 1, 4,
		0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1
	};

	sf::View mainView;
	mainView.setSize(1280/3.45,720/3.45);

	while (window.isOpen())
	{
		mainView.setCenter(playerSprite.getPosition());

		// Sprite du personnage au repos
		playerSprite.setTextureRect(sf::IntRect(counterWalking * 95, 0 * 105, 95, 103));

		// Evenement qui se produit quand on ferme la fenetre
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(); // Met la fenetre avec les memes pixel ( ecrasement des anciens pixels )
		window.setView(mainView);
		// Deplacement du joueur

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			playerSprite.move(playerMovementSpeed, 0);
			playerSprite.setTextureRect(sf::IntRect(counterWalking * 95, 7 * 105, 95, 103)); // Charge l'animation du sprite du personnage quand il marche a droite

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			playerSprite.move(-playerMovementSpeed, 0);
			playerSprite.setTextureRect(sf::IntRect(counterWalking * 95, 5 * 105, 95, 103));

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerSprite.move(0, -playerMovementSpeed);
			playerSprite.setTextureRect(sf::IntRect(counterWalking * 95, 6*105, 95, 103));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerSprite.move(0, playerMovementSpeed);
			playerSprite.setTextureRect(sf::IntRect(counterWalking * 95, 4 * 105, 95, 103));

		}




		// Permet de changer de sprite pour creer une animation
		animationCounter += clock.restart().asMilliseconds(); // prend le temps qui se déroule en temps réel
		//std::cout << "Nombre : " << animationCounter << std::endl; // obliger de le mettre sinon pas d'animation ( ?? )

		if (animationCounter >= animationFrameDuration) // Comparaison pour savoir si l'on passe au sprite suivant de l'animation
		{
			animationCounter =0;
			counterWalking++;
			if (counterWalking == 10) // Permet de choisir le bon sprite pour que l'animation soit fluide et cohérente
			{
				counterWalking = 0;
			}
		}


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
		window.draw(playerSprite);
		window.setView(window.getDefaultView());


		window.display(); // Affiche les pixels
	}
	return 0;
}
