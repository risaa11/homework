#include <iostream>

int** CreateMatrix(int size);

void FillingArray(int** Matrix, int size);

int SumArrayElements(int** Matrix, int size);

void PrintMatrix(int** Matrix, int size);

int main()
{
	const int size = 2;
	int** Matrix = CreateMatrix(size);
	FillingArray(Matrix, size);
	std::cout << SumArrayElements(Matrix, size) << std::endl;
	PrintMatrix(Matrix, size);
}

int** CreateMatrix(int size)
{
	int** Matrix = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		Matrix[i] = new int[size];
	}
	return Matrix;
}

void FillingArray(int** Matrix, int size)
{
	int temp = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			++temp;
			Matrix[i][j] = temp;
		}
	}
}

int SumArrayElements(int** Matrix, int size)
{
	int temp = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			temp += Matrix[i][j];
		}
	}
	return temp;
}

void PrintMatrix(int** Matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << Matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
