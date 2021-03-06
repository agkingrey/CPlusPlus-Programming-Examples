// Austin Kingrey Assignment 3B Completed 4/4
// The purpose of this program is to create a stock simulation game following
// 4 popular companies.  The user has the goal of making 10,000 more off of their
// 100,000 cash reserve.  The user accomplishes this by buying and selling stocks
// that change price every day.  The trends are random, but have  a 3-8 day change period
// This program also give detailed information about each of the stocks. This program runs
// for 30 days, and then is done.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

//structure responsible for holding my stock data
struct Stock
{
	string symbol;
	string info;
	double revenue;
	double avgVol;
	double high;
	double low;
	string chairman;
	double current; //holds current stock value
	double sharesHeld; //holds how many shares the user has held currently
	int daysChange; // will hold the random number of days it takes the stocks to switch
	double trend; //will hold the stock's up or down trend 
};

//function responsible for showing the user the stock info they select
void printStruct(Stock &exStock)
{
	cout << "Ticker Sympol: " << exStock.symbol << endl;
	cout << "Revenue: " << exStock.revenue << endl;
	cout << "Avg. Vol.: " << exStock.avgVol << endl;
	cout << "52 Week High: " << exStock.high << endl;
	cout << "52 Week Low:  " << exStock.low << endl;
	cout << "Chairman: " << exStock.chairman << endl;
	cout << "Company Info: " << exStock.info << endl;
}

//function that ensures user doesn't take more money than they have, then adds to the amount of stocks for current company and returns the new cash reserve amount
double overdrawCheck(Stock &exStock, double exShares, double exCashReserve )
{
	double attemptedBuy = 0; //holds amount user is attempting to buy
	double newAmount = 0; //needed an extra number to make sure I maintained exCashReserve
	
	do 
	{
		newAmount = exCashReserve; //used to reset newAmount back to original
		attemptedBuy = exStock.current * exShares; 
		newAmount -= attemptedBuy;

		//overdraw check happens here
		if (newAmount < 0)
		{
			cout << "You aren't allowed to overdraw, enter a smaller number of shares to buy.";
			cin >> exShares;
		}
		//this will prevent infinite loop if user does not enter number
		//Source Credit:https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
		if (cin.fail())
		{
			cout << "Make sure you are typing numbers, not letters or symbols!" << endl;
			//clears cin
			cin.clear();
			//ignores any bad characters.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
	} while (newAmount < 0);
	
	//add the number of stocks to the current company's sharesHeld value
	exStock.sharesHeld += exShares;

	//once we're certain its a valid transaction, set exCashReserve to newAmount and return exCR
	exCashReserve = newAmount;
	return exCashReserve;
}

//function checks to make sure the user has enough shares to sell, then updates shares for that company and returns new Cash Reserve amount
double sellCheck(Stock &exStock, double exShares, double exCashReserve)
{
	double companyShares = exStock.sharesHeld; //using this so I can maintain the original amount of shares in exStock.sharesHeld
	do
	{
		companyShares = exStock.sharesHeld; // resets newShares to original every itteration of loop

		companyShares -= exShares;

		//sell check happens here
		if (companyShares < 0)
		{
			cout << "You have attempted to sell more shares than you have, try again. (Press 0 if you're stuck)" << endl;
			cin >> exShares;
		}
	} while (companyShares < 0);

	//calculate new cash reserve amount
	exCashReserve = exCashReserve + ((exStock.sharesHeld - companyShares) * exStock.current);
	//subtract the number of stocks held from the company's sharesHeld value
	exStock.sharesHeld = companyShares;

	return exCashReserve;
}

//function responsible for manipulating stocks every day
void stockAdjuster(Stock &exStock,int exDay)
{
	//once days(or exDay) is divisible by the random day of the stock, reroll a new number of days and new trend
	if ( exDay % exStock.daysChange == 0)
	{
		exStock.daysChange = rand() % 6 + 3;
		exStock.trend = rand() % 100;
	}

	//adding or subtracting stocks
	srand(time(NULL)); // creates more random numbers(had the issue of same number every time)
	int dollarsChanged = rand() % 15; // causes stocks to go up or down by up to 15 per time

	//subtracts from stock if trend is negative, adds if positive, does nothing if neutral
	if (exStock.trend <= 32)
	{
		exStock.current -= dollarsChanged;
	}
	if (exStock.trend >= 66)
	{
		exStock.current += dollarsChanged;
	}

	//readjusts stock's high or low measurements if need be
	if (exStock.current > exStock.high)
	{
		exStock.high = exStock.current;
	}
	if (exStock.current < exStock.low)
	{
		exStock.low = exStock.current;
	}
}

int main()
{
	//creates my apple stock info
	Stock apple;
	apple.symbol = "APPL";
	apple.info = "Apple Inc. (Apple), incorporated on January 3, 1977, designs, manufactures\nand markets mobile communication and"
		"media devices, personal computers and portable\ndigital music players and sells a variety of related software, services, peripherals,"
		"networking solutions\nand third-party digital content and applications. The Company's products and services include iPhone, iPad, Mac,\n"
		"iPod, Apple TV, a portfolio of consumer and professional software applications, the\niOS and OS X operating systems, iCloud and a variety"
		"of accessory, service and support offerings. The Company\noffers a range of mobile communication and media devices, personal computing products"
		"and portable digital music\nplayers, as well as a variety of related software, services, peripherals, networking solutions\nand third-party hardware"
		"and software products.\nIn addition, the Company offers its own software products, including iOS, the Company's mobile operating system;\nOS X, the"
		"Company's Mac operating system; and server and application software. The Company's\nprimary products include iPhone, iPad, Mac, iPod, iTunes, Mac App Store,";
		"iCloud, Operating System Software,\n Application Software and Other Application Software.";
	apple.revenue = 50577.00;
	apple.avgVol = 8007.73;
	apple.high = 123.81;
	apple.low = 89.47;
	apple.chairman = "Art Levinson";
	apple.current = 105;
	apple.sharesHeld = 0;
	apple.daysChange = rand() % 6 + 3; //produces a random number between 3 and 8
	apple.trend = rand() % 100; // will produce a number, 0 through 99, giving me my trend: 0-32 is neg., 33-65 is neut, 66-99 is pos. (check stockAdjuster func)

	//building my chipotle stock struct
	Stock chipotle;
	chipotle.symbol = "CMG";
	chipotle.info = "Chipotle Mexican Grill, Inc., incorporated on January 30, 1998, together with its\n"
		"subsidiaries operates Chipotle Mexican Grill restaurants. The Company's Chipotle\n"
		"Mexican Grill restaurants serve a menu of burritos, tacos, burrito bowls (a burrito\n"
		"without the tortilla) and salads. The Company operates approximately 1,970 Chipotle\n"
		"restaurants throughout the United States, over 10 in Canada, seven in England, four in\n"
		"France and one in Germany. The Company's restaurants include over 10 ShopHouse\n"
		"Southeast Asian Kitchen restaurants, serving Asian-inspired cuisine. The Company\n"
		"owned and operated approximately three Pizzeria Locale restaurants, a fast casual\n"
		"pizza concept, resulting in a totaling of approximately 2,010 restaurants. The Company\n"
		"sells gift cards which do not have an expiration date.";
	chipotle.revenue = 1898.00;
	chipotle.avgVol = 161937;
	chipotle.high = 575.00;
	chipotle.low = 384.80;
	chipotle.chairman = "Steve Ells";
	chipotle.current = 451;
	chipotle.sharesHeld = 0;
	chipotle.daysChange = rand() % 6 + 3;
	chipotle.trend = rand() % 100;

	//Disney
	Stock disney;
	disney.symbol = "DIS";
	disney.info = "The Walt Disney Company, incorporated on July 28, 1995, is a diversified\n"
		"entertainment company. The Company operates through five business segments:\n"
		"Media Networks, Parks and Resorts, Studio Entertainment, Consumer Products and \n"
		"Interactive.";
	disney.revenue = 12969;
	disney.avgVol = 2238425;
	disney.high = 120.65;
	disney.low = 86.25;
	disney.chairman = "Robert Iger";
	disney.current = 99;
	disney.sharesHeld = 0;
	disney.daysChange = rand() % 6 + 3;
	disney.trend = rand() % 100;

	//Tesla
	Stock tesla;
	tesla.symbol = "TSLA";
	tesla.info = "Tesla Motors, Inc., incorporated on July 1, 2003, designs, develops, manufactures\n"
		"and sells electric vehicles and energy storage products. The Company produces and\n"
		"sells two electric vehicles: the Model S sedan and the Model X sport utility vehicle\n"
		"(SUV). The Company has delivered over 107,000 Model S vehicles across the world. In\n"
		"addition to developing its own vehicles, it sells energy storage products. Its energy\n"
		"storage products include the seven kilowatt-hour and 10 kilowatt-hour Powerwall for\n"
		"residential applications, and the 100 kilowatt-hour Powerpack for commercial and\n"
		"industrial applications. The Company delivers energy storage products products under\n"
		"the Tesla Energy brand. It manufactures its products primarily at its facilities in Fremont,\n"
		"California, Lathrop, California, Tilburg, Netherlands and at its Gigafactory near Reno,\n"
		"Nevada. It is using battery packs manufactured at the Gigafactory for its energy storage\n"
		"products.";
	tesla.revenue = 2236.16;
	tesla.avgVol = 924800;
	tesla.high = 269.34;
	tesla.low = 141.13;
	tesla.chairman = "Elon Musk";
	tesla.current = 175;
	tesla.sharesHeld = 0;
	tesla.daysChange = rand() % 6 + 3;
	tesla.trend = rand() % 100;


	//***BEGINNING OF GAME (PART 1)***
	int selection = 5; // holds user selection
	cout << "Welcome to my stock game, type 1-4 to see info on your various stock options." << endl;
	cout << "After you feel acquainted, type 0 to begin the game.";

	//loop will continue until the user enters 0
	while (selection != 0)
	{
		//this will prevent infinite loop if user does not enter number
		//Source Credit:https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
		if (cin.fail())
		{
			cout << "Make sure you are typing numbers, not letters or symbols!";
			//clears cin
			cin.clear();
			//ignores any bad characters.
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cin >> selection;

		if (selection == 1)
		{
			cout << "Information for Apple" << endl;
			printStruct(apple);
		}
		else if (selection == 2)
		{
			cout << "Information for Chipotle" << endl;
			printStruct(chipotle);
		}
		else if (selection == 3)
		{
			cout << "Information for Disney" << endl;
			printStruct(disney);
		}
		else if (selection == 4)
		{
			cout << "Information for Tesla" << endl;
			printStruct(tesla);
		}
		else if (selection == 0)
		{
			cout << "It's time to play the game!" << endl;
			break;
		}
		else
		{
			cout << "Please enter a valid number" << endl;
		}
		cout << "\n***Please enter another number(1-4) or 0 to begin." << endl;
	}


	//***GAME PART TWO***
	selection = 100; // resetting my selection variable for use in next loop
	int stockSelection = 0; //holds which stock the user selects
	int day = 1; //holds which day we're on(why does c++ not have integrated date/time support?)
	double cashReserve = 100000; //the user starts with $100,000
	double newShares = 0; //holds how many shares the user is attempting to buy/sell

	cout << "You start with $100,000, your goal is to make 10,000 more in 30 days." << endl;

	//loop itterates for "30 days", day 1 being monday
	while (day <= 30)
	{
		//two if statements to skip day and itteration of loop if it is Sat. or Sun.
		if (day == 6 || day == 13 || day == 20 || day == 27)
		{
			cout << "The stock market isn't open on Saturdays, next day." << endl;
			day++;
			continue;
		}
		if (day == 7 || day == 14 || day == 21 || day == 28)
		{
			cout << "The stock market isn't open on Sundays, next day." << endl;
			day++;
			continue;
		}

		//nested loop will itterate until the user is done with all stock decisions for the day
		while (selection != 0)
		{
			//display current info
			cout << "Day :" << day << endl;
			cout << "APPL: " << apple.current << ", CMG: " << chipotle.current << ", DIS: " << disney.current << ", TSLA: " << tesla.current << endl;
			cout << "You currently have:" << endl;
			cout << "$" << cashReserve << " in cash reserves." << endl;
			cout << apple.sharesHeld << " shares APPL" << endl << chipotle.sharesHeld << " shares CMG" << endl;
			cout << disney.sharesHeld << " shares DIS" << endl << tesla.sharesHeld << " shares TSLA" << endl;

			//user decision
			cout << "Would you like to Buy(1), Sell(2), Info(3), or NextDay(0) [Please enter a number]?" << endl;
			cin >> selection;
			
			//this will prevent infinite loop if user does not enter number
			//Source Credit:https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
			if (cin.fail())
			{
				cout << "Make sure you are typing numbers, not letters or symbols!" << endl;
				//clears cin
				cin.clear();
				//ignores any bad characters.
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			//BUY DECISION LOGIC
			if (selection == 1)
			{
				cout << "Which Stock?: APPL(1), CMG(2), DIS(3), TSLA(4) [Please enter a number]" << endl;
				cin >> stockSelection;
				cout << "How many shares are you buying?: ";

				//user buying apple stocks
				if (stockSelection == 1)
				{
					cin >> newShares;
					cashReserve = overdrawCheck(apple, newShares, cashReserve);
				}
				//user buying chipotle shares
				else if (stockSelection == 2)
				{
					cin >> newShares;
					cashReserve = overdrawCheck(chipotle, newShares, cashReserve);
				}
				//user buying disney shares
				else if (stockSelection == 3)
				{
					cin >> newShares;
					cashReserve = overdrawCheck(disney, newShares, cashReserve);
				}
				//user buying tesla shares
				else if (stockSelection == 4)
				{
					cin >> newShares;
					cashReserve = overdrawCheck(tesla, newShares, cashReserve);
				}
				else
				{
					cout << "Please enter a valid number" << endl;
				}
			}
			//SELL DECISION LOGIC
			else if (selection == 2)
			{
				cout << "Which Stock?: APPL(1), CMG(2), DIS(3), TSLA(4) [Please enter a number]" << endl;
				cin >> stockSelection;
				cout << "How many shares are you selling?: ";

				//user selling apple shares
				if (stockSelection == 1)
				{
					cin >> newShares;
					cashReserve = sellCheck(apple, newShares, cashReserve);
				}
				//user selling chipotle shares
				else if (stockSelection == 2)
				{
					cin >> newShares;
					cashReserve = sellCheck(chipotle, newShares, cashReserve);
				}
				//user selling disney shares
				else if (stockSelection == 3)
				{
					cin >> newShares;
					cashReserve = sellCheck(disney, newShares, cashReserve);
				}
				//user selling tesla shares
				else if (stockSelection == 4)
				{
					cin >> newShares;
					cashReserve = sellCheck(tesla, newShares, cashReserve);
				}
				else
				{
					cout << "Please enter a valid number" << endl;
				}
			}
			//INFO LOGIC
			else if (selection == 3)
			{
				cout << "Which Stock?: APPL(1), CMG(2), DIS(3), TSLA(4) [Please enter a number]" << endl;
				cin >> stockSelection;

				//info for apple
				if (stockSelection == 1)
				{
					cout << "Information for Apple" << endl;
					printStruct(apple);
				}
				//info for chipotle
				else if (stockSelection == 2)
				{
					cout << "Information for Chipotle" << endl;
					printStruct(chipotle);
				}
				//info for disney
				else if (stockSelection == 3)
				{
					cout << "Information for Disney" << endl;
					printStruct(disney);
				}
				//info for disney
				else if (stockSelection == 4)
				{
					cout << "Information for Tesla" << endl;
					printStruct(tesla);
				}
				else
				{
					cout << "Please enter a valid number" << endl;
				}
			}	
		}
		//logic to check if the user has reached the 110,000 goals, congrat. them if they did
		if (cashReserve >= 110000)
		{
			cout << "Congrats on reaching your $110,000 goal, here's a cookie:)";
		}

		//adjusting stock price here, using stockAdjuster function
		stockAdjuster(apple, day);
		stockAdjuster(chipotle, day);
		stockAdjuster(disney, day);
		stockAdjuster(tesla, day);
		selection = 100; //resetting selection
		day++; //add one to the day count

		cout << apple.high << endl;
		cout << apple.low << endl;
	}

	//end results
	cout << "That's a wrap! Over 30 days your cash reserve is $" << cashReserve << ". That's a gain/loss of $" << cashReserve - 100000 << ". Press any key to exit" <<endl;
	cin >> selection;
    return 0;
}

