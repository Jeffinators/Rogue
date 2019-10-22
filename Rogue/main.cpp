#include <iostream>
#include <string>
#include <cmath>



using namespace std;
int playerX = 10, playerY = 10;
bool Game = true;
void draw() {
	//crates random room size
	int width = 20, height = 20;
	system("cls");
	//creates the top of the room
	for (int i = 0; i < width + 1; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width + 1; j++)
		{
			if (j == 0) {
				std::cout << "#";
			}
			//write player location here
			if (i == playerX && j == playerY) {
				cout << "@";
			}
			else std::cout << " ";

			if (j == width - 1)
				std::cout << "#";
		}
		std::cout << std::endl;
	}
	//creates bottom of the room
	for (int i = 0; i < width + 1; i++) {
		std::cout << "#";
	}
	std::cout << "\n";
}
bool input() {
	char command;
	while (Game = true) {
		cin >> command;
		//This moves down
		if (command == 's') {
			playerX++;
		}
		//this moves up
		else if (command == 'w') {
			playerX--;
		}
		//this moves left
		else if (command == 'a') {
			playerY--;
		}
		//This moves right
		else if (command == 'd') {
			playerY++;
		}
		//This exits the game
		else if (command == '=') {
			Game = false;
		}

		return Game;
	}

}
int main() {
	//while loop for game to run
	while (Game == true) {
		draw();
		input();
	}

}