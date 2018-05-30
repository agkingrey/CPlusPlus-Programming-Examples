/**
 * Austin Kingrey
 * Chapter 5
 * Programming Challenge 16
 * THis program takes in a balance, annual interest rate, and number of months since the beginning
 * of the account.  The program stores these, then asks the user for each month, how much they
 * deposited and withdrew.  It then adds all months up plus the monthly interest,
 * and returns the number of withdraws, deposits, total interest gained, and final balance
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double annualInterestRate, balance; //interest rate the user enters and balance of account
	int numOfMonthsSinceStart; //number of months since the beginning of account
	int totalDeposit, totalWithdraw; //a running count of how many deposits the user had
	double totalInterest; // a running total of the amount of interest earned in dollars

	//grab input from user for interest rate, balance , and number of months
	cout << "Please enter the initial balance of your account: ";
	cin >> balance;

	//if statement immedatedly terminating program if user enters negative value
	if(balance >= 0)
	{
		cout << "Please enter your annual interest rate in decimal format: ";
		cin >> annualInterestRate;

		cout << "Please enter the number of months since your account was started: ";
		cin >> numOfMonthsSinceStart;


		/** a for loop will ask the user how much was deposited and withdrawn each month,
		 *  depending on how many months they entered. if the account hits negative at any point
		 *  the program is to stop and display a message to the user
		*/
		for( int count =1; count <= numOfMonthsSinceStart; count++){
			double deposit = -1;   //deposit variable for my while loop to continue until user changes to positive
			double withdraw = -1;  //withdraw variable (read deposit variable above)
			double monthlyInterestRate = annualInterestRate/12;  //monthly interest rate is the annual divided by 12 per instructions
			double monthlyInterest; //to hold my monthly interest calculated below

			//while loop to make sure user enters positive number
			while(deposit < 0)
			{
				//grab amount withdrawn and deposited for the month
				cout << "Please enter the amount deposited in month " << count << ".  Negative numbers will not be accepted.";
				cin >> deposit;
			}

			//if statement adding to the running count of totalDeposit if deposit doesnt equal 0
			if(deposit != 0)
			{
				totalDeposit++;
			}

			//while loop to make sure user enters positive number
			while(withdraw < 0)
			{
				cout <<"Please enter the amount withdrawn in month " << count << ".  Negative numbers will not be accepted.";
				cin >> withdraw;
			}

			//if statement adding to the running count of totalWithdraw if withdraw doesnt equal 0
			if(withdraw !=0)
			{
				totalWithdraw++;
			}

			//if statement stopping program if it detects the balance is below 0
			if(balance < 0)
			{
				cout << "Balance is less than 0. Program terminated";
				//wanted to use an exit() but not until next chapter
				break;
			}
			//add the amount deposited and withdrawn to the balance
			balance = balance + (deposit - withdraw);

			//then calculate the monthly interest
			monthlyInterest = balance * monthlyInterestRate;

			//update balance and total interest
			totalInterest += monthlyInterest;
			balance += monthlyInterest;

			//let user know the month was recorded correctly
			cout << "Month " << count << " was recorded correctly. \n";
		}

		//update the user on what happened (set prec. and fixed for better readibility)
		cout.precision(2);
		cout << "Ending Balance: $" << fixed << balance <<"\n";
		cout << "Total Number of Deposits: " << totalDeposit <<"\n";
		cout << "Total Number of Withdraws: " << totalWithdraw <<"\n";
		cout << "Total Interest Earned: $" << totalInterest;
		}
	else
	{
		cout << "You entered a negative balance. Restart program";
	}
	return 0;
}
