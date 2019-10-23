#include <iostream>
#include <string>
#include <cmath>
#include<vector>



//using namespace std;
int playerX = 10, playerY = 10;
bool Game = true;
//crates random room size
int width = 20, height = 20;
//creates an exit
int exitX = rand() % 20, exitY = rand() % 20;
//allows saving of previous exits and new exits
int oWidth; //i dont even see a cmd popup... 
int oHeight;//just don't ex out or it will error
int oldExitX = exitX, oldExitY = exitY;
int newExitX = (rand() % 20) + 20, newExitY = (rand() % 20) + 20;
//counts the room number
int room;
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
				std::cout << "@";
			}
			//creates exit
			if (room > 0 && i == oldExitX && j == oldExitY) {
				std::cout << "E";
			}
			if (i == newExitX && j == newExitY) {
				std::cout << "%";
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
		std::cin >> command;
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
void collision()
{
	std::vector<int> oldRoomsW;
	std::vector<int> oldRoomsH;
	if (playerX == newExitX && playerY == newExitY) {
		oldRoomsW.push_back(width);
		oldRoomsH.push_back(height);
		width = (rand() % 30) + 20;
		height = (rand() % 30) + 20;
		room++;
		oldExitX = newExitX;
		oldExitY = newExitY;
		newExitX = (rand() % 20);
		newExitY = (rand() % 20);
	}
	if (room > 0 && playerX == oldExitX && playerY == oldExitY) {
		width = oldRoomsW.back();
		height = oldRoomsH.back();
		oldRoomsH.pop_back();
		oldRoomsW.pop_back();
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