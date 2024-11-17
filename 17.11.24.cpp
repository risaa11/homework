#include <iostream>

using namespace std;

void fillArray(int* array,int* dublArr, int size)
{
    for(int i = 0; i<size; ++i)
    {
        cin>>array[i];
        dublArr[i] = array[i];
    }
}
1: Гистаграмма со звездочками ( * )
void check(int* dublArr, int size)
{
    int sum = 0;
    for(int i = 0; i<size; ++i)
    {
        sum = 0;
        for(int j = i+1; j<size; ++j)
        {
            if(dublArr[i] == dublArr[j])
            {
                sum++;
                dublArr[j] = -1;
            }
        }
        if(dublArr[i] != -1)
        {
            cout<<dublArr[i];
            for(int k = 0; k<sum+1; ++k)
            {
                cout<<'*';
            }
            cout<<endl;
        }
    }
}

int main()
{
    const int size = 5;
    int array[size];
    int dublArr[size];
    fillArray(array, dublArr, size);
    check(dublArr,  size);
}
2: Сортировка шейкером:
#include <iostream>

using namespace std;

void fillArr(int* array, int size)
{
    for(int i = 0; i<size; ++i)
    {
        cin>>array[i];
    }
}

void shaker(int* array, int size)
{
    bool check = true;
    int temp = 0;
    
    do{
        check = false;
        for(int i = 0; i<size-1; ++i)
        {
            if(array[i] > array[i+1])
            {
                check = true;
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;   
            }
        }
        for(int j = size-1; j>1; --j)
        {
            if(array[j]<array[j-1])
            {
                check = true;
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp; 
            } 
        }
        
    }while(check);
}

void result(int* array, int size)
{
    for(int i = 0; i<size; ++i)
    {
        cout<<array[i]<<endl;  
    }
    
}

int main()
{
    const int size = 15;
    int array[size];
    fillArr(array, size);
    shaker(array, size);
    result(array,  size);
}
