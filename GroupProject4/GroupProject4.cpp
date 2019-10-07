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
	/*
	string userInput;
	userInput = "p";
	MachineBank vendingMachineBank = MachineBank();
	Storage vendingStorageSystem = Storage();
	vendingStorageSystem.FillItemArray();

	
	while (userInput != "q" && userInput != "Q") {

		cout << vendingMachineBank.getTotal() << endl;
		vendingMachineBank.calculateChange(vendingStorageSystem.getItemCost("eweqo"), 3.89);
		cout << vendingMachineBank.getTotal() << endl;

		cout << endl << endl;
		vendingStorageSystem.TestPrintVect(vendingStorageSystem.getVect());
		vendingStorageSystem.CustomerRequestHandler("eweqo");
		cout << endl;
		vendingStorageSystem.TestPrintVect(vendingStorageSystem.getVect());

		cout << endl << vendingStorageSystem.getItemCost("fdfsdj") << endl;
		cout << "Would you like to purchase another item? Press Q(q) to quit the program --> " << endl;
		cin >> userInput;
	}
	*/

	// I put all of your tests in comments and left them above
	UserInterface vendingUI = UserInterface();
	vendingUI.selectionMenu();
	 
	return 0;
}