#include <iostream>
using namespace std;

class Func;
class Point {
    friend Func;
private :
    int y;
    int x;
public: 
    Point(int xo, int yo) {
        this->x = xo;
        this->y = yo;
    }

    friend void swap(Point&,Point&);
    
    void print() {
        cout << "x: " << x << " y: " << y << endl;
    }
};



void swap(Point& a, Point& b) {
    int op;
    op = a.x;
    a.x = b.x;
    b.x = op;
    op = a.y;
    a.y = b.y;
    b.y = op;
}


class Func {
    friend int aver(Func&, int, int);
private:
    int a, b,  c;
public: 

    Func() {
        a = 0;
        b = 0;
        c = 0;
    }

    Func(int i_a, int i_b,  int i_c) {
        a = i_a;
        b = i_b;
        c = i_c;
        
    }
    
    bool Iscont(Point& poi) {
        poi.x;
        return (poi.y == a * poi.x * poi.x + b * poi.x + c) ? true : false ;
    }
    void print() {
        cout << a << "x^2+" << b << "x+" << c<<endl;
    }
};

int aver(Func& fun, int l, int r) {
    int sum = 0;
    int con = 0;
    for (int i = l; i <= r; i++) {
        int x = i;
        int y = fun.a * x * x + fun.b * x + fun.c;
        sum += y;
        con++;
    }

    sum = sum / con;
    return sum;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Func fun(2,4,0);
    Point poi(0,0);
    cout << fun.Iscont(poi)<<endl;
    cout<<aver(fun, 2, 2)<<endl;
    fun.print();
}
