/* Karen Mitchell
 * 6/6/24
 *banking app*/

#include <iostream>
#include <string>
#include <iomanip>
#include "banking.h"

using namespace std;

//Function to continue at own pace

void keyToContinue() {
    cout << "Press any key to continue...";
    cin.get(); // Wait for a single key press
}

//function for borders

void displayBorder() {
	int totalWidth = 34; // Total width of the borders display lines

	//border
	cout << string(16, ' ') << string(totalWidth, '-') << endl;
}

//function to display initial input menu.

void InputDisplay(double initialAmount, double moDeposit, double anInterest, int years) {
	displayBorder();

	//titles
	cout << string(16, ' ') << string(11, '*') << " Data Input " << string(11, '*') << endl;
	cout << string(16, ' ') << "Initial Investment Amount: $" << fixed << setprecision(2) << initialAmount << endl;
	cout << string(16, ' ') << "Monthly Deposit: $" << fixed << setprecision(2) << moDeposit << endl;
	cout << string(16, ' ') << "Annual Interest: %" << fixed << setprecision(1) << anInterest << endl;
	cout << string(16, ' ') << "Number of years: " << years << endl;

	displayBorder();
}

//Fuction for static report without deposit.

double withoutDeposit(double initialInvestment, double annualInterest, int numberOfYears) {
	double totalAmount = initialInvestment;
	double interestAmount;

	//Table header
	cout << "\n" << string(12, ' ') << "Balance and Interest Without Additional Monthly Deposits" << string(12, ' ') << endl;
	cout << string(80, '=') << endl;
	cout << left << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(30) << "Year End Earned Interest" << endl;
	cout << string(80, '-') << endl;

	// Calculate yearly interest and year end total
	for (int i = 0; i < numberOfYears; i++) {
		interestAmount = totalAmount * (annualInterest / 100.0);
		totalAmount = totalAmount + interestAmount;
		cout << " " << left << setw(10) << (i + 1)
			<< "$" << setw(19) << fixed << setprecision(2) << totalAmount
			<< "$" << setw(29) << fixed << setprecision(2) << interestAmount << endl;
	}

	cout << string(80, '-') << endl;
	return totalAmount;
}

//Fuction for static report with deposit.

double withDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
	double totalAmount = initialInvestment;
	double yearlyTotalInterest;
	double interestAmount;


	//Table header
	
	cout << "\n" << string(12, ' ') << "Balance and Interest With Additional Monthly Deposits" << string(12, ' ') << endl;
	cout << string(80, '=') << endl;
	cout << left << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(30) << "Year End Earned Interest" << endl;
	cout << string(80, '-') << endl;

	// Calculate yearly interest and year end total
	for (int i = 0; i < numberOfYears; i++) {
		yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			interestAmount = (totalAmount + monthlyDeposit) * ((annualInterest / 100.0) / 12.0);
			yearlyTotalInterest = yearlyTotalInterest + interestAmount;
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}

		cout << " " << left << setw(10) << (i + 1)
			<< "$" << setw(19) << fixed << setprecision(2) << totalAmount
			<< "$" << setw(29) << fixed << setprecision(2) << yearlyTotalInterest << endl;
	}
	cout << string(80, '-') << endl;
	return totalAmount;
}