1:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;


int main()
{
	const int size = 10;
	vector <int> result;
	int array[size]{ 10, 10, 10, 13, 13, 14, 15, 16, 17, 18 } , dubl[size];
	int sum = 0;
	
	for (int i = 0; i < size; ++i)
	{
		dubl[i] = array[i];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (dubl[i] == dubl[j])
			{
				sum = 0;
				for (int k = 0; k < result.size(); ++k)
				{
					if (dubl[i] == result[k])
						++sum;
				}
				if (sum == 0)
					result.push_back(dubl[i]);
			}
		}
	}
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
}

2:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace stdi;


int main()
{
	const int size1 = 10, size2 = 10;
	int array[size1][size2];
	int result1[size1], resultt[size1];
	int tt = size1 - 1;
	int helps1 = 100, helps2 = 0, temp = 0;
	int result = 0;
	int resulttt[2];

	for (int i = 0; i < size1; ++i)
	{Y
		for (int j = 0; j < size2; ++j, --helps1)
		{
			array[i][j] = helps1;
		}
	}
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			for (int k = j + 1; k < size2; ++k)
			{
				if (array[i][j] > array[i][k])
				{
					helps2 = array[i][j];
					array[i][j] = array[i][k];
					array[i][k] = helps2;
				}
			}
		}
		result1[i] = array[i][0];
	}
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j, --helps1)
		{
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;

	for (int i = 0; i < size1; ++i)
	{

		resultt[i] = result1[tt];
		--tt;
	}
	for (int i = 0; i < size1; ++i)
	{
		cout << resultt[i] << endl;
	}

	for (int i = 0; i < size1; ++i)
	{
		for (int j = i + 1; j < size1; ++j)
		{
			if (resultt[i] > resultt[j])
			{
				temp = resultt[i];
				resultt[i] = resultt[j];
				resultt[j] = temp;
				cout << resultt[i] << endl;
			}
		}
	}
	cout << endl << endl;

	int s = 0;
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			
			if (array[i][j] == resultt[0])
			{
				resulttt[s] = i;
				++s;
				resulttt[s] = j;
			}
		}

		
	}
	cout <<"Number: "<< resultt[0]<<endl<<"Index i = " <<resulttt[0]<<endl<< "Index j = " << resulttt[1] << endl;
	cout << endl << endl;
}
3:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;


int main()
{
	int condition = 0, condition1 = 0, condition2 = 0, condition3 = 0;
	const int size1 = 4, size2 = 10;
	int array[size1][size2];
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			if (i == 0)
				array[i][j] = 0;
			if(i == 1)
				array[i][j] = 19;
			if (i == 2)
				array[i][j] = 20;
			if (i == 3)
				array[i][j] = j;
		}
	}
	

	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			for (int k = j + 1; k < size2; ++k)
			{
				if (array[i][j] != array[i][k])
					condition = 1;

				if (array[i][j] != array[i][k] || array[i][j] != 0)
					condition1 = 1;
				
				if (array[i][j] % 2 != 0)
					condition2 = 1;

			}
		}
		if (condition == 0)
			cout << i << " str - DOUPLICATE" << endl;
		condition = 0;
		if (condition1 == 0)
			cout << i << " str - ALL_NULL" << endl;
		condition1 = 0;
		if (condition2 == 0)
			cout << i << " str - EVEN" << endl;
		condition2 = 0;
		
	}
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2-1; ++j)
		{
			for (int k = j + 1; k < size2; ++k)
			{
				if (array[i][j] - array[i][j+1] != -1 && array[i][j] - array[i][j + 1] != 1)
					condition3 = 1;
			}
		}
		if (condition3 == 0)
			cout << i << " str - notone" << endl;
		condition3 = 0;
	}
}
