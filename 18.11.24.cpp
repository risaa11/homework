
#include<iostream>
using namespace std;

/*

Функция, которую нужно дописать
int** transponMatrix(int** matrix){
    
}
*/

//Функция для вывода динамической матрицы
void printMatrix(int** matrix, int size_X, int size_Y){
    for(int i = 0; i < size_X; i++){
        
        
        for(int j = 0; j < size_Y; j++){
            cout << matrix[i][j] << " ";  
        }
        cout << endl;
     }
}

int** transponMatrix(int** matrix, int size_X, int size_Y){
    int** matrix2 = new int*[size_X];
    
    for(int i = 0; i < size_X; i++){
        matrix2[i] = new int[size_Y];
        
        for(int j = 0; j < size_Y; j++){
            matrix2[i][j] = matrix[j][i];  
        }
     }
    return matrix2;
}

void printMatrix2(int** matrix2, int size_X, int size_Y){
    for(int i = 0; i < size_X; i++){
        
        
        for(int j = 0; j < size_Y; j++){
            cout << matrix2[i][j] << " ";  
        }
        cout << endl;
     }
}

//Функция создания динамической матрицы размера size_X по вертикали и size_Y горизонтали 
int** getRandomMatrix(int size_X, int size_Y){
    int** matrix = new int*[size_X];
    
    for(int i = 0; i < size_X; i++){
        matrix[i] = new int[size_Y];
        
        for(int j = 0; j < size_Y; j++){
            matrix[i][j] = rand() % 9 + 1;  
        }
     }
     
     return matrix;
}


int main()
{
    int** matrix = getRandomMatrix(5,5);
    printMatrix(matrix, 5, 5);
    cout<<"================================"<<endl;
    int** matrix2 = transponMatrix(matrix,  5,  5);
    printMatrix2(matrix2,  5,  5);
    return 0;
}
