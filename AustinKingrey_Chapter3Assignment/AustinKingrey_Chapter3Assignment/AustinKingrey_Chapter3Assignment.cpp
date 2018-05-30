//This program will take input of tickets name of the movie and tickets sold
//It will calculate and output, the amount of net profit made
#include "stdafx.h"
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	//variable declaration
	//my constant is the percentage of profit taken from the movie sales
	const double PROFIT_PERCENTAGE = .2;
	//constants for the children and adult ticket prices
	const double CHILDRENS_TICKET_PRICE = 6;
	const double ADULT_TICKET_PRICE = 10;
	string movieTitle;
	int adultTicketsSold;
	int childrensTicketsSold;

	//I will now start outputting to the user, and grabbing the input for the name of the movie
	cout << "Please enter the movie's title: " << endl;
	getline(cin, movieTitle);

	//Next to get the number of movies sold from the user.
	cout << "Please enter the number of adult movie tickets sold: " << endl;
	cin >> adultTicketsSold;
	cout << "Please enter the number of children movie tickets sold: " << endl;
	cin >> childrensTicketsSold;

	//manipulate the data
	double grossProfit = (adultTicketsSold * ADULT_TICKET_PRICE) + (childrensTicketsSold * CHILDRENS_TICKET_PRICE);
	double netProfit = grossProfit * PROFIT_PERCENTAGE;
	double distributorFee = grossProfit - netProfit;

	//display the formatted data back to the user
	cout << left << setprecision(2) << fixed;
	cout << left << setw(40) << "Movie Name:" << setw(10) << movieTitle << endl;
	cout << left << setw(40) << "Adult Tickets Sold:" << "$" << adultTicketsSold << endl;
	cout << left << setw(40) << "Childrens Tickets Sold:" << "$" << childrensTicketsSold << endl;
	cout << left << setw(40) << "Gross Box Office Profit:" << "$" << grossProfit << endl;
	cout << left << setw(40) << "Net Box Office Profit:" << "$" << netProfit << endl;
	cout << left << setw(40) << "Amount Paid to Distributor" << "$" << distributorFee << endl;

	system("pause");
	return 0;
}