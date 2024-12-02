#include <iostream> 
#include <typeinfo> 
#include "string"

void ups(std::string a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		if (int(a[i]) >= 65 || int(a[i]) <= 90)
		{
			std::cout << a[i];
		}
		else
		{
			a[i] = int(a[i]) - 32;
			std::cout << a[i];
		}
	}
}

void nizh(std::string a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		if (int(a[i]) >= 65 || int(a[i]) <= 97)
		{
			a[i] = int(a[i]) + 32;
			std::cout << a[i];
		}
		else
		{
			std::cout << a[i];
		}
	}
}

void swap(std::string a)
{
	std::string glas = "AaEeIiOoUuYy";
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < glas.size(); ++j)
		{
			if (a[i] == glas[j])
				a[i] = '_';

		}
	}
	std::cout << a;
}

int main()
{
	std::string a;
	a = "ABOBA";

	std::cout << int('A') << ' ' << int('Z') << std::endl;
	std::cout << int('a') << ' ' << int('z') << std::endl;
	nizh(a);
	std::cout << std::endl;
	ups(a);
	std::cout << std::endl;
	swap(a);
}
