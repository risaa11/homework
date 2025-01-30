#include <iostream>

void CheckInfo(int Point)
{
	std::cout << "This is a number!!!" << std::endl;
}

void CheckInfo(char Point)
{
	((Point >= 41 && Point <= 90) || (Point>=97&&Point<=122))? std::cout<<"This is a letter"<<std::endl: std::cout<<"This is a symbol";
}

int main()
{
	int Chislo = 5;
	char Symb = 'g';
	CheckInfo(Chislo);
	CheckInfo(Symb);
	Symb = '&';
	CheckInfo(Symb);
}
