// AustinKingreyZSS.cpp : Defines the entry point for the console application.
//Austin Kingrey
//1/30/18
//agkingrey@dmacc.edu

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	//variable declaration
	int wait = 0;
	int current = 1;
	int userInput;

	//grab the user input for the game
	cout << "Please enter a number between 10 and 1000.";
	cin >> userInput;
	cin.ignore();

	//loop for game that will go through the numbers until the userinput no longer exceeds our counter
	while (current <= userInput)
	{
		//defining my flag variable inside the loop for a more limited scope
		int flag = 0;

		//next will be a series of if statement to print the correct numbers
		
		//if current is a multiple of 3 and five, print shwartz, and set the flag to one
		if (current %3 == 0 && current % 5 == 0) {
			cout << "Surprise" << endl;
			flag = 1;
			wait++;
		}

		//if current is a multiple of 5 and flag is 0, print schwartz and set flag to 1
		if (current %5 == 0 && flag == 0) {
			cout << "Schwartz" << endl;
			flag = 1;
			wait++;
		}

		//if currrent is a multiple of 3 and flag is 0, print zoom, and set flag to 1
		if (current % 3 == 0 && flag == 0) {
			cout << "Zoom" << endl;
			flag = 1;
			wait++;
		}
		//if the flag hasn't been set off by one of the previous conditions, print the number
		if (flag == 0) {
			cout << current << endl;
			wait++;
		}

		

		//if the wait flag is greater than 14, pause the program until the user hits the return key
		if (wait > 14) {
			cout << "....Please hit enter to continue.";
			
			cin.get();
			wait = 0;
		}

		//add one to the current counter
		current++;
	}
	return 0;
    
}

