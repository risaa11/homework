#include <iostream>
#include <math.h>
#include <cstdlib>  
#include <ctime>  
#include <thread>  
#include <chrono>  
#include <string>  

using namespace std;

class Conus {
protected:
    int x;
    int y;
    double height;
    double radius;
public:

    Conus() {
        x = 0;
        y = 0;
        height = 0;
        radius = 0;
    }

    Conus(double heigh, double radiu) {
        x = 0;
        y = 0;
        height = heigh;
        radius = radiu;
    }

    Conus(int x, int y, double radius, double height) {
        this->x = x;
        this->y = y;
        this->height = height;
        this->radius = radius;
    }

    double Vol() {
        double vol = 0.333 * 3.1415 * radius * radius * height;
        cout << 0.333 * 3.1415 * radius * radius * height << endl;
        return vol;
    }
    double Square(){
        int l = sqrt((height * height) + (radius * radius));
        double sqr = 3.1415 * radius * (l + radius);
        cout<<3.1415 * radius * (l + radius) << endl;
        return sqr;
    }
    friend istream& operator>>(istream& stream, Conus& con) {
        cout << "conus.x: " << endl;    
        stream >> con.x;
        cout << "con.y ";
        stream >> con.y;
        cout << "conus.radius: " << endl;
        stream >> con.radius;
        cout << "con.height ";
        stream >> con.height;
        return stream;
    }
    friend ostream& operator <<(ostream& stream, Conus con) {
        stream << " X: " << con.x << " y: " << con.y << " radius: " << con.radius << " height: " << con.height << endl;
    }

};
class UsecConus : Conus{
private:
    double minRad;
public: 
    UsecConus() : Conus() {
        minRad = 0;
    }
    UsecConus(double minrad, int x, int y, double radius, double height)  {
        minRad = minrad;
        this->x = x;
        this->y = y;
        this->height = height;
        this->radius = radius;
    }
    friend ostream& operator <<(ostream& stream, UsecConus con) {
        stream << " X: " << con.x << " y: " << con.y << " radius: " << con.radius << " height: " << con.height <<" minradius: "<<con.minRad<< endl;
    }
    friend istream& operator>>(istream& stream, UsecConus& con) {
        cout << "conus.x: " << endl;
        stream >> con.x;
        cout << "con.y ";
        stream >> con.y;
        cout << "conus.radius: " << endl;
        stream >> con.radius;
        cout << "con.height ";
        stream >> con.height;
        cout << "conus.minRad:";
        stream >> con.minRad;
        return stream;
    }
    double Vol() {
        double vol = 1 / 3 * 3.1415 * height * (minRad * minRad + minRad * radius + radius * radius);
        cout << 1 / 3 * 3.1415 * height * (minRad * minRad + minRad * radius + radius * radius) << endl;
        return vol;
    }
    double Square() {
        double l = sqrt((height * height) + (radius * radius));
        double sqr = 3.1415 * (minRad * minRad + (minRad + radius) * l + radius * radius);
        cout << 3.1415 * (minRad * minRad + (minRad + radius)*l + radius * radius) << endl;
        return sqr;
    }
};

void Sravn(Conus a, Conus b) {
    if (a.Vol() > b.Vol())
        cout << "конус 1 больше, чем 2" << endl;
    else cout << "конус 1 меньше, чем 2" << endl;
}
void Sravn(UsecConus a, Conus b) {
    if (a.Vol() > b.Vol())
        cout << "конус 1 больше, чем 2" << endl;
    else cout << "конус 1 меньше, чем 2" << endl;
}
void Sravn(UsecConus a, UsecConus b) {
    if (a.Vol() > b.Vol())
        cout << "конус 1 больше, чем 2" << endl;
    else cout << "конус 1 меньше, чем 2" << endl;
}
void Sravn(Conus a, UsecConus b) {
    if (a.Vol() > b.Vol())
        cout << "конус 1 больше, чем 2" << endl;
    else cout << "конус 1 меньше, чем 2" << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    Conus fir{ 1,1,1,1 };
    fir.Square();
    fir.Vol();
    UsecConus sec{ 20,20,20,20,20 };
    sec.Square();
    sec.Vol();
    Sravn(fir,sec);
}
