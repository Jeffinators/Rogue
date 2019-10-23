#include <iostream>
#include <string>
#include <cmath>



using namespace std;
int playerX = 10, playerY = 10;
bool Game = true;
//crates random room size
int width = 20, height = 20;
//creates an exit
int exitX = rand() % 20, exitY = rand() % 20;
//allows saving of previous exits and new exits
int oldExitX = exitX, oldExitY = exitY;
int newExitX = 19, newExitY = 19;
//counts the room number
int room;
int oWidth = 10, oHeight = 10;
void draw() {
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
			//creates exit
			if (i == oldExitX && j == oldExitY) {
				cout << "%";
			}
			if (room > 0 && i == newExitX && j == newExitY) {
				cout << "%";
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
//detects if the player collides with the exit
void collision() {
	if (room == 0 && playerX == exitX && playerY == exitY) {
		oWidth = width;
		oHeight = height;
		width = (rand() % 30) + 20;
		height = (rand() % 30) + 20;
		room++;
		newExitX = 19;
		newExitY = 19;
		draw();
	}
	if (playerX == newExitX && playerY == newExitY) {
		oWidth = width;
		oHeight = height;
		width = (rand() % 30) + 20;
		height = (rand() % 30) + 20;
		room++;
		oldExitX = newExitX;
		oldExitY = newExitY;
		newExitX = (rand() % 20);
		newExitY = (rand() % 20);
	}
	//goes back a room (not working yet)
	if (room > 1 && playerX == oldExitX && playerY == oldExitY) {
		width = oWidth;
		height = oHeight;
		draw();
	}
}
//creates new exit
/*void exit() {
	int oldExitX = exitX, oldExitY = exitY;
	int newExitX = (rand() % 29) + 20, newExitY = (rand() % 29) + 20;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width + 1; j++)
		{
			//creates exit
			if (i == exitX && j == exitY) {
				cout << "%";
			}
		}
	}
}*/
int main() {
	//while loop for game to run
	while (Game == true) {
		draw();
		//exit();
		input();
		collision();
	}

}