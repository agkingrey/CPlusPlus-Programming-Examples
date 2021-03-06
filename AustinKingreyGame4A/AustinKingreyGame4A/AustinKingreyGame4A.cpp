// AustinKingreyGame4A.cpp : Defines the entry point for the console application.
//This text-based game uses a handful of classes to send a user around a cross formation
//Most of the instructions are in game. Use control + f5 if on Vis. Stud. to make sure the end screen doesn't
//get cut off. I have it set to "easy" right now, change the maxTurns variable at the top of 
//int main() to 40-45 if you want a challenge. Capitilization shows the start of different sections in code.

#include "stdafx.h"
#include <string>
#include <ctime>
#include <iostream>
using namespace std;

//Location class will hold all data for each space on the board
class Location 
{
	public:
		string name; //holds the name of the location
		int gem = 0; //This holds the gem (Can be gem number 1-4)
};

// will hold all the data for the user's character
class Character
{
	public:
		int currentLocation; //holds where the user is on the board currently
		bool inventory[5]; // array to hold the 4 inventory items (index 0 is not used in this game)
		string name; // holds the user's name

		//constructor that sets the player location to home at the start and sets the name
		Character(string lvName)
		{
			name = lvName;
			cout << "Hello there " << name << endl;
			currentLocation = 4;
			//sets all inventory items to false
			for (int i = 0; i <= 4; i++)
			{
				inventory[i] = false;
			}
		}

		//manages inventory (Either pick up or drop item)
		void inventoryManagement(Location* lvSpace)
		{
			int inventoryChoice = 0; // holds decision for inventory choice
			int gemChoice = 0; //holds decision on which gem to drop
				//If there is an item at current location, give the option to pick up or drop
				if (lvSpace[currentLocation].gem > 0)
				{
					cout << "Gem " << lvSpace[currentLocation].gem << " is currently at this location." << endl;
					cout << "Would you like to (1)Pick it up  (2)See current inventory (3)Cancel and return to main decision screen" << endl;
					cin >> inventoryChoice;
					//add gem to the inventory, using the gem number as reference
					if (inventoryChoice == 1)
					{
						inventory[lvSpace[currentLocation].gem] = true; //add to inventory
						lvSpace[currentLocation].gem = 0; //remove from board
						cout << "You picked up the gem, returning to main decision screen." << endl;
					}
					//shows current inventory
					else if (inventoryChoice == 2)
					{
						cout << "You have gem(s): ";
						for (int i = 0; i <= 4; i++)
						{
							if (inventory[i] != 0)
							{
								cout << i << " ";
							}
						}
						cout << endl;
						//any other number will return to main decision screen	
					}	
				}
				//if there is no gem there currently, give the user the choice to drop
				else if (lvSpace[currentLocation].gem == 0)
				{
					cout << "There is currently not a gem here." << endl;
					cout << "Would you like to (1)Choose a gem to drop  (2)See current inventory  (3)Cancel and return to main decision screen" << endl;
					cin >> inventoryChoice;
					//choose gem to drop if user selects 1
					if (inventoryChoice == 1)
					{
						cout << "Choose a gem to drop by entering their respective number, or type (0) to cancel." << endl << "Your current gems: ";
						for (int i = 0; i <= 4; i++)
						{
							if (inventory[i] != 0)
							{
								cout << i << " ";
							}
						}
						cout << endl;
						cin >> gemChoice;
						//if user chooses to drop gem 1,2,3,4
						if (gemChoice == 1 || gemChoice == 2 || gemChoice == 3 || gemChoice == 4)
						{
							if (inventory[gemChoice] == true)
							{
								inventory[lvSpace[currentLocation].gem] = false; //add to inventory
								lvSpace[currentLocation].gem = gemChoice; //remove from board
							}
							else 
							{
								cout << "That's not a valid gem choice, returning to main screen." << endl;
							}
						}
					}
					else if (inventoryChoice == 2)
					{
						cout << "You have gem(s): ";
						for (int i = 0; i <= 4; i++)
						{
							if (inventory[i] != 0)
							{
								cout << i << " ";
							}
						}
						cout << endl;
						//any other number will return to main decision screen
					}
				}
		}
		
		//***** NAVIGATION MANAGEMENT SECTION / FUNCTION ******
		bool navigation()
		{
			int lvNavChoice = 0; //holds the navigation choice of the user
			//Navigation unique to homebase, since user can go NESW
			if (currentLocation == 4)
			{
				cout << "Would you like to go (1)North (2)East (3)South (4)West?" << endl;
				cin >> lvNavChoice;
				//moving north
				if (lvNavChoice == 1) { currentLocation = 12; return true;}
				//moving east
				else if (lvNavChoice == 2) { currentLocation = 5; return true; }
				//moving south
				else if (lvNavChoice == 3) { currentLocation = 13; return true; }
				//moving west
				else if (lvNavChoice == 4) { currentLocation = 3; return true; }
				else { return false; }
			}
			//navigation for space 0
			else if (currentLocation == 0)
			{
				cout << "Type (1) To go East." << endl;
				cin >> lvNavChoice;
				if (lvNavChoice == 1) { currentLocation = 1;return true; }
				else 
				{
					cout << "You only had 1 choice, you're now going East." << endl;
					currentLocation = 1;
					return true;
				}
			}
			//navigation for space 8
			else if (currentLocation == 8)
			{
				cout << "Type (1) To go West." << endl;
				cin >> lvNavChoice;
				if (lvNavChoice == 1) { currentLocation = 7; }
				else
				{
					cout << "You only had 1 choice, you're now going West." << endl;
					currentLocation = 7;
				}
				return true;
			}
			//navigation for space 9
			else if (currentLocation == 9)
			{
				cout << "Type (1) To go South." << endl;
				cin >> lvNavChoice;
				if (lvNavChoice == 1) { currentLocation = 10; }
				else
				{
					cout << "You only had 1 choice, you're now going South." << endl;
					currentLocation = 10;
				}
				return true;
			}
			//navigation for space 16
			else if (currentLocation == 16)
			{
				cout << "Type (1) To go North." << endl;
				cin >> lvNavChoice;
				if (lvNavChoice == 1) { currentLocation = 15; }
				else
				{
					cout << "You only had 1 choice, you're now going North." << endl;
					currentLocation = 15;
				}
				return true;
			}
			//navigation for space 12
			else if (currentLocation == 12)
			{
				cout << "Would you like to go (1)North or (2)South?" << endl;
				cin >> lvNavChoice;
				if (lvNavChoice == 1) { currentLocation = 11; return true; } //North
				else if (lvNavChoice == 2) { currentLocation = 4; return true; } //South
				else { return false; }
			}
			//navigation for space 13
			else if (currentLocation == 13)
			{
				cout << "Would you like to go (1)North or (2)South?" << endl;
				cin >> lvNavChoice;
				if (lvNavChoice == 1) { currentLocation = 4; return true;} //North
				else if (lvNavChoice == 2) { currentLocation = 14; return true;} //South
				else { return false; }
			}
			//navigation for spaces 1 , 2 , 3 , 5, 6, 7
			else if (currentLocation <= 7)
			{
				cout << "Would you like to go (1)East or (2)West ?" << endl;
				cin >> lvNavChoice;
				//East Navigation
				if (lvNavChoice == 1) { currentLocation++; return true;}
				//West Navigation
				else if (lvNavChoice == 2) { currentLocation--; return true; }
				else { return false; }
			}
			//navigation for spaces 10, 11, 14, 15
			else if (currentLocation >= 10)
			{
				cout << "Would you like to go (1)North or (2)South?" << endl;
				cin >> lvNavChoice;
				if (lvNavChoice == 1) { currentLocation--; return true;} //North
				else if (lvNavChoice == 2) { currentLocation++; return true; } //South
				else { return false; }
			}
		}
};

//this function adds turns based on player status/ game status
//Player will increase turns used per inventory item held currently
int turnChanger(Character lvPlayer)
{
	int changeInTurns = 1; //will hold how many turns will be changed (1 by default)
	//adds up all inventory items currently held
	for (int i = 0; i < 4; i++)
	{
		changeInTurns += lvPlayer.inventory[i];
	}
	return changeInTurns;
}

//combat system, user has to guess correctly or forfeit another turn
bool headsOrTails(int lvTurn)
{
	srand(time(NULL));
	int randomNumber = rand() % 10 + 1;  //creates a random number, 1 through 10, and assisngs it to randomNumber
	int userGuess = 0; // holds the user's guess

	cout << "Current Turn: " << lvTurn << endl;
	cout << "You face the Home Base monster, he's a real jerk." << endl;
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
	int turn = 1; //holds which turn game is on
	int maxTurns = 50; // sets how long the game goes ********** DIFFICULTY*****************
	string playerName; //holds the character's name to pass to character object
	Location spaces[17]; //array to hold the 17 locations (16 plus home space which is index 4)
	//assign the names to my locations
	spaces[0].name = "Farthest West";
	spaces[1].name = "Farther West";
	spaces[2].name = "Far West";
	spaces[3].name = "West";
	spaces[4].name = "Home Base";
	spaces[5].name = "East";
	spaces[6].name = "Far East";
	spaces[7].name = "Farther East";
	spaces[8].name = "Farthest East";
	spaces[9].name = "Farthest North";
	spaces[10].name = "Farther North";
	spaces[11].name = "Far North";
	spaces[12].name = "North";
	spaces[13].name = "South";
	spaces[14].name = "Far South";
	spaces[15].name = "Farther South";
	spaces[16].name = "Farthest South";

	//Assign the gems to 4 spaces (Spoiler alert)
	spaces[1].gem = 1;
	spaces[5].gem = 2;
	spaces[10].gem = 3;
	spaces[15].gem = 4;

	//get character's name and assign it to new Character object
	cout << "Hello there adventurer." << endl << "Please enter your character's name: " << endl;
	cin >> playerName;
	Character player(playerName); //this is the user's character

	cout << playerName << " wakes up in the middle of an insane asylum, the room is freezing and the light is dim.  Suddenly, " << playerName;
	cout << " hears a grizzly voice come on to an overhead intercom.\"Welcome to Jerald Asylum, I think we both know why you're here."
		"  If you don't do exactly as I say, you are never leaving.  You see those four rooms going in each direction? There are "
		"4 going North, 4 going South, 4 going West, 4 going East, 16 in total.  In each wing of the asylum, there is one gem.  Collect all four of these gems"
		" and bring them to Home Base.  There's a catch, each one of these gems will weigh you down quite a bit. This will cause you one extra turn " 
		"per move you make for each gem held  "
		"If you don't collect the gems in " << maxTurns << " minutes(TURNS), you will be stuck here forever. Good luck, you'll need it.\"\n" << endl;
	cout << "You slowly pick yourself off the ground, and begin to look around.\n" << endl;
	//****MAIN GAMEPLAY LOOP****
	while (turn <= maxTurns)
	{
		int userChoice = 0; //holds the user's current choice,resets every turn
		while (userChoice != 1)
		{
			//cleanup
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Current Location: " << spaces[player.currentLocation].name << endl; //displays the current name of space
			cout << "Current Turn: " << turn << endl;//displays current turn

			//will print only if their is a gem at current location
			if (spaces[player.currentLocation].gem != 0)
			{
				cout << "Gem " << spaces[player.currentLocation].gem << " is stashed here." << endl;
			}
			else
			{
				cout << "No gems are here." << endl;
			}

			//main menu
			cout << "Would you like to (1)Make a Move  or  (2)Manage Your Inventory?" << endl;
			cin >> userChoice;
			if (userChoice == 2)
			{
				player.inventoryManagement(spaces);
			}
			else if (userChoice == 1)
			{
				//changes the player choice to avoid skipping a turn if user puts in wrong answer
				if (player.navigation() == false)
				{
					cout << "You entered in an invalid movement choice, returning to main menu." << endl;
					userChoice = 0;
				}
			}
		}
		//WIN STATE
		if (player.inventory[1] == 1 && player.inventory[2] == 1 && player.inventory[3] == 1 && player.inventory[4] == 1 && player.currentLocation ==4)
		{
			cout << "You hear the announcers voice come back onto the radio: \"Wow I can't believe you actually made it. I guess that means you're free to go.\"" << endl;
			cout << "Congrats " << playerName << "! You escaped the insane asylum, and can go home to your family and friends(If you have any) XD" << endl;
			break;
		}
		//combat system implementation will only run if user doesn't have all gems at home base
		if ((player.inventory[0] == 0 || player.inventory[1] == 0 || player.inventory[2] == 0 || player.inventory[3] == 0) && turn != 1 && player.currentLocation == 4)
		{
			//will run until the user wins
			while (headsOrTails(turn + 1) == false && turn <= maxTurns) 
			{ 
				//cleanup
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				turn++; 
			} 
		}
		turn += turnChanger(player);
	}
	//LOSE STATE
	if (turn > maxTurns)
	{
		cout << "You lose you dirty loser, go lose somewhere else.  Oh and" << playerName << "is trapped in the asylum forever." << endl;
	}

    return 0;
}

