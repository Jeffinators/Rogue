#include <iostream>

int width, hight = 20;
void draw() {
	system("cls");
	for (int i = 0; i < width; i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			else cout << " ";

			if (j == width - 1)
				cout << "#"
		}
		cout << endl
	}
	for (int i = 0; i < width; i++) {
		cout << "#";
	}
	cout << endl;
}
int main() {
	draw();
}