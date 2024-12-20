1: rand array (6)
#include <iostream>

using namespace std;

void ZapArray(int* array)
{
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 9;
	}
}

int main()
{
	int* array = new int[10];
	ZapArray(array);
}

2:
#include <iostream>

using namespace std;

int FindTarget(string stroka, char target)
{
	int vhozh = 0;
	for (int i = 0; i < stroka.size(); ++i)
	{
		if (stroka[i] == target)
		{
			++vhozh;
		}
	}
	return vhozh;
}

int main()
{
	char target;
	cout << "Enter ur target" << endl;
	cin >> target;
	string stroka = "Hello";
	cout << FindTarget(stroka, target) << " entry" << endl;
}

3:

  
  #include <iostream>

using namespace std;

double MiddleValue(int* array, int size)
{
	double MiddleValResult = 0;

	for (int i = 0; i < size; i++)
	{
		MiddleValResult += array[i];
	}
	
	MiddleValResult = MiddleValResult / size;
	return MiddleValResult;
}

int main()
{
	int size = 10;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = i;
	}

	cout << MiddleValue(array, size) << endl;
}

4:

#include <iostream>

using namespace std;

void Sort(int* array, int size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main()
{
	int size = 10;
	int temp = 0;
	int* array = new int[size];
	for (int i = size-1; i >= 0; i--)
	{
		array[temp] = i;
		++temp;
	}
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << endl;
	}
	Sort(array, size);
	cout << "____________________" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}
