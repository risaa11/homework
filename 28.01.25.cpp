// Homework1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void FillingMatrix(int** Matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            Matrix[i][j] = i;
        }
    }
}

int** CreateMatrix(int size)
{
    int** Matrix = new int* [size] {0};

    for (int i = 0; i < size; ++i)
        Matrix[i] = new int[size] {0};
    int temp = 1;

    FillingMatrix(Matrix, size);
    

    return Matrix;
}

void PrintArray(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << matrix[i][j] << "|";
        }
        std::cout << std::endl;
    }
}

void SpinArray(int** Matrix, int sdvig, int size)
{
    int temp1 = size - 1, temp2 = size - 1;
    int DublTemp = temp1;
    int** Dubl = CreateMatrix(size);
    
    switch (sdvig)
    {
    case 90:
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                Matrix[i][j] = Dubl[temp1][j];
                --temp1;
                
            }
            DublTemp;
            temp1 = DublTemp;
        }
        break;
    case 180:
        
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                Matrix[i][j] = Dubl[temp1][temp2];
                --temp2;
            }
            --temp1;
            temp2 = size - 1;
        }
        break;
    case 270:
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                Matrix[i][j] = Dubl[j][temp2];
                --temp1;

            }
            temp2--;
            temp1 = size - 1;
        }
        break;
    default:
        break;
    }

}


int main()
{
    const int size = 10;
    int sdvig = 0;

    std::cin >> sdvig;

    std::cout << "Hello World!\n";

    int** matrix = CreateMatrix(size);

    std::cout << "Choose ur sdvig ) 0/90/180/270/360" << std::endl;
    std::cout << "Default Matrix: " << std::endl;
    PrintArray(matrix, size);
    SpinArray(matrix, sdvig, size);
    std::cout << "Corrected Matrix: " << std::endl;
    PrintArray(matrix, size);
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
