// AustinKingrey
// Chapter3
// agkingrey@dmacc.edu
// This program will take two user numbers, val1 val2, and compare
// them. This program will also add/divide/multiply/subtract/ratio the two numbers
//
// ANSWER TO 5:
// The difference when I changed my values from int to double, is that I got floating
// point precision now. Instead of all of my mathematical equations rounding off numbers
// and giving me innacurate answers, I'm getting more precise, decimal point numbers.
// This is important because when you divide, you need to make sure you are dividing by
// the right type, otherwise you may get the wrong solution.


#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	//variable declaration
	double val1 = 0; //holds user value 1
	double val2 = 0; //holds user value 2


	/*int exDeck [52][3]= {	{0,0,1},
							{1,1,1},
							{2,2,1},
							{3,3,1},
							{4,4,1},
							{5,5,1},
							{6,6,1},
							{7,7,1},
							{8,8,1},
							{9,9,1},
							{10,10,1},
							{11,11,1},
							{12,12,1},
							{13,13,1},
							{14,0,1},
							{15,1,1},
							{16,2,1},
							{17,3,1},
							{18,4,1},
							{19,5,1},
							{20,6,1},
							{21,7,1},
							{22,8,1},
							{23,9,1},
							{24,10,1},
							{25,11,1},
							{26,12,1},
							{27,13,1},
							{0,0,1},
							{1,1,1},
							{2,2,1},
							{3,3,1},
							{4,4,1},
							{5,5,1},
							{6,6,1},
							{7,7,1},
							{8,8,1},
							{9,9,1},
							{10,10,1},
							{11,11,1},
							{12,12,1},
							{13,13,1},
							
					   };



*/
	//will be used to input the values into the second column.
	int secondCollumnBuilder = 0;
	
	//creating and then populating my two dimmensional matrix.
	int deckMatrix[52][3];
	//navigating through rows
	for (int x = 0; x < 52; x++) 
	{
		//navigating through collumns
		for (int y = 0; y < 3; y++) 
		{
			//if statement to reset variable once it reaches 12.
			if (secondCollumnBuilder > 12)
			{
				secondCollumnBuilder = 0;
			}

			//this section will assign the variables to the matrix
			deckMatrix[x][0] = x; //first collumn
			deckMatrix[x][1] = secondCollumnBuilder; //second collumn
			deckMatrix[x][2] = 1; // third collumn
			
		}
		//add 1 to the second column builder
		++secondCollumnBuilder;
	}

	cout << deckMatrix[12][2] << endl;











	//now we'll get the two values from the user.
	cout << "Welcome to the program, please enter your first number.";
	cin >> val1;

	cout << "Please enter a second value." ;
	cin >> val2;
	
	//comparison of the two numbers
	if (val1 > val2)
	{
		cout << val1 << " is greater than " << val2 << endl;
	}
	else if (val1 < val2)
	{
		cout << val1 << " is less than " << val2 << endl;
	}
	else
	{
		cout << "Both numbers are equal." << endl;
	}

	//here is where I will perform the operations, and print.
	cout << "The sum is: " << val1 + val2 << endl;
	cout << "The difference is: " << val1 - val2 << endl;
	cout << "The product is: " << val1 * val2 << endl;
	cout << "The quotient is: " << val1 / val2 << endl;
	cout << "The ratio is: " << val1 << "/" << val2 << endl;
    return 0;
}
