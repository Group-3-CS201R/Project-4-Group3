// Group #3
// Project #4
// Names: Gabrial Nell, Nolan Rice, Bao Ngo
// Instructor: Michael Essmyer



#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "FoodItem.h"
#include "MachineBank.h"
#include "Storage.h"
#include "UserInterface.h"

using namespace std;

int main() {
	string userInput;
	userInput = "p";
	MachineBank vendingMachineBank = MachineBank();
	Storage vendingStorageSystem = Storage();
	vendingStorageSystem.FillItemArray();
	UserInterface vendingUI = UserInterface(vendingStorageSystem ,vendingMachineBank);
	vendingUI.selectionMenu();
	 
	return 0;
}