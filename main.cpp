#include <iostream>
#include <vector>
#include <fstream>

#include <SFML\Graphics.hpp>

int main() {
	
	int red, green, blue;
	std::vector <sf::Vector3i> colors;

	for (red = 0; red <= 255; red++) {
		for (green = 0; green <= 255; green++) {
			for (blue = 0; blue <= 255; blue++) {
				//std::cout << "pushed: " << colors.size() << std::endl;
				std::cout << colors.size() / 16581375.000000 << "%" << std::endl;
				colors.push_back(sf::Vector3i(red, green, blue));
			}
		}
	}

	std::ofstream myfile;
	myfile.open("numbers.txt");
	for (int i = 0; i < colors.size() -1; i++) {
		std::cout << colors[i].x << " " << colors[i].y << " " << colors[i].z << "\n";
		myfile << colors[i].x << colors[i].y << colors[i].z << "\n";
	}
	myfile.close();
	system("pause");
	return 0;
}