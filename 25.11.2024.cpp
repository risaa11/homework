#include <iostream>

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/

void pask(int n);

void print(int* newarr, int c);

int main() {
int n;
std::cin>>n;
pask(n-2);
}

void pask(int n)
{
    int c = 1;
    int* start = new int[c]{1};
    ++c;
    std::cout<<start[0]<<std::endl;
    int* array = new int[c]{1,1};
    std::cout<<array[0]<<' '<<array[1]<<std::endl;
    ++c;
    int* farray = array;
    for(int i = 0; i<n; ++i)
    {
        int* newarr = new int[c];
        
        newarr[0] = 1;
        newarr[c-1] = 1;
        
        for(int j = 1; j<c; ++j)
        {
            newarr[j] = farray[j-1] + farray[j];
        }
        print( newarr,  c);
        farray = newarr;
        ++c;
    }
}

void print(int* newarr, int c)
{
    
    for(int i = 0; i<c; ++i)
    {
        std::cout<<newarr[i]<<' ';
        
    }
    std::cout<<std::endl;
}
