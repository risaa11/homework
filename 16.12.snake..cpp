#include <iostream>
#include "windows.h" 
#include <ctime>
#include <conio.h>

int** CreateMatrix(int size_X, int size_Y, int startval_X, int startval_Y, int startval_Dog_X = 5, int startval_Dog_Y = 5);

int** CreateMap(int& size_X, int& size_Y);

void StartGame(int** map, int size_X, int size_Y);

void SwapMap(int Current_X, int Current_Y, int size_X, int size_Y, int** map, int& Dog_X_Value, int& Dog_Y_Value);

void FillingMap(int startval_X, int startval_Y, int size_X, int size_Y, int** map, int startval_Dog_X = 5, int startval_Dog_Y = 5);

int main()
{
	setlocale(LC_ALL, "ru");
	//Создание карты: 
	int size_X = 0, size_Y = 0;
	int** map;
	map = CreateMap(size_X, size_Y);
	//Вход в игру
	StartGame(map, size_X, size_Y);


}

int** CreateMap(int& size_X, int& size_Y)
{
	/*
	std::cout << "Введите ширину игрового поля: " << std::endl;
	std::cin >> size_X;
	std::cout << "Введите длину игрового поля: " << std::endl;
	std::cin >> size_Y;
	*/
	size_X = 10;
	size_Y = 10;
	int startval_X = 1, startval_Y = 1;
	int startval_Dog_X = 2, startval_Dog_Y = 2;
	int** map = CreateMatrix(size_X, size_Y, startval_X, startval_Y, startval_Dog_X, startval_Dog_Y);

	return map;

}



int** CreateMatrix(int size_X, int size_Y, int startval_X, int startval_Y, int startval_Dog_X, int startval_Dog_Y)
{
	int** map = new int* [size_X];
	for (int i = 0; i < size_Y; ++i)
	{
		map[i] = new int[size_Y];
	}
	FillingMap(startval_X, startval_Y, size_X, size_Y, map, startval_Dog_X, startval_Dog_Y);
	return map;
}

void StartGame(int** map, int size_X, int size_Y)
{
	bool check = true;
	int Dog_X_Value = 2;
	int Dog_Y_Value = 2;
	int Start_Point_X = 1, Start_Point_Y = 1, key = 0, Current_X = 1, Current_Y = 1;
	do {
		system("CLS");

		for (int i = 0; i < size_X; ++i)
		{
			check = true;
			for (int j = 0; j < size_Y; ++j)
			{
				if (map[i][j] == 1)
				{
					std::cout << '*' << ' ';
				}
				if (map[i][j] == 2)
				{
					std::cout << "@" << ' ';
				}
				if ((map[i][j] == 0 && i != 0) && (map[i][j] == 0 && i != size_X - 1) && (map[i][j] == 0 && j != 0) && (map[i][j] == 0 && j != size_Y - 1))
				{
					std::cout << ' ' << ' ';
					check = false;
				}
				else if (map[i][j] != 1 && map[i][j] != 2)
					std::cout << map[i][j] << ' ';

			}
			std::cout << std::endl;
		}
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}



		switch (key)
		{
			//up
		case 72:
			SwapMap(Current_X - 1, Current_Y, size_X, size_Y, map, Dog_X_Value, Dog_Y_Value);
			Current_X = Current_X - 1;
			break;
			//right
		case 77:
			SwapMap(Current_X, Current_Y + 1, size_X, size_Y, map, Dog_X_Value, Dog_Y_Value);
			Current_Y = Current_Y + 1;
			break;
			//down
		case 80:
			SwapMap(Current_X + 1, Current_Y, size_X, size_Y, map, Dog_X_Value, Dog_Y_Value);
			Current_X = Current_X + 1;
			break;
			//left
		case 75:
			SwapMap(Current_X, Current_Y - 1, size_X, size_Y, map, Dog_X_Value, Dog_Y_Value);
			Current_Y = Current_Y - 1;
			break;
		default:

			break;

		}
		Sleep(50);
		int c = key;
		std::cout << key;
	} while (true);
}

void SwapMap(int Current_X, int Current_Y, int size_X, int size_Y, int** map, int& Dog_X_Value, int& Dog_Y_Value)
{
	for (int i = 0; i < size_X; ++i)
	{
		for (int j = 0; j < size_Y; ++j)
		{
			map[i][j] = 0;
		}
	}
	if (Current_X == Dog_X_Value && Current_Y == Dog_Y_Value)
	{
		Dog_X_Value = rand() % (size_X-2) + 1;
		Dog_Y_Value = rand() % (size_Y-2) + 1;
	}
	if (Current_X == 0 || Current_X == size_X - 1 || Current_Y == 0 || Current_Y == size_Y - 1)
	{
		int esc = 0;
		std::cout << "Вы проиграли. Нажмите любую кнопку, чтобы начать сначала. " << std::endl;
		esc = _getch();
		if(esc)
			exit(0);
	}
	for (int i = 0; i < size_X; ++i)
	{
		for (int j = 0; j < size_Y; ++j)
		{
			if (i == Current_X && j == Current_Y)
			{
				map[i][j] = 1;
			}
			else
				map[i][j] = 0;
			if (i == Dog_X_Value && j == Dog_Y_Value)
			{
				map[i][j] = 2;
			}
		}
	}

}

void FillingMap(int startval_X, int startval_Y, int size_X, int size_Y, int** map, int startval_Dog_X, int startval_Dog_Y)
{
	for (int i = 0; i < size_X; ++i)
	{
		for (int j = 0; j < size_Y; ++j)
		{
			if (i == startval_X && j == startval_Y)
			{
				map[i][j] = 1;
			}
			else
				map[i][j] = 0;
			if (i == startval_Dog_X && j == startval_Dog_Y)
			{
				map[i][j] = 2;
			}

		}
	}
}
