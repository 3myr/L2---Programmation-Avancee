//SUPPRIMER LE MAIN DU FICHIER "Test_OpenGL_Install.cpp" POUR EVITER LE CONFLIT


#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML");

	while (window.isOpen())
	{
		window.clear();

		window.display();
	}
	return 0;
}