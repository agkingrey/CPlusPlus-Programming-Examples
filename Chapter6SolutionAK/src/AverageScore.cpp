/**
 * Austin Kingrey
 * Chapter 6
 * Programming Challenge 11
 *This program takes 5 test scores, grabbed from the user, drops the lowest score and returns the average of the remainging 4.
 *If the two lowest scores are the same, the program instead, takes the average of all scores.  THis program uses various
 *function created by me, and then ran in the main driver.
 */
#include <iostream>
#include <iomanip>
using namespace std;

//global variable declaration
int testScore1 = 0;  //testScore1 global variable
int testScore2 = 0;  //testScore2 global variable
int testScore3 = 0;  //testScore3 global variable
int testScore4 = 0;  //testScore4 global variable
int testScore5 = 0;  //testScore5 global variable
int testScoreCounter = 1; //variable to display correct test score number to user
int averageDivider = 4; //number to divide the average by. This will change to 5 later, if two test score are the same

//function prototypes
void getScore(int &);
void calcAverage(int,int,int,int,int);
int findLowest(int, int, int, int, int);

//main driver
int main(){
//grab the 5 test scores
getScore(testScore1);
getScore(testScore2);
getScore(testScore3);
getScore(testScore4);
getScore(testScore5);

//use calcAverage to drop the lowest test score, find the average, and display to the user.
calcAverage(testScore1,testScore2,testScore3,testScore4,testScore5);

	return 0;
}

/*
*function to ask user for test score, storing it in a temp variable and input validating.
*If program fails first validation, run while loop to reverify until user
*puts in appropriate number
*/
void getScore(int &refVar){
	int tempTestScore = 0; //temporary local test score variable that hold user input

	//ask for user input
	cout << "Please enter test score number " << testScoreCounter << ": ";
	cin >> tempTestScore;

	//first part of input validation, if succeds, set refVar to testscore
	if(tempTestScore>= 0 && tempTestScore<=100){
		refVar = tempTestScore;
	}
	else{
		//while loop to input validate the ref. variable
		while(tempTestScore > 100 || tempTestScore < 0){
			cout << "Invalid Test Score, please enter another one: ";
			cin >> tempTestScore;
		}
		//set ref variable to temp test score
		refVar = tempTestScore;
	}
	//add one more to testScoreCounter for better user interface
	testScoreCounter++;
}

//calcAverage will calculate and display the average of the four highest scores
//this function will take in 5 score variables
void calcAverage(int ts1, int ts2, int ts3, int ts4, int ts5){
	int testTotal = ts1 + ts2 + ts3 + ts4 + ts5; //local variable to hold the total of the test scores
	double average = 0; //local variable to hold average

	//use findLowest function to return smallest score, or return 0 if two smallest are equal. then set that to the local variable lowestScore
	int lowestScore= findLowest(ts1,ts2,ts3,ts4,ts5);

	//subtract the lowestScore from testTotal, then find average by dividing by the averageDivider, cast testTotal to double to make equation double1
	testTotal -= lowestScore;
	average = (double)testTotal / averageDivider;

	//tell user what the average of the 4 highest scores, or 5 if the two lowest were the same
	if(averageDivider == 4){
		cout << "The average of the 4 test scores is: " << average;
	}
	else if(averageDivider ==5){
		cout << "The average of the 5 test scores is: " << average;
	}
}

/*findLowest will use multiple complex if statements to find the lowest
 * of 5 test scores, and then return the lowest score as an int, to be then
 * be subtracted from the score total in calcAverage
 */
int findLowest(int a, int b, int c, int d, int e){
	int scoreGettingDropped = 0; // local variable to be returned by the function

	//these if statements will see if each of the test scores, are the lowest
	//if yes, then scoreGettingDropped = that letter
	if(a<b && a<c && a<d && a<e){
		scoreGettingDropped=a;
	}
	else if(b<a && b<c && b<d && b<e){
		scoreGettingDropped=b;
	}
	else if(c<a && c<b && c<d && c<e){
		scoreGettingDropped=c;
	}
	else if(d<a && d<b && d<c && d<e){
		scoreGettingDropped=d;
	}
	else if(e<a && d<b && d<c && d<e){
		scoreGettingDropped=e;
	}
	//this will take care if the two lowest test scores are the same, dividing by all 5 instead of 4
	else{
		cout << "The two lowest test scores were the same, dividing by all 5 instead of 4. \n";
		averageDivider =5;
	}
	return scoreGettingDropped;
}


