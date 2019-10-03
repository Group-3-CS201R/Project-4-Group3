#include "pch.h"

#include <iostream>
#include <vector>
#include "MachineBank.h"

using namespace std;

MachineBank::MachineBank() {
	numTwenties = 0;
	numFives = 0;
	numOnes = 0;
	numQuarters = 50;
	numDimes = 50;
	numNickels = 50;
	numPennies = 50;
	bankTotal = (50 * 0.25) + (50 * 0.10) + (50 * 0.05) + (50 * 0.01);
}

void MachineBank::calculateChange(double amountDue, double amountGiven) {
	double changeTotal = amountGiven - amountDue;
	if (changeTotal > bankTotal) {
		cout << "Machine is out of change. Sorry!" << endl;
		return;
	}
	else if (changeTotal < 0) {
		cout << "Sorry, you don't have enough money." << endl;
		return;
	}
	double toWithdraw = changeTotal;
	int quartersChange = 0;
	int dimesChange = 0;
	int nickelsChange = 0;
	int penniesChange = 0;
	while (toWithdraw >= 0.01) {
		if (toWithdraw >= .25 && numQuarters >= 1) {
			toWithdraw -= 0.25;
			numQuarters--;
			quartersChange++;
			bankTotal -= 0.25;
		}
		else if (toWithdraw >= 0.10 && numDimes >= 1) {
			toWithdraw -= 0.10;
			numDimes--;
			dimesChange++;
			bankTotal -= 0.10;
		}
		else if (toWithdraw >= 0.05 && numNickels >= 1) {
			toWithdraw -= 0.05;
			numNickels--;
			nickelsChange++;
			bankTotal -= 0.05;
		}
		else if (toWithdraw >= 0.01 && numPennies >= 1) {
			toWithdraw -= 0.01;
			numPennies--;
			penniesChange++;
			bankTotal -= 0.01;
		}
	}

	cout << "Total coinage returned is: Quarters -> " << quartersChange << " Dimes -> " << dimesChange;
	cout << " Nickels -> " << nickelsChange << " Pennies -> " << penniesChange << endl;
}


void MachineBank::replenishFunds() {
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

double MachineBank::getTotal() {
	return bankTotal;
}