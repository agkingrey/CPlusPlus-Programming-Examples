/* Austin Kingrey PA2
// I approached this problem, starting with the assignment starter. I used this to 
// refresh on how to import txt files into c++.  I then proceded to organize the data
// into league, then wins.  I had to make sure to print the years they won as well, after
// I got everything else working. The biggest challenge, was figuring out how to 
// wrap my head around the data we were trying to store.  I only neeeded to reference how to concatenate strings in
// c++ again, to be able to make my years array work the way I wanted.
// http://www.cplusplus.com/reference/string/string/operator+/
*/

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	ifstream winsIn; //ifstream object to hold the winners from 1903-2015
	ifstream teamsIn; //will hold the alphabetical list of teams
	ifstream leagueIn; //will hold the list of which league each team is on
	
	int wins[30]; //int array to hold the number of wins held by each team, using the teams[] array as reference
	string teams[30]; //string array holding the teams captured by the text object
	string league[30]; //string array holding the leagues of each respective team relating to teams[] array as ref.
	string years[30]; //string array to hold the years corresponding to each team's wins

	int yearCount = 1903; //the year the world series started was 1903, used to populate years[]
	string input;  //used to store the data temporarily when itterating through loops
	int numOfTeams = 30; // number of teams in txt list
	int counter; // a simple counter variable

	//opening the objects using the text files
	teamsIn.open("Teams.txt");
	leagueIn.open("Leagues.txt");
	winsIn.open("WorldSeriesWinners.txt");

	counter = 0; 

	//responsible for filling the 30 spaces of my teams and wins array, by itterating
	//through the loop until getline fails grabbing input from my teams.txt file
	while (getline(teamsIn, input))
	{
		teams[counter] = input;
		wins[counter] = 0;
		counter++;
	}

	counter = 0;

	//filling my league array using my league.txt file, itterating until there
	//are no more lines to grab
	while (getline(leagueIn, input))
	{
		league[counter] = input;
		counter++;
	}

	counter = 0;

	//this will add one to the respective winner in the wins array, at the position correlating
	// to the team in the same position in the teams array. will itterate until there are no lines to be read
	while (getline(winsIn, input))
	{
		
		//itterating through teams[] checking to see which name is equal to the winner stored in input
		//then adding one to the corresponding win[] array.
		for (int x = 0; x < numOfTeams; x++)
		{
			if (teams[x] == input)
			{
				//concatenate the year count to the corresponding winning team
				years[x] += " " + to_string(yearCount);
				wins[x]++;
			}
		}
		counter++;
		yearCount++;
	}

	cout << "***NATIONAL LEAGUE***" << endl;

	//NATIONAL LEAGUE LOOP
	//this loop is going through the number of wins starting at the highest, 27, and moving down to 0
	for (int i = 27; i >= 0; i--)
	{
		//loop itterating through the wins[] array checking if any match i
		for (int z = 0; z < numOfTeams; z++)
		{
			//only print if national league
			if (league[z] == "National League")
			{
				//if wins[z] = i, print the team, and the other info required
				if (wins[z] == i)
				{
					cout << teams[z] << " - WINS: " << i << " - " << years[z] << endl;
				}
			}
		}
	}

	cout << endl << "***AMERICAN LEAGUE***" << endl;

	//AMERICAN LEAGUE LOOP, doing the same thing as above, but only printing al.
	for (int i = 27; i >= 0; i--)
	{
		for (int z = 0; z < numOfTeams; z++)
		{
			//only print if american league
			if (league[z] == "American League")
			{
				if (wins[z] == i)
				{
					cout << teams[z] << " - WINS: " << i << " - " << years[z] << endl;
				}
			}
		}
	}

	//closing my objects
	teamsIn.close();
	leagueIn.close();
	winsIn.close();

    return 0;
}

