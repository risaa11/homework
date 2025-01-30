#include <iostream>

void PrintMatrix(int** Matrix, int size);

void CheckPoint(int** array, int size)
{
	bool check = true, check2 = true;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			for (int c = 0; c < size; ++c)
			{
				if (array[i][j] > array[i][c])
					check = false;
			}

			if (check)
			{
				for (int c = 0; c < size; ++c)
				{
					if (array[i][j] < array[c][j])
						check2 = false;
				}
			}
			else
				check = false;

			if (check && check2)
				std::cout << array[i][j] << std::endl;
			else
				check2 = false;
			check = true;
			check2 = true;

		}
	}
}

void FillingMatrix(int** array, int size)
{
	int k = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			++k;
			array[i][j] = k;
		}
	}
}

int** MatrixInicilization(int size)
{
	int** matrix = new int* [size];

	for (int i = 0; i < size; ++i)
		matrix[i] = new int[size];
	
	return matrix;
}

int main()
{
	const int Size = 10;

	int** Matrix = MatrixInicilization(Size);

	FillingMatrix(Matrix, Size);

	CheckPoint(Matrix, Size);
	
	PrintMatrix(Matrix, Size);

}

void PrintMatrix(int** Matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << Matrix[i][j]<<' ';
		}
		std::cout << std::endl;
	}
}
