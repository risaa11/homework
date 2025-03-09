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
				return u8"♟";
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

class Player
{
private:
	bool colorCurrentStep = true;
	bool playerTurn = true;
public:
	Player()
	{
		colorCurrentStep = true;
		playerTurn = true;
	}
	bool getColorCurrentStep()
	{
		// White == true  || Black == false
		return (colorCurrentStep) ? true : false;
	}
	void changeColorStep()
	{
		(this->colorCurrentStep) ? this->colorCurrentStep = false : this->colorCurrentStep = true;
	}
	void changePlayerTurn()
	{
		(this->playerTurn) ? this->playerTurn = false : this->playerTurn = true;
	}
	bool getPlayerTurn()
	{
		//player = true, bot = false
		return (playerTurn) ? true : false;
	}
};

Player player;

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

bool newStep(Figure** map, int size, int tempFigure, int tempFigure2, int tempFinalPoint, int tempFinalPoint2, bool botMode);

bool quennStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode)
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
					player.changePlayerTurn();
					return true;
					
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
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
					player.changePlayerTurn();
					return true;
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
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
					player.changePlayerTurn();
					return true;
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
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
					player.changePlayerTurn();
					return true;
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
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
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
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
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
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
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
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
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}

			} while (true);
		}

	}
}

bool pStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode)
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
					player.changePlayerTurn();
					return true;
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
				}
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
			}
		}
		else
		{
			if (tempFinalPoint2 - tempFigure2 == 1 && tempFigure != tempFinalPoint && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				player.changePlayerTurn();
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
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
					player.changePlayerTurn();
					return true;
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
				}
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
			}
		}
		else
		{
			if (tempFinalPoint2 - tempFigure2 == -1 && tempFigure != tempFinalPoint && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				player.changePlayerTurn();
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
			}
		}
	}
}

bool kStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode)
{
	map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('k', map[size - (tempFigure2)][tempFigure - 1].getColor());
	map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
	player.changePlayerTurn();
	return true;
}

bool rStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode)
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
				player.changePlayerTurn();
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
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
				player.changePlayerTurn();
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
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
				player.changePlayerTurn();
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
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
				player.changePlayerTurn();
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
		}
	}
}

bool eStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode)
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
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				player.changePlayerTurn();
				return true;
				break;
			}
			if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No eliph!!" << std::endl;
					Sleep(2000);
				}
				return false;
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
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				player.changePlayerTurn();
				return true;
				break;
			}
			if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No eliph!!" << std::endl;
					Sleep(2000);
				}
				return false;
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
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				player.changePlayerTurn();
				return true;
				break;
			}
			if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No eliph!!" << std::endl;
					Sleep(2000);
				}
				return false;
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
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
				map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
				player.changePlayerTurn();
				return true;
				break;
			}
			if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No eliph!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
}

bool hStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode)
{
	if (((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1) || (tempFigure - tempFinalPoint == 2 || tempFigure - tempFinalPoint == -2)) && ((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) || (tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2)))
	{
		map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('h', map[size - (tempFigure2)][tempFigure - 1].getColor());
		map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
		player.changePlayerTurn();
		return true;
	}
	else
	{
		if(botMode)
		{
			std::cout << "Impossible point!!" << std::endl;
			Sleep(1000);
		}
		return false;
	}
}

bool checkAbilityStep(int stepFromX, int stepFromY, Figure** map, bool botMode)
{
	if(!botMode)
	{
		if ((map[stepFromX][stepFromY].getColor() == 'B' && player.getColorCurrentStep()) || (map[stepFromX][stepFromY].getColor() == 'W' && !player.getColorCurrentStep()))
		{
			player.changeColorStep();
			return true;
		}
		else
		{
			std::cout << "Not your turn" << std::endl;
			Sleep(2000);
			return false;
		}
	}
	else
	{
		if ((map[stepFromX][stepFromY].getColor() == 'B' && player.getColorCurrentStep()) || (map[stepFromX][stepFromY].getColor() == 'W' && !player.getColorCurrentStep()))
			return true;
		else
			return false;
	}
}

void stepFigure(Figure** map, int size)
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

	newStep(map, size, tempFigure, tempFigure2, tempFinalPoint, tempFinalPoint2, false);
}

void botTurn(Figure** map, int size)
{

	int fromX = 0;
	int fromY = 0;
	int toX = 0;
	int toY = 0;
	bool close = false;
	do {
		fromX = rand() % 7;
		fromY = rand() % 7;
		if (map[fromX][fromY].getNull())
		{
			if (checkAbilityStep(fromX, fromY, map, true))
			{
				std::cout << "SO GOOD" << std::endl;
				for (int i = 0; i < 64; ++i)
				{
					toX = rand() % 7;
					toY = rand() % 7;
					if (map[toX][toY].getNull())
					{
						if (newStep(map, size, fromY + 1, fromX + 1, toY + 1, toX + 1, true))
						{
							std::cout << "SO NIIIIICE" << std::endl;
							Sleep(3000);
							close = true;
							break;
						}
					}
				}
				if (close)
					break;
			}
			else
			{
				std::cout << "SO BAD" << std::endl;
			}


		}
	} while (true);
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
		if (map[0][3].getValue() == u8"♔" || map[7][3].getValue() == u8"♚")
			printMap(map, size);
		if (!player.getPlayerTurn())
			botTurn(map, size);
		else
			stepFigure(map, size);
		system("cls");
	} while (true);
}


bool newStep(Figure** map, int size, int tempFigure, int tempFigure2, int tempFinalPoint, int tempFinalPoint2, bool botMode)
{
	char closeFunc = false;
	bool checkEnemy = false;

	(map[size - (tempFigure2)][tempFigure - 1].getColor() == map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor()) ? checkEnemy = false : checkEnemy = true;
	(checkAbilityStep(tempFigure2, tempFigure, map, botMode)) ? closeFunc = true : closeFunc = false;
	if (closeFunc)
	{
		if (map[size - (tempFigure2)][tempFigure - 1].getNull() && ((!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull() || checkEnemy)))
		{
			if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♘" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♞")
			{
				return (hStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode)) ? true: false;
			}
			else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♔" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♛")
			{
				return (kStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode))? true : false;
			}
			else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♙" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♟")
			{
				return (pStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode)) ? true : false;
			}
			if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♖" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♜")
			{
				return (rStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode)) ? true : false;
			}
			else if ((map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♗") || (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♝"))
			{
				return (eStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode)) ? true : false;
			}
			if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♕")
			{
				return (quennStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode)) ? true : false;
			}
		}
		else
		{
			if(!botMode)
			{
				std::cout << "Impossible point(" << std::endl;
				Sleep(2000);
			}
		}
	}
}
