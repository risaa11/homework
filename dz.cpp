1:
#include <iostream> 

int fibn(int n);

int main()
{
 int n;
 std::cin >> n;
 
 std::cout << fibn(n-1) << std::endl;
}

int fibn(int n)
{
 if (n > 1)
  return fibn(n-1) + fibn(n - 2);
 else
  return 1;

}

2:
#include <iostream>

int Step(int n, int chisl, int dubl);

int main()
{
 int n, chisl;
 std::cin >> chisl>>n;
 int dubl = chisl;
 std::cout << Step(n, chisl, dubl) << std::endl;
}

int Step(int n, int chisl, int dubl)
{
 if (n > 1)
  return Step(n - 1, chisl * dubl, dubl);
 else
  return chisl;
}
