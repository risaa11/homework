1:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int prp(int a)
{
    int sum = 0;
    for (int i = 0; a!=0; ++i)
    {
        sum += a % 10;
        a = a / 10;
    }
    return sum;
}

int main()
{  
    int a;
    int sum = 0;
    cin >> a;
    cout << prp(a) << endl;
}
2:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int prp(int a)
{
    int x0 = 15;
    int x = 15;
    for (int i = 0; i < a; ++i)
    {
        if (i >= 1) {
            x = x + 2;
            x0 = x0 + x;
        }
    }
    return x0;
}

int main()
{  
    int a;
    cin >> a;
    cout << prp(a) << endl;
}
3:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

void prp()
{
    int sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                cout << i << ' ' << j << ' ' << k << endl;
                sum += 3;
            }
        }
    }
    cout << "Worst picking time = " << sum << " sec" << endl;
}

int main()
{  
    prp();
}
4:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

void prp()
{
    int sum = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <=i; ++j)
        {
            if (i % j == 0)
                ++sum;      
        }
        if (sum == 2)
            cout << i << endl;
        sum = 0;
    }
}

int main()
{  
    prp();
}
5:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

void prp(int a, char b, int c)
{
    if (c == 1) {
        for (int i = 0; i < a; ++i)
        {
            cout << b << endl;
        }
    }
    if (c == 2) {
        for (int i = 0; i < a; ++i)
        {
            cout << b;
        }
    }
}

int main()
{  
    setlocale(LC_ALL, "ru");
    int a,c;
    char b;
    cout << "Кол-во/символ/верт(1) или горизонт(2)" << endl;
    cin >> a>>b>>c;
    prp(a,b,c);
}
