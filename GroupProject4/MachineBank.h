#ifndef MACHINEBANK_H
#define MACHINEBANK_H
#include <iostream>
#include <vector>
#include <string>

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
};

#endif