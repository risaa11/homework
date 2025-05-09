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
	bool firstStep = false;
public:
	Pawn(bool P)
	{
		this->P = P;
	}
	Pawn()
	{
		this->P = false;
	}
	void setTrueFirstStep()
	{
		this->firstStep = true;
	}

	bool getFirstStep()
	{
		return this->firstStep;
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
	bool whiteColor = false;
	bool whiteKingUnshakable = true;
	bool blackKingUnshakable = true;
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
		this->whiteKingUnshakable = true;
		this->blackKingUnshakable = true;
	}

	void changeWhiteKing()
	{
		this->whiteKingUnshakable = false;
	}

	void changeBlackKing()
	{
		this->blackKingUnshakable = false;
	}

	bool whiteKingUnshakableCheck()
	{
		return this->whiteKingUnshakable;
	}
	bool blackKingUnshakableCheck()
	{
		return this->blackKingUnshakable;
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
				return " ";
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
				return " ";
		}
	}

	char getCharValue()
	{
		if (E)
			return 'e';
		else if (Q)
			return 'q';
		else if (H)
			return 'h';
		else if (R)
			return 'r';
		else if (P)
			return 'p';
		else if (K)
			return 'k';
		else if (!E && !Q && !H && !R && !P && !K)
			return 'n';
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
				this->whiteColor = true;
			}
			if (s == 'p')
			{
				this->P = true;
				this->whiteColor = true;
			}
			if (s == 'r')
			{
				this->R = true;
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
				this->whiteColor = false;
			}
			if (s == 'p')
			{
				this->P = true;
				this->whiteColor = false;
			}
			if (s == 'r')
			{
				this->R = true;
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
	bool whiteMath = false;
	bool blackMath = false;
	bool mate = false;
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
	void setTrueMate()
	{
		this->mate = true;
	}
	void setFalseMate()
	{
		this->mate = false;
	}
	bool getMate()
	{
		return this->mate;
	}
	
	void setTrueBlackMate()
	{
		this->blackMath = true;
	}

	void setFalseBlackMate()
	{
		this->blackMath = false;
	}

	bool getBlackMate()
	{
		return this->blackMath;
	}

	void setTrueWhiteMate()
	{
		this->whiteMath = true;
	}

	void setFalseWhiteMate()
	{
		this->whiteMath = false;
	}

	bool getWhiteMate()
	{
		return this->whiteMath;
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
		std::cout << scrr << "   ";
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
	std::cout << "\n\n    A" << ' ' << "B" << ' ' << "C" << ' ' << "D" << ' ' << "E" << ' ' << "F" << ' ' << "G" << ' ' << "H" << ' ' << "           <<<<<<<<<<<<<------------\n" << std::endl;
	(player.getPlayerTurn()) ? std::cout << "Player turn" << std::endl : std::cout << "BOT turn" << std::endl;
	(player.getColorCurrentStep()) ? std::cout << "White player choose\n" << std::endl : std::cout << "Black player choose\n" << std::endl;
}


void firstFillingMap(Figure** array, int size)
{
	const char* emoji = u8"♟";
	for (int i = 0; i < size; ++i)
	{
		array[1][i].setValue('p', 'B');
		array[6][i].setValue('p', 'W');
		array[1][i].setTrueFirstStep();
		array[6][i].setTrueFirstStep();
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
	array[0][4].setValue('k', 'B');
	array[7][4].setValue('k', 'W');
	array[0][3].setValue('q', 'B');
	array[7][3].setValue('q', 'W');
}

bool newStep(Figure** map, int size, int tempFigure, int tempFigure2, int tempFinalPoint, int tempFinalPoint2, bool botMode, bool matCheck);

bool quennStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (((tempFigure - tempFinalPoint) == 0 || (tempFigure2 - tempFinalPoint2) == 0) || ((tempFigure + tempFinalPoint) == 0 || (tempFigure2 + tempFinalPoint2) == 0) || ((tempFigure + tempFinalPoint) == 0 || (tempFigure2 - tempFinalPoint2) == 0) || ((tempFigure - tempFinalPoint) == 0 || (tempFigure2 + tempFinalPoint2) == 0))
	{
		int temppf2 = tempFigure2;
		int temppf = tempFigure;
		if (tempFigure2 < tempFinalPoint2)
		{
			do {
				temppf2++;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure2 > tempFinalPoint2)
		{
			do {
				temppf2--;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure > tempFinalPoint)
		{
			do {
				temppf--;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure < tempFinalPoint)
		{
			do {
				temppf++;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else return false;
	}
	else
	{
		int a = (tempFinalPoint > tempFigure) ? tempFinalPoint - tempFigure : tempFigure - tempFinalPoint;
		int b = (tempFinalPoint2 > tempFigure2) ? tempFinalPoint2 - tempFigure2 : tempFigure2 - tempFinalPoint2;
		if (a == b)
		{
			int temppf2 = tempFigure2;
			int temppf = tempFigure;
			if (tempFigure < tempFinalPoint && tempFigure2 < tempFinalPoint2)
			{
				do {
					temppf++;
					temppf2++;
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
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
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
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
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
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
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
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
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
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
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
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
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
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
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
							Sleep(2000);
						}
						return false;
						break;
					}

				} while (true);
			}
			else return false;
		}
		else return false;
	}
}

bool pStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (map[size - (tempFigure2)][tempFigure - 1].getColor() == 'W')
	{
		if (!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull())
		{
			if (((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && (tempFigure - tempFinalPoint == 0)) || ((tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2) && map[size - (tempFigure2)][tempFigure - 1].getFirstStep()))
			{
				if (size - (tempFinalPoint2) < size - (tempFigure2))
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
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
			if ((tempFinalPoint2 - tempFigure2 == 1 && tempFigure != tempFinalPoint) && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
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
			if (((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && (tempFigure - tempFinalPoint == 0)) || ((tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2) && map[size - (tempFigure2)][tempFigure - 1].getFirstStep()))
			{
				if (size - (tempFinalPoint2) > size - (tempFigure2))
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
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
			if ((tempFinalPoint2 - tempFigure2 == -1 && tempFigure != tempFinalPoint) && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
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

bool kStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (map[size - (tempFigure2)][tempFigure - 1].getColor() == 'B')
		map[size - (tempFigure2)][tempFigure - 1].changeBlackKing();
	else
		map[size - (tempFigure2)][tempFigure - 1].changeWhiteKing();

	if (((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && tempFigure - tempFinalPoint == 0) || ((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1) && tempFigure2 - tempFinalPoint2 == 0) || ((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && ((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1))))
	{
		if (!matCheck)
		{
			map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('k', map[size - (tempFigure2)][tempFigure - 1].getColor());
			map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			player.changePlayerTurn();
			player.changeColorStep();
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool rStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	int temppf2 = tempFigure2;
	int temppf = tempFigure;
	if (tempFigure2 < tempFinalPoint2)
	{
		do {
			temppf2++;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
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
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else if (tempFigure2 > tempFinalPoint2)
	{
		do {
			temppf2--;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
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
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else if (tempFigure > tempFinalPoint)
	{
		do {
			temppf--;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
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
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else if (tempFigure < tempFinalPoint)
	{
		do {
			temppf++;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
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
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else return false;
}

bool eStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	int a = (tempFinalPoint > tempFigure) ? tempFinalPoint - tempFigure : tempFigure - tempFinalPoint;
	int b = (tempFinalPoint2 > tempFigure2) ? tempFinalPoint2 - tempFigure2 : tempFigure2 - tempFinalPoint2;
	if (a == b)
	{
		int temppf2 = tempFigure2;
		int temppf = tempFigure;
		if (tempFigure < tempFinalPoint && tempFigure2 < tempFinalPoint2)
		{
			do {
				temppf++;
				temppf2++;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
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
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
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
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
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
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
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
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
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
		else return false;
	}
	else return false;
}

bool hStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1) && (tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2)) || ((tempFigure - tempFinalPoint == 2 || tempFigure - tempFinalPoint == -2) && (tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1)))
	{
		if (!matCheck)
		{
			map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('h', map[size - (tempFigure2)][tempFigure - 1].getColor());
			map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			player.changePlayerTurn();
			player.changeColorStep();
		}
		return true;
	}
	else
	{
		if (botMode)
		{
			std::cout << "Impossible point!!" << std::endl;
			Sleep(1000);
		}
		return false;
	}
}

bool checkAbilityStep(int stepFromX, int stepFromY, Figure** map, bool botMode)
{
	if (!botMode)
	{
		if (!map[stepFromX][stepFromY].getNull())
		{
			std::cout << "SO BULL" << std::endl;
			Sleep(2000);
			return false;
		}
		if ((map[stepFromX][stepFromY].getColor() == 'B' && !player.getColorCurrentStep()) || (map[stepFromX][stepFromY].getColor() == 'W' && player.getColorCurrentStep()))
		{
			return true;
		}
		else
		{
			std::cout << "So Bad Move" << std::endl;
			Sleep(2000);
			return false;
		}
	}
	else
	{
		if (!map[stepFromX][stepFromY].getNull())
		{
			std::cout << "SO BULL" << std::endl;
			return false;
		}
		if ((map[stepFromX][stepFromY].getColor() == 'B' && !player.getColorCurrentStep()) || (map[stepFromX][stepFromY].getColor() == 'W' && player.getColorCurrentStep()))
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

	if (player.getMate())
	{
		if (!newStep(map, size, tempFigure, tempFigure2, tempFinalPoint, tempFinalPoint2, true, true))
		{
			std::cout << "Your king is checkmated, you can only move your king!!!!" << std::endl;
			Sleep(2000);
		}
	}
	else
		newStep(map, size, tempFigure, tempFigure2, tempFinalPoint, tempFinalPoint2, false, false);
}

void botTurn(Figure** map, int size)
{
	rand() %500 + 200;
	Sleep(200);
	int fromX = 0;
	int fromY = 0;
	int toX = 0;
	int toY = 0;
	do {
		fromX = rand() % 8 + 1;
		fromY = rand() % 8 + 1;
		if(map[size-fromX][fromY-1].getNull())
		{
			toX = rand() % 8 + 1;
			toY = rand() % 8 + 1;
			if (newStep(map, size, fromY, fromX, toY, toX, true, false))
			{
				break;
			}
		}

	} while (true);
}

std::string searchKing(Figure** map, int size)
{
	bool endGameCheckBlack = true;
	bool endGameCheckWhite = true;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j].getValue() == u8"♚")
			{
				endGameCheckWhite = false;
			}

			if (map[i][j].getValue() == u8"♔")
			{
				endGameCheckBlack = false;
			}
		}
	}
	if (endGameCheckBlack)
		return "WhiteLose";
	if (endGameCheckWhite)
		return "BlackLose";
	if (!endGameCheckBlack && !endGameCheckWhite)
		return "ALL";
}

bool checkDefaultKingAlive(Figure** map)
{
	if (map[0][3].getValue() != u8"♔")
	{
		std::cout << "White Player WIN!!!!" << std::endl;
		Sleep(2000);
		return false;
	}

	if (map[7][3].getValue() != u8"♚")
	{
		std::cout << "Black Player WIN!!!!" << std::endl;
		Sleep(2000);
		return false;
	}

	return true;
}

bool checkKingAlive(Figure** map, int size)
{
	if (searchKing(map, size) == "BlackLose")
	{
		std::cout << "Black Player WIN!!!!" << std::endl;
		Sleep(2000);
		return false;
	}
	if (searchKing(map, size) == "WhiteLose")
	{
		std::cout << "White Player WIN!!!!" << std::endl;
		Sleep(2000);
		return false;
	}
	return true;
}

bool matCheck(Figure** map, int size, bool botMode)
{
	bool stopSearch = false;
	int kingX = 0;
	int kingY = 0;
	for (int toX = 0; toX < size; ++toX)
	{
		for (int toY = 0; toY < size; ++toY)
		{
			if (map[toX][toY].getCharValue() == 'k' && (map[toX][toY].getColor() == 'W' && player.getColorCurrentStep() || map[toX][toY].getColor() == 'B' && !player.getColorCurrentStep()))
			{
				kingX = toX;
				kingY = toY;
				stopSearch = true;
				break;
			}
		}
		if (stopSearch)
			break;
	}

	for (int i = 0;i < size; ++i)
	{
		for (int j = 0; j < size; ++j)  
		{
			if (map[i][j].getNull() && map[i][j].getColor() != map[kingX][kingY].getColor())
			{
				player.changePlayerTurn();
				player.changeColorStep();
				if (newStep(map, size, j + 1, size - i, kingY + 1, size - kingX, true, true))
				{
					player.changePlayerTurn();
					player.changeColorStep();
					if (kingX == 0)
					{
						if(!botMode)
							std::cout << "\nBlack king has a check!!!\n" << std::endl;
						player.setTrueBlackMate();
						player.setFalseWhiteMate();
					}
					else
					{
						if(!botMode)
							std::cout << "\nWhite king has a check!!!\n" << std::endl;
						player.setTrueWhiteMate();
						player.setFalseBlackMate();
					}
					if(!botMode)
						Sleep(2000);
					player.setTrueMate();
					return true;
				}
				else
				{
					player.changePlayerTurn();
					player.changeColorStep();
				}
			}
		}
	}
	player.setFalseBlackMate();
	player.setFalseWhiteMate();
	player.setFalseMate();
	return false;
}

bool botMateTurn(Figure** map, int size)
{
	int tempX = 0;
	int tempY = 0;
	bool close = false;
	for(int tempX = 0; tempX < size; ++tempX)
	{
		for (int tempY = 0; tempY < size; ++tempY)
		{
 			if (map[tempX][tempY].getNull() && (map[tempX][tempY].getColor() == 'W' && player.getColorCurrentStep()) || (map[tempX][tempY].getColor() == 'B' && !player.getColorCurrentStep()))
			{
				for (int i = 0; i < size; ++i)
				{
					for (int j = 0; j < size; ++j)
					{
						close = false;
						if (map[i][j].getNull())
						{
							char tempVal = map[i][j].getCharValue();
							if (newStep(map, size, tempY + 1, size - tempX, j + 1, size - i, true, false))
							{
								player.changeColorStep();
								player.changePlayerTurn();
								matCheck(map, size, true);
								if (player.getMate())
								{
									map[tempX][tempY].setValue(map[i][j].getCharValue(), map[i][j].getColor());
									map[i][j].setValue(tempVal, (map[tempX][tempY].getColor() == 'W') ? 'B' : 'W');
								}
								else
								{
									close = true;
									return true;
								}
							}
						}
						else
						{
							if (newStep(map, size, tempY + 1, size - tempX, j + 1, size - i, true, false))
							{
								player.changeColorStep();
								player.changePlayerTurn();
								matCheck(map, size, true);
								if (player.getMate())
								{
									map[tempX][tempY].setValue(map[i][j].getCharValue(), map[i][j].getColor());
									map[i][j].setValue('n', (map[tempX][tempY].getColor() == 'W') ? 'W' : 'B');
								}
								else
								{
									close = true;
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	system("cls");
	printMap(map, size);
	(player.getBlackMate()) ? std::cout << "Black king has a CheckMate" << std::endl : std::cout << "White king has a CheckMate" << std::endl;
	Sleep(5000);
	player.changeColorStep();
	player.changePlayerTurn();
	return false;
}

int main()
{
	/*player.changePlayerTurn();
	player.changeColorStep();*/
	bool endGameCheck = false;
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	const int size = 8;
	Figure** map = mapCreate(size);
	firstFillingMap(map, size);
	do
	{
		endGameCheck = false;

		printMap(map, size);

		matCheck(map, size, false);

		if(!player.getMate())
		{
			//if (!player.getPlayerTurn())
			//	botTurn(map, size);
			//else
				stepFigure(map, size);
		}
		else
		{
			if (!player.getPlayerTurn())
			{
				if (!botMateTurn(map, size))
				{
					return 0;
				}
				else
				{
					player.changeColorStep();
					player.changePlayerTurn();
				}
			}
			else
				stepFigure(map, size);
		}


		system("cls");

	} while (true);
}



bool newStep(Figure** map, int size, int tempFigure, int tempFigure2, int tempFinalPoint, int tempFinalPoint2, bool botMode, bool matCheck)
{
	char closeFunc = false;
	bool checkEnemy = false;
	(map[size - (tempFigure2)][tempFigure - 1].getColor() == map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor()) ? checkEnemy = false : checkEnemy = true;
	if (map[size - (tempFigure2)][tempFigure - 1].getNull() && (!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull() || checkEnemy))
	{
		(checkAbilityStep(size - (tempFigure2), tempFigure - 1, map, botMode)) ? closeFunc = true : closeFunc = false;

		if (closeFunc)
		{
			if (map[size - (tempFigure2)][tempFigure - 1].getNull() && ((!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull() || checkEnemy)))
			{
				if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♘" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♞")
				{
					return (hStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♔" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♚")
				{
					return (kStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♙" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♟")
				{
					return (pStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♖" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♜")
				{
					return (rStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if ((map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♗") || (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♝"))
				{
					return (eStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♕" || (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♛"))
				{
					return (quennStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
			}
			else
			{
				if (!botMode)
				{
					std::cout << "Impossible point(" << std::endl;
					Sleep(2000);
				}
				return false;
			}
		}
	}
	else
	{
		if (!botMode)
		{
			std::cout << "Impossible move!!! He busy field" << std::endl;
			Sleep(2000);
		}
		return false;
	}
	return false;
}
