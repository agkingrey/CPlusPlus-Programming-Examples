// HeadsOrTails.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std;

//combat system, user has to guess correctly or forfeit another turn
bool headsOrTails()
{
	srand(time(NULL));
	int randomNumber = rand() %10 + 1;  //creates a random number, 1 through 10, and assisngs it to randomNumber
	int userGuess = 0; // holds the user's guess

	cout << "You must guess heads or tails. If you guess wrong, you will lose a turn. Good Luck." << endl;
	cout << "(1)Heads or (2)Tails?" << endl;
	cin >> userGuess;

	//user guesses heads and is correct
	if (userGuess == 1 && randomNumber <= 5)
	{
		cout << "Heads was right, you got lucky this time." << endl;
		return true;
	}
	//user guesses tails and is correct
	else if (userGuess == 2 && randomNumber >= 6)
	{
		cout << "Tails was right, you lucky dog." << endl;
		return true;
	}
	else
	{
		cout << "WRONG, you lose a turn" << endl;
		return false;
	}
}





int main()
{

	while (headsOrTails() == false) {}
    return 0;
}

