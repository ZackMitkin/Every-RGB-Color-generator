#define _WIN32_WINNT 0x0500 

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>
#include <sstream>

#include <iostream>
#include <string>

int main() {

	sf::Vector3f colors = sf::Vector3f(2, 2, 2);

	bool x = 1, y = 1, z = 1;

	sf::RenderWindow window(sf::VideoMode(640, 480), "CRINGE");

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	window.setFramerateLimit(15);

	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		int speed = 1;

		if (z == 1) {
			colors.z = colors.z + speed;
		}
		if (z == 0) {
			colors.z = colors.z - speed;
		}

		if (colors.z > 255 - speed || colors.z <= 1 ) {
			if (y == 1) {
				colors.y = colors.y + speed;
			}
			else {
				colors.y = colors.y - speed;
			}
			z = !z;
		}
		if (colors.y >= 255 || colors.y <= 1) {
			if (x == 1) {
				colors.x = colors.x + speed;
			}
			else {
				colors.x = colors.x - speed;
			}
			y = !y;
		}
		if (colors.x >= 255 || colors.x <= 0) {
			x = !x;
		}

		int r = colors.x;
		int g = colors.y;
		int b = colors.z;

		std::ostringstream oss;
		oss << "R: " << r << " G: " << g << " B: " << b;
		std::string s = oss.str();

		window.clear(sf::Color(colors.x, colors.y, colors.z));
		window.display();

	}
	return 0;
}