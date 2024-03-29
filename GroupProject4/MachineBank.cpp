#include "pch.h"
#include <cmath>
#include <iostream>
#include <vector>
#include "MachineBank.h"

using namespace std;

// Constructor for MachineBank that sets the bank to it's initial state
MachineBank::MachineBank() {
	numQuarters = 50;
	numDimes = 50;
	numNickels = 50;
	numPennies = 50;
	// keeps track of the total amount of money that is available for change at any one time
	bankTotal = (50 * 0.25) + (50 * 0.10) + (50 * 0.05) + (50 * 0.01);
	// keeps track of the total profits made during the entire run of the program
	totalProfits = 0;
}

// takes in the amount due for purchasing an item and the amount that the customer put into the machine to pay. Prints out the coinage
// needed to pay back the customer what wasn't needed to pay for the item. Returns no value.
void MachineBank::calculateChange(double amountDue, double amountGiven) {
	double changeTotal = amountGiven - amountDue;
	// checks if the bank is too low on funds to complete the transaction. If it is, the function is ended
	if (changeTotal > bankTotal) {
		cout << "Machine is out of change. Sorry!" << endl;
		return;
	}
	// checks if amount given to bank by customer is too little to complete the transaction. If it is, the function is ended
	else if (changeTotal < 0) {
		cout << "Sorry, you don't have enough money." << endl;
		return;
	}
	// total profits is tracked by keeping track of the amount due for each item purchased
	totalProfits += amountDue;
	// temporary variables to track the number of each coin type needed to give the customer their change due
	if (needsRestock()) replenishFunds();
	long long toWithdraw = (changeTotal * 100) + 0.05;
	int quartersChange = toWithdraw / 25;
	toWithdraw %= 25;
	numQuarters -= quartersChange;
	bankTotal -= (0.25 * quartersChange);
	int dimesChange = toWithdraw / 10;
	toWithdraw %= 10;
	numDimes -= dimesChange;
	bankTotal -= (0.10 * dimesChange);
	int nickelsChange = toWithdraw / 5;
	toWithdraw %= 5;
	numNickels -= nickelsChange;
	bankTotal -= (0.05 * nickelsChange);
	int penniesChange = toWithdraw % 5;
	numPennies -= (0.01 * penniesChange);
	bankTotal -= 0.01;
	// prints out the total coinage used to pay back the customer
	cout << "Total coinage returned is: Quarters -> " << quartersChange << " Dimes -> " << dimesChange;
	cout << " Nickels -> " << nickelsChange << " Pennies -> " << penniesChange << endl << endl;
}

bool MachineBank::needsRestock() {
	if (numQuarters <= 10 || numDimes <= 10 || numNickels <= 10 || numPennies <= 10)
	{
		return true;
	}
	return false;
}


// fills the machine coinage back to it's original state. Usually done when vending machine is restocked to ensure that
// there is enough change in the machine to give change back to customers
void MachineBank::replenishFunds() {
	// the following branches check if the number of a coin type in the bank needs to be replenished and also
	// recalculates bankTotal accordingly
	if (numQuarters < 50) {
		bankTotal -= (numQuarters * 0.25);
		numQuarters = 50;
		bankTotal += (numQuarters * 0.25);
	}
	if (numDimes < 50) {
		bankTotal -= (numDimes * 0.10);
		numDimes = 50;
		bankTotal += (numDimes * 0.10);
	}
	if (numNickels < 50) {
		bankTotal -= (numNickels * 0.05);
		numNickels = 50;
		bankTotal += (numDimes);
	}
	if (numPennies < 50) {
		bankTotal -= (numPennies * 0.01);
		numPennies = 50;
		bankTotal += (numPennies * 0.01);
	}

}

// getter to get the total amount in the bank. Returns a double representing the total available change in the bank
double MachineBank::getTotal() {
	return bankTotal;
}