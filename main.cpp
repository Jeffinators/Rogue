#include <iostream>
#include <string>

void draw() {
	int width = 20, height = 20;
	for (int i = 0; i < width+1; i++) {
		std::cout << "#";
	}
	std::cout << "\n";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width+1; j++)
		{
			if (j == 0)
				std::cout << "#";
			else std::cout << " ";

			if (j == width - 1)
				std::cout << "#";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < width+1; i++) {
		std::cout << "#";
	}
	std::cout << "\n";
}
int main() {
	draw();
}