#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void ShowBoard(); // function to create the board
char Board[9]; // creating a board
void Intro(); // a small intro for visual effect
int WhoWon(); // win condition fucntion
bool MoveIsValid(int m);
int main()
{
	string Player1;
	string Player2;

	int WhoseTurn = true;
	int Move;
	int k = 0;
	Intro();

	Board[0] = ' ';
	Board[1] = '1';
	Board[2] = '2';
	Board[3] = '3';
	Board[4] = '4';
	Board[5] = '5';
	Board[6] = '6';
	Board[7] = '7';
	Board[8] = '8';
	Board[9] = '9';

	//Get players names for the game
	cout << "Player One - type your name!" << endl;
	cin >> Player1;
	cout << "Player Two - type your name!" << endl;
	cin >> Player2;
	system("cls");

	
	while (WhoWon() == false)
	{
		do
		{
			ShowBoard();
			if (WhoseTurn == true)
			{
				cout << Player1 << " Make your move";

			}

			else
			{
				cout << Player2 << " Make your move";

			}
			while (!(cin >> Move) || Move <= 0 || Move >= 10)
			{
				cin.clear();
				while (cin.get() != '\m') {}
			}
			k++; // add 1 to total moves
			system("cls");
		} while (MoveIsValid(Move) != true);



		switch (WhoseTurn)
		{
		case (1):
		{
			Board[Move] = 'X';
			WhoseTurn = 2;
			break;
		}
		case (2):
		{
			Board[Move] = '0';
			WhoseTurn = 1;
			break;
		}
		}



		if (WhoWon() == 1)
		{
			cout << Player1 << " You Won - Congratulations!" << endl;
		}
		else if (WhoWon() == 2)
		{
			cout << Player2 << " You Won - Congratulations!" << endl;
		}	
		else if (k >=9)
		{
			cout << "Stalemate! Well Played!" << endl;
			
		}
	}
		system("pause");

		return 0;
}
void ShowBoard()
{
	cout << endl << endl;
	cout << "     " << Board[1] << " | " << Board[2] << " | " << Board[3] << endl;
	cout << "     " << "--+---+--" << endl;
	cout << "     " << Board[4] << " | " << Board[5] << " | " << Board[6] << endl;
	cout << "     " << "--+---+--" << endl;
	cout << "     " << Board[7] << " | " << Board[8] << " | " << Board[9] << endl;
	cout << endl << endl;
}
void Intro()
{
	cout << "        ============================" << endl;
	cout << "        =========  WELCOME  ========" << endl;
	cout << "        ===========  TO  ===========" << endl;
	cout << "        ======   TIC TAC TOE  ======" << endl;
	cout << "        ============================" << endl << endl;
	cout << "        Press any key to begin..." << endl;
	_getch();
	system("cls");

}
int charToWinner(char ch) // additional fucntion to reduce the WhoWon function
{
	if (ch == 'X') 
	{
		return 1;
	}
	else 
	{
		return 2;
	}
}
int WhoWon()
{
	if (Board[1] == Board[2] && Board[2] == Board[3]) 
	{
		return charToWinner(Board[1]);
	}

	if (Board[4] == Board[5] && Board[5] == Board[6]) 
	{
		return charToWinner(Board[4]);
	}

	if (Board[7] == Board[8] && Board[8] == Board[9]) 
	{
		return charToWinner(Board[7]);
	}

	if (Board[1] == Board[4] && Board[4] == Board[7]) 
	{
		return charToWinner(Board[1]);
	}

	if (Board[2] == Board[5] && Board[5] == Board[8]) 
	{
		return charToWinner(Board[2]);
	}
	if (Board[3] == Board[6] && Board[6] == Board[9]) 
	{
		return charToWinner(Board[3]);
	}

	if (Board[1] == Board[5] && Board[5] == Board[9]) 
	{
		return charToWinner(Board[1]);
	}

	if (Board[3] == Board[5] && Board[5] == Board[7]) 
	{
		return charToWinner(Board[3]);
	
	}
	return 0;
}
bool MoveIsValid(int m)
{
	if (Board[m] != 'X' && Board[m] != '0')
	{
		return true;
	}
	else
	{
		return false;
	}
}