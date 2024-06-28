/* Karen Mitchell
 * 6/6/24
 *banking app*/

#include <iostream>
#include <string>
#include <iomanip>
#include "banking.h"

using namespace std;

//Validation for user input.

double getValidDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a non-negative number." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any additional input
            return value;
        }
    }
}
int getValidIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a non-negative integer." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any additional input
            return value;
        }
    }
}
int main() {
    double initialAmount = 0.0, moDeposit = 0.0, anInterest = 0.0;
    int years = 0;

    // Display initial input menu without values
    InputDisplay(initialAmount, moDeposit, anInterest, years);

    // User input for amounts with validation
    initialAmount = getValidDoubleInput("Enter the Initial Investment Amount: ");
    moDeposit = getValidDoubleInput("Enter Monthly Deposit: ");
    anInterest = getValidDoubleInput("Enter Annual Interest: ");
    years = getValidIntInput("Enter Number of Years: ");

    // Call InputDisplay with the entered values
    InputDisplay(initialAmount, moDeposit, anInterest, years);

    keyToContinue();

    // Show balances without additional deposits
    withoutDeposit(initialAmount, anInterest, years);

    // Show balances with additional monthly deposits
    withDeposit(initialAmount, moDeposit, anInterest, years);

    return 0;

}