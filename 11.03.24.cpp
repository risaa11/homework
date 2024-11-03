1:

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int prgr(int r1, int r2, int r3)
{
	int r = 0;
	int a = r1 * r2 * r3;
	int b = r1 * r2 + r2 * r3 + r3 * r1;
	r = a / b;
	return r;
}

int main()
{
	int r1, r2, r3;
	cin >> r1;
	cin >> r2;
	cin >> r3;
	prgr(r1, r2, r3);
}

2:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    cout << "x1 y1 x2 y2? ";
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x = sqrt(x1 - x2);
    int y = sqrt(y1 = y2);
    cout << "Расстояние: " << sqrt(x + y) << endl;
}

3:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

void abc(int a, int b, int c)
{
    (a < b) ? (a < c) ? cout << c : cout << c : (b < c) ? cout << c : cout << b;
}

int main()
{
    int a,  b,  c;
    cin >> a >> b >> c;
    abc(a,b,c);
}

4:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

void abc(int a, int b, int c)
{
    if (a >= 1 || a <= 3)
    {
        cout<<a;
    }
    if (b >= 1 || b <= 3)
    {
        cout << b;
    }
    if (c >= 1 || c <= 3)
    {
        cout << c;
    }
}

int main()
{
    int a,  b,  c;
    cin >> a >> b >> c;
    abc(a,b,c);
}
5:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int abb(int a)
{
    if (a >= 10 && a <= 100) 
        return 2;
    else
        return 0;
}

int perv(int a);
int posl(int a);

int sum(int a)
{
    return perv(a) + posl(a);
}
int perv(int a)
{
    return a / 10;
}
int posl(int a)
{
    return a % 10;
}

int main()
{  
    int a;
    cin >> a;
    cout << "quantity = " << abb(a) << endl;
    cout << "number sum = "<<sum(a) << endl;
    cout << "first = "<<perv(a)<<" second = "<<posl(a)<<endl;
}
