#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

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
protected:
	bool line = true;
	bool straight = false;
	bool zigzag = false;
	bool whiteColor = false;
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
			this->zigzag = true;
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

	const char* getValue()
	{
		if (!this->whiteColor)
		{
			if (E)
				return u8"♗";
			else if (Q)
				return u8"♕"; 
			else if (H)
				return u8"♘";
			else if (R)
				return u8"♖";
			else if (P)
				return u8"♙";
			else if (K)
				return u8"♔";
			else if (!E && !Q && !H && !R && !P && !K)
				return 0;
		}
		else
		{
			if (E)
				return u8"♝";
			else if (Q)
				return u8"♛";
			else if (H)
				return u8"♞";
			else if (R)
				return u8"♜";
			else if (P)
				return u8"♙";
			else if (K)
				return u8"♚";
			else if (!E && !Q && !H && !R && !P && !K)
				return 0;
		}

	}

	void setValue(char s, char c)
	{
		if (c == 'W' || c == 'w')
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
				this->whiteColor = true;
			}
			if (s == 'q')
			{
				this->Q = true;
				this->whiteColor = true;
			}
			if (s == 'h')
			{
				this->H = true;
				this->line = false;
				this->zigzag = true;
				this->whiteColor = true;
			}
			if (s == 'p')
			{
				this->P = true;
				this->straight = true;
				this->whiteColor = true;
			}
			if (s == 'r')
			{
				this->R = true;
				this->straight = true;
				this->whiteColor = true;
			}
			if (s == 'e')
			{
				this->E = true;
				this->whiteColor = true;
			}
		}
		else
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
				this->whiteColor = false;
			}
			if (s == 'q')
			{
				this->Q = true;
				this->whiteColor = false;
			}
			if (s == 'h')
			{
				this->H = true;
				this->line = false;
				this->zigzag = true;
				this->whiteColor = false;
			}
			if (s == 'p')
			{
				this->P = true;
				this->straight = true;
				this->whiteColor = false;
			}
			if (s == 'r')
			{
				this->R = true;
				this->straight = true;
				this->whiteColor = false;
			}
			if (s == 'e')
			{
				this->E = true;
				this->whiteColor = false;
			}
		}
	}


	int getNull()
	{
		return (this->K == false && this->Q == false && this->H == false && this->P == false && this->R == false && this->E == false) ? 0 : 1;
	}
	bool getZigZag()
	{
		return this->zigzag;
	}
	char getColor()
	{
		return (whiteColor) ? 'W' : 'B';
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
	std::cout << "\n\nA" << ' ' << "B" << ' ' << "C" << ' ' << "D" << ' ' << "E" << ' ' << "F" << ' ' << "G" << ' ' << "H" << ' ' << "           <<<<<<<<<<<<<------------" << std::endl;
}

void firstFillingMap(Figure** array, int size)
{
	const char* emoji = u8"♟";
	for (int i = 0; i < size; ++i)
	{
		array[1][i].setValue('p', 'B');
		array[6][i].setValue('p', 'W');
	}
	array[0][0].setValue('r', 'B');
	array[0][7].setValue('r', 'B');
	array[7][0].setValue('r', 'W');
	array[7][7].setValue('r', 'W');
	array[0][1].setValue('h', 'B');
	array[0][6].setValue('h', 'B');
	array[7][1].setValue('h', 'W');
	array[7][6].setValue('h', 'W');
	array[0][2].setValue('e', 'B');
	array[0][5].setValue('e', 'B');
	array[7][2].setValue('e', 'W');
	array[7][5].setValue('e', 'W');
	array[0][3].setValue('k', 'B');
	array[7][3].setValue('k', 'W');
	array[0][4].setValue('q', 'B');
	array[7][4].setValue('q', 'W');
}

void newStep(Figure** array, int size);

void quennStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2)
{
	if (((tempFigure - tempFinalPoint) == 0 || (tempFigure2 - tempFinalPoint2) == 0) || ((tempFigure + tempFinalPoint) == 0 || (tempFigure2 + tempFinalPoint2) == 0) || ((tempFigure + tempFinalPoint) == 0 || (tempFigure2 - tempFinalPoint2) == 0) || ((tempFigure - tempFinalPoint) == 0 || (tempFigure2 + tempFinalPoint2) == 0))
	{
		int tempp = 0;
		bool hair = true, falling = false;
		if (tempFigure2 - tempFinalPoint2 != 0)
			hair = false;
		if (hair)
		{
			if (tempFigure > tempFinalPoint)
			{
				falling = true;
				tempp = tempFigure - tempFinalPoint;
			}
			else
			{
				falling = false;
				tempp = tempFinalPoint - tempFigure;
			}
		}
		else
		{
			if (tempFigure2 > tempFinalPoint2)
			{
				falling = true;
				tempp = tempFigure2 - tempFinalPoint2;
			}
			else
			{
				falling = false;
				tempp = tempFinalPoint2 - tempFigure2;
			}
		}
		for (int i = 0;i < tempp; ++i)
		{
			if (falling && !hair)
			{
				tempFigure2--;
				if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
				{
					map[size - (tempFigure2)][tempFigure - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2 + 1)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				}
				else
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(3000);
					break;
				}
			}
			else if (!falling && !hair)
			{
				tempFigure2++;
				if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
				{
					map[size - (tempFigure2)][tempFigure - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2 - 1)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				}
				else
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(3000);
					break;
				}
			}
			else if (falling && hair)
			{
				tempFigure--;
				if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
				{
					map[size - (tempFigure2)][tempFigure - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				}
				else
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(3000);
					break;
				}
			}
			else if (!falling && hair)
			{
				tempFigure++;
				if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
				{
					map[size - (tempFigure2)][tempFigure - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 2].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				}
				else
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(3000);
					break;
				}
			}
		}

	}
	else
	{
		int temppf2 = tempFigure2;
		int temppf = tempFigure;
		if (tempFigure < tempFinalPoint && tempFigure2 < tempFinalPoint2)
		{
			do {
				temppf++;
				temppf2++;
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					break;
				}
				if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					std::cout << "No Quenn!!" << std::endl;
					Sleep(2000);
					break;
				}

			} while (true);
		}
		else if (tempFigure < tempFinalPoint && tempFigure2 > tempFinalPoint2)
		{
			do {
				temppf++;
				temppf2--;
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					break;
				}
				if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					std::cout << "No Quenn!!" << std::endl;
					Sleep(2000);
					break;
				}

			} while (true);
		}
		else if (tempFigure > tempFinalPoint && tempFigure2 < tempFinalPoint2)
		{
			do {
				temppf--;
				temppf2++;
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					break;
				}
				if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					std::cout << "No Quenn!!" << std::endl;
					Sleep(2000);
					break;
				}

			} while (true);
		}
		else if (tempFigure > tempFinalPoint && tempFigure2 > tempFinalPoint2)
		{
			do {
				temppf--;
				temppf2--;
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					break;
				}
				if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					std::cout << "No Quenn!!" << std::endl;
					Sleep(2000);
					break;
				}

			} while (true);
		}

	}
}

void pStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2)
{
	if (map[size - (tempFigure2)][tempFigure - 1].getColor() == 'W')
	{
		if (!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull())
		{
			if (tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1)
			{
				if (size - (tempFinalPoint2) < size - (tempFigure2))
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				}
				else
				{
					std::cout << "Impossible move(" << std::endl;
					Sleep(4000);
				}
			}
			else
			{
				std::cout << "Impossible point(" << std::endl;
				Sleep(4000);
			}
		}
		else
		{
			if (tempFinalPoint2 - tempFigure2 == 1 && tempFigure != tempFinalPoint && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			}
			else
			{
				std::cout << "Impossible point(" << std::endl;
				Sleep(4000);
			}
		}
	}
	else
	{
		if (!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull())
		{
			if (tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1)
			{
				if (size - (tempFinalPoint2) > size - (tempFigure2))
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				}
				else
				{
					std::cout << "Impossible move(" << std::endl;
					Sleep(4000);
				}
			}
			else
			{
				std::cout << "Impossible point(" << std::endl;
				Sleep(4000);
			}
		}
		else
		{
			if (tempFinalPoint2 - tempFigure2 == -1 && tempFigure != tempFinalPoint && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			}
			else
			{
				std::cout << "Impossible point(" << std::endl;
				Sleep(4000);
			}
		}
	}
}

void kStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2)
{
	map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('k', map[size - (tempFigure2)][tempFigure - 1].getColor());
	map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
}

void rStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2)
{
	int tempp = 0;
	bool hair = true, falling = false;
	if (tempFigure2 - tempFinalPoint2 != 0)
		hair = false;
	if (hair)
	{
		if (tempFigure > tempFinalPoint)
		{
			falling = true;
			tempp = tempFigure - tempFinalPoint;
		}
		else
		{
			falling = false;
			tempp = tempFinalPoint - tempFigure;
		}
	}
	else
	{
		if (tempFigure2 > tempFinalPoint2)
		{
			falling = true;
			tempp = tempFigure2 - tempFinalPoint2;
		}
		else
		{
			falling = false;
			tempp = tempFinalPoint2 - tempFigure2;
		}
	}
	for (int i = 0;i < tempp; ++i)
	{
		if (falling && !hair)
		{
			tempFigure2--;
			if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
			{
				map[size - (tempFigure2)][tempFigure - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2 + 1)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			}
			else
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(3000);
				break;
			}
		}
		else if (!falling && !hair)
		{
			tempFigure2++;
			if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
			{
				map[size - (tempFigure2)][tempFigure - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2 - 1)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			}
			else
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(3000);
				break;
			}
		}
		else if (falling && hair)
		{
			tempFigure--;
			if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
			{
				map[size - (tempFigure2)][tempFigure - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			}
			else
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(3000);
				break;
			}
		}
		else if (!falling && hair)
		{
			tempFigure++;
			if (!map[size - (tempFigure2)][tempFigure - 1].getNull())
			{
				map[size - (tempFigure2)][tempFigure - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 2].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			}
			else
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(3000);
				break;
			}
		}
	}
}

void eStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2)
{
	int temppf2 = tempFigure2;
	int temppf = tempFigure;
	if (tempFigure < tempFinalPoint && tempFigure2 < tempFinalPoint2)
	{
		do {
			temppf++;
			temppf2++;
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(1000);
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				break;
			}
			if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				std::cout << "No eliph!!" << std::endl;
				Sleep(2000);
				break;
			}

		} while (true);
	}
	else if (tempFigure < tempFinalPoint && tempFigure2 > tempFinalPoint2)
	{
		do {
			temppf++;
			temppf2--;
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(1000);
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				break;
			}
			if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				std::cout << "No eliph!!" << std::endl;
				Sleep(2000);
				break;
			}

		} while (true);
	}
	else if (tempFigure > tempFinalPoint && tempFigure2 < tempFinalPoint2)
	{
		do {
			temppf--;
			temppf2++;
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(1000);
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				break;
			}
			if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				std::cout << "No eliph!!" << std::endl;
				Sleep(2000);
				break;
			}

		} while (true);
	}
	else if (tempFigure > tempFinalPoint && tempFigure2 > tempFinalPoint2)
	{
		do {
			temppf--;
			temppf2--;
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				std::cout << "Impossible move" << std::endl;
				Sleep(1000);
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				break;
			}
			if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				std::cout << "No eliph!!" << std::endl;
				Sleep(2000);
				break;
			}

		} while (true);
	}
}

void hStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2)
{
	if (((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1) || (tempFigure - tempFinalPoint == 2 || tempFigure - tempFinalPoint == -2)) && ((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) || (tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2)))
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('h', map[size - (tempFigure2)][tempFigure - 1].getColor());
		map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
	}
	else
	{
		std::cout << "Impossible point!!" << std::endl;
		Sleep(1000);
	}
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	const int size = 8;
	Figure** map = mapCreate(size);
	firstFillingMap(map, size);
	do
	{
		if(map[0][3].getValue() == u8"♔" || map[7][3].getValue() == u8"♚")
			printMap(map, size);
			newStep(map, size);

			system("cls");
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
	bool checkEnemy = false;
	(map[size - (tempFigure2)][tempFigure - 1].getColor() == map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor()) ? checkEnemy = false : checkEnemy = true;
	if (map[size - (tempFigure2)][tempFigure - 1].getNull() && ((!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull() || checkEnemy)))
	{
		if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♘" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♞")
		{
			hStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2);
		}
		else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♔" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♛")
		{
			kStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2);
		}
		else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♙" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♟")
		{
			pStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2);
		}
		if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♖" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♜")
		{
			rStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2);
		}
		/*int tempFigure = 0, tempFigure2 = 0;
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
	std::cin >> tempFinalPoint2; */
		else if ((map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♗") || (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♝"))
		{

			eStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2);
		}
		if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♕")
		{
			quennStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2);
		}



	}
	else
	{
		std::cout << "Impossible point(" << std::endl;
		Sleep(4000);
	}

}
