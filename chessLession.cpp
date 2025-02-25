#include <iostream>



class Horse
{
protected:
	bool H = false;
public:
	Horse(bool H)
	{
		this->H = H;
	}
	Horse()
	{
		this->H = false;
	}
};
class  Rook : public Horse
{
protected:
	bool R = false;
public:
	Rook(bool R)
	{
		this->R = R;
	}
	Rook()
	{
		this->R = false;
	}
};
class Pawn : public Rook
{
protected:
	bool P = false;
public:
	Pawn(bool P)
	{
		this->P = P;
	}
	Pawn()
	{
		this->P = false;
	}
};
class Elephant : public Pawn
{
protected:
	bool E = false;
public:
	Elephant(bool E)
	{
		this->E = E;
	}
	Elephant()
	{
		this->E = false;
	}
};
class King : public Elephant
{
protected:
	bool K = false;
public:
	King(bool K)
	{
		this->K = K;
	}
	King()
	{
		this->K = false;
	}
};
class Quenn : public King
{
protected:
	bool Q = false;
public:
	
	Quenn(bool Q)
	{
		this->Q = Q;
	}
	Quenn()
	{
		this->Q = false;
	}
};
class Figure : public Quenn
{
private:
public:
	Figure(char s)
	{
		if (s == 'k')
		{
			this->K = true;
		}
		if (s == 'q')
		{
			this->Q = true;
		}
		if (s == 'h')
		{
			this->H = true;
		}
		if (s == 'p')
		{
			this->P = true;
		}
		if (s == 'r')
		{
			this->R = true;
		}
		if (s == 'e')
		{
			this->E = true;
		}
	}
	Figure()
	{
			this->K = false;
			this->Q = false;
			this->H = false;
			this->P = false;
			this->R = false;
			this->E = false;
	}
	char getValue()
	{
		if (E)
			return 'E';
		else if (Q)
			return 'Q';
		else if (H)
			return 'H';
		else if (R)
			return 'R';
		else if (P)
			return 'P';
		else if (K)
			return 'K';
		else if (!E && !Q && !H && !R && !P && !K)
			return 0;
	}
	void setValue(char s)
	{
		this->K = false;
		this->Q = false;
		this->H = false;
		this->P = false;
		this->R = false;
		this->E = false;
		if (s == 'k')
		{
			this->K = true;
		}
		if (s == 'q')
		{
			this->Q = true;
		}
		if (s == 'h')
		{
			this->H = true;
		}
		if (s == 'p')
		{
			this->P = true;
		}
		if (s == 'r')
		{
			this->R = true;
		}
		if (s == 'e')
		{
			this->E = true;
		}
	}
};



Figure** mapCreate(char size)
{

	Figure** newMap = new Figure * [size];
	for (int i = 0; i < size; ++i)
		newMap[i] = new Figure[size];

	return newMap;
}

void printMap(Figure** map, int size)
{
	int scrr = size;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j].getValue() != 0)
				std::cout << map[i][j].getValue() << ' ';
			else
				std::cout << ' ' << ' ';
		}
		std::cout << "   " << scrr << std::endl;
		scrr--;
	}
	std::cout << "\n\nA" << ' ' << "B" << ' ' << "C" << ' ' << "D" << ' ' << "E" << ' ' << "F" << ' ' << "G" << ' ' << "H" << ' ' << std::endl;
}

void firstFillingMap(Figure** array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[1][i].setValue('p');
		array[6][i].setValue('p');
	}
	array[0][0].setValue('r');
	array[0][7].setValue('r');
	array[7][0].setValue('r');
	array[7][7].setValue('r');
	array[0][1].setValue('h');
	array[0][6].setValue('h');
	array[7][1].setValue('h');
	array[7][6].setValue('h');
	array[0][2].setValue('e');
	array[0][5].setValue('e');
	array[7][2].setValue('e');
	array[7][5].setValue('e');
	array[0][3].setValue('k');
	array[7][3].setValue('k');
	array[0][4].setValue('k');
	array[7][4].setValue('k');
}

void newStep(Figure** array, int size);

int main()
{
	const int size = 8;
	Figure** map = mapCreate(size);
	firstFillingMap(map, size);
	do
	{
		printMap(map, size);
		newStep(map, size);
	} while (true);
}

void newStep(Figure** map, int size)
{
	int tempFigure = 0, tempFigure2 = 0;
	char figg;
	int tempFinalPoint = 0, tempFinalPoint2 = 0;
	char finn;
	std::cout << "Choose ur figure (x y)" << std::endl;
	std::cin >> figg;
	if (figg == 'A' || figg == 'a')
		tempFigure = 1;
	else if (figg == 'B' || figg == 'b')
		tempFigure = 2;
	else if (figg == 'C' || figg == 'c')
		tempFigure = 3;
	else if (figg == 'D' || figg == 'd')
		tempFigure = 4;
	else if (figg == 'E' || figg == 'e')
		tempFigure = 5;
	else if (figg == 'F' || figg == 'f')
		tempFigure = 6;
	else if (figg == 'G' || figg == 'g')
		tempFigure = 7;
	else if (figg == 'H' || figg == 'h')
		tempFigure = 8;
	std::cin >> tempFigure2;
	std::cout << "Choose final point (x y)" << std::endl;
	std::cin >> finn;
	if (finn == 'A' || finn == 'a')
		tempFinalPoint = 1;
	else if (finn == 'B' || finn == 'b')
		tempFinalPoint = 2; 
	else if (finn == 'C' || finn == 'c')
		tempFinalPoint = 3;
	else if (finn == 'D' || finn == 'd')
		tempFinalPoint = 4;
	else if (finn == 'E' || finn == 'e')
		tempFinalPoint = 5;
	else if (finn == 'F' || finn == 'f')
		tempFinalPoint = 6;
	else if (finn == 'G' || finn == 'g')
		tempFinalPoint = 7;
	else if (finn == 'H' || finn == 'h')
		tempFinalPoint = 8;
	std::cin >> tempFinalPoint2;
	if (map[tempFigure2 - 1][tempFigure - 1].getValue() == 'K')
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('k');
		map[size - (tempFigure2)][tempFigure - 1].setValue('n');
	}
	else if (map[tempFigure2 - 1][tempFigure - 1].getValue() == 'Q')
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q');
		map[size - (tempFigure2)][tempFigure - 1].setValue('n');
	}
	else if (map[tempFigure2 - 1][tempFigure - 1].getValue() == 'E')
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e');
		map[size - (tempFigure2)][tempFigure - 1].setValue('n');
	}
	else if (map[tempFigure2 - 1][tempFigure - 1].getValue() == 'R')
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r');
		map[size - (tempFigure2)][tempFigure - 1].setValue('n');
	}
	else if (map[tempFigure2 - 1][tempFigure - 1].getValue() == 'P')
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p');
		map[size - (tempFigure2)][tempFigure - 1].setValue('n');
	}
	else if (map[tempFigure2 - 1][tempFigure - 1].getValue() == 'H')
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('h');
		map[size - (tempFigure2)][tempFigure - 1].setValue('n');
	}

}
