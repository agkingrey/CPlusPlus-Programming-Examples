//This program will take input of tickets name of the movie and tickets sold
//It will calculate and output, the amount of net profit made
#include<pch.h>
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
	cout << "Movie Name:" << setw(10) << movieTitle << endl;
	cout << "Adult Tickets Sold:" << setw(10) << adultTicketsSold << endl;
	cout << "Childrens Tickets Sold:" << setw(10) << childrensTicketsSold << endl;
	cout << "Gross Box Office Profit:" << setw(10) << grossProfit << endl;
	cout << "Net Box Office Profit:" << setw(10) << netProfit << endl;
	cout << "Amount Paid to Distributor" << setw(10) << distributorFee << endl;
	
	return 0;
}