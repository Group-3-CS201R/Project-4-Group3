#ifndef MACHINEBANK_H
#define MACHINEBANK_H
#include <iostream>
#include <vector>
#include <string>

// See corresponding .cpp for thorough comments of what these functions are respoonsible for

class MachineBank {
public:
	MachineBank();
	void calculateChange(double amountDue, double amountGiven);
	void replenishFunds();
	double getTotal();
private:
	int numTwenties;
	int numFives;
	int numOnes;
	int numQuarters;
	int numDimes;
	int numNickels;
	int numPennies;
	double bankTotal;
	double totalProfits;
};

#endif