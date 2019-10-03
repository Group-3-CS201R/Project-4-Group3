#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "FoodItem.h"
#include "MachineBank.h"
#include "Storage.h"
#include "UserInterface.h"

using namespace std;

int main() {
	Storage vendingStorageSystem = Storage();
	vendingStorageSystem.FillItemArray();

	MachineBank vendingMachineBank = MachineBank();
	cout << vendingMachineBank.getTotal() << endl;
	vendingMachineBank.calculateChange(2.50, 3.89);
	cout << vendingMachineBank.getTotal() << endl;
	vendingMachineBank.replenishFunds();
	cout << vendingMachineBank.getTotal() << endl;


	cout << endl << endl;
	vendingStorageSystem.TestPrintVect(vendingStorageSystem.getVect());
	vendingStorageSystem.ReplenishItemAmount("eweqo");
	cout << endl;
	vendingStorageSystem.TestPrintVect(vendingStorageSystem.getVect());
	return 0;
}