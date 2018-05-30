//Austin Kingrey
//Chapter 4
//Programming Challenge 14
#include <iostream>

using namespace std;

int main()
{
	//constant variable for check fees and minimum limit fee
	const double LESS_THAN_TWENTY = .10;
	const double TWENTY_TO_THIRTYNINE = .08;
	const double FOURTY_TO_FIFTYNINE = .06;
	const double SIXTY_PLUS = .04;
	const double MIN_LIMIT_FEE = 15;

	//variables to hold the account balance, number of checks, and checkFeeAmount
	double accountBalance;
	int numberOfChecks;
	double checkFeeAmount;
	double checkFeeDisplay = 0;
	double totalFees;

	//this will be my input validation variable, if it gets set to 0. the program will display errors to the user
	int inputValidator = 1;

	//grab user input on account balance and number of checks written for the month
	cout << "Please enter the Account balance: ";
	cin >> accountBalance;

	//input validation to urgently make customer aware of overdraft(see further validation below)
	if(accountBalance > 0)
	{
		cout << "Please enter number of checks written this month: ";
		cin >> numberOfChecks;
	}

	//Manipulate the data using if statements and equations
	//if statement will check if the account is too low for either overdraft or fees
	if(accountBalance < 0 )
	{
		inputValidator = 0;
		cout << "OVERDRAFT WARNING";
	}
	else if(accountBalance < 400)
	{
		accountBalance = accountBalance - MIN_LIMIT_FEE;
		checkFeeDisplay = 15;
	}

	//if else if that checks how many checks were written, and adds fees accordingly
	//also this is my input validation for checks being more than 0
	if(numberOfChecks <0)
	{
		inputValidator = 0;
		cout << "Negative amount of checks. Start again";
	}
	else if(numberOfChecks < 20)
		checkFeeAmount = numberOfChecks * LESS_THAN_TWENTY;
	else if(numberOfChecks < 40)
		checkFeeAmount = numberOfChecks * TWENTY_TO_THIRTYNINE;
	else if(numberOfChecks < 60)
		checkFeeAmount = numberOfChecks * FOURTY_TO_FIFTYNINE;
	else
		checkFeeAmount = numberOfChecks * SIXTY_PLUS;

	//Manipulating the data further using equations
	accountBalance = accountBalance - checkFeeAmount;
	totalFees = checkFeeAmount + checkFeeDisplay;

	//display back to the user if my input validator didn't get triggered
	if(inputValidator == 1)
	{
		cout.precision(2);
		cout << "Minimum Limit Fee: $" << fixed << checkFeeDisplay << "\n";
		cout << "Check Fee: $" <<checkFeeAmount <<"\n";
		cout << "Total Fees: $" << totalFees << "\n";
		cout << "Account Balance after Fees: $" << accountBalance;
	}
	return 0;
}



