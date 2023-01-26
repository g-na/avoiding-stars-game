#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "GameObject.h"
#include "Manager.h"

int main(void)
{
	srand(time(NULL));
		
	bool state = true;
	int score = 0;
	int life = 3;

	Flight flight;
	Manager manager;

	while (state)
	{
		system("cls");
		printf("Life: %d   Score: %d\n\n", life, score);

		if (_kbhit())
		{
			int input = _getch();
			flight.Move(input);
		}
		
		flight.Print();

		manager.MakeStar();
		manager.MoveStar();
		manager.PrintStar();
		manager.CheckStar();
		
		if (manager.CheckCollision(&flight)) { life--; }
		if (life <= 0) { state = false; }
		
		score++;
		Sleep(100);
	}

	system("cls");
	manager.GameOver(score);

	return 0;
}