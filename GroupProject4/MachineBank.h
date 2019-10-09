#ifndef MACHINEBANK_H
#define MACHINEBANK_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// See corresponding .cpp for thorough comments of what these functions are respoonsible for

class MachineBank {
public:
	MachineBank();
	void calculateChange(double amountDue, double amountGiven);
	void replenishFunds();
	double getTotal();
	bool needsRestock();
private:
	int numQuarters;
	int numDimes;
	int numNickels;
	int numPennies;
	double bankTotal;
	double totalProfits;
};

#endif