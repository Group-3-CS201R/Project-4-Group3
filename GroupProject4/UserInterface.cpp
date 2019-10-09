#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "FoodItem.h"
#include "MachineBank.h"
#include "Storage.h"
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface(Storage storageSystem, MachineBank bankingSystem) {
	vendingStorage = storageSystem;
	vendingBank = bankingSystem;
}

int UserInterface::getChoice() {  // gets a menu choice from the user
	int choice = 0;
	while ((choice < 1) || (choice > 3)) {
		cout << "What would you like to do at the vending machine?\n";
		cout << "  1) View avaliable items\n";
		cout << "  2) Make an item selection\n";
		cout << "  3) Leave machine\n";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if ((choice < 1) || (choice > 3)) {
			cout << "Please enter a number selection between 1-3\n\n";
		}
	}
	return choice;
}

void UserInterface::selectionMenu() { // uses menu choices to select the correct function for the user
	int choice = 0;
	string itemName;
	while (choice != 3) {
		choice = getChoice();
		switch (choice) {
		case 1: 
			DisplayItems(vendingStorage.getVect());
			break;
		case 2: 
			itemName = ItemSelection(vendingStorage.getVect());
			ItemPurchase(itemName);
			break;
		case 3: cout << "\nHave a great day!\n";
			break;
		}
	}
	return;
}

void UserInterface::DisplayItems(vector<vector<FoodItem>> inventory) { // displays the list of vending machine items
	cout << fixed << setprecision(2);
	cout << "===== AVALIABLE ITEMS =====\n\n";
	for (int i = 0; i < inventory.size(); ++i) {
		for (int j = 0; j < inventory.at(0).size(); ++j) {
			cout << "ITEM: " << inventory.at(i).at(j).getName() << "\tPRICE: " << inventory.at(i).at(j).getPrice() << "\tQUANTITY: " << inventory.at(i).at(j).getNumItem() << endl;
		}
	}
	cout << endl;
	return;
}

string UserInterface::ItemSelection(vector<vector<FoodItem>> inventory) {  // gets a letter and number key and converts it to a vector with two integer to use as a location on the item vector
	string selection;
	cout << "What item from the menu would you like to purchase: " << endl;
	getline(cin, selection);
	while (!IsValid(inventory, selection)) {
		cout << "You must enter a valid entry from the menu." << endl;
		cout << "What item from the menu would you like to purchase:" << endl;
		getline(cin, selection);
	}
	return selection;
}

bool UserInterface::IsValid(vector<vector<FoodItem>> inventory, string name) { // checks if item is a valid choice in the machine
	for (int i = 0; i < inventory.size(); ++i) {
		for (int j = 0; j < inventory.at(0).size(); ++j) {
			if (inventory.at(i).at(j).getName() == name) {
				return true;
			}
		}
	}
	return false;
}

void UserInterface::ItemPurchase( string name) {  // takes an item to get its price and checks if there is enough money before vending, showing in suffiecent funds, or out of stock
	double amountPayed;
	cout << fixed << setprecision(2);
	if (vendingStorage.getItemStock(name) == 0) {
		cout << "Sorry, the machine is out of this item." << endl << endl;
		return;
	}
	cout << "Please insert at least $" << vendingStorage.getItemCost(name) << endl;
	cin >> amountPayed;
	if (amountPayed >= vendingStorage.getItemCost(name)) {
		cout << "Thank you for your purchase\nVENDING...\n\n";
		vendingStorage.CustomerRequestHandler(name);
		vendingBank.calculateChange(vendingStorage.getItemCost(name), amountPayed);
	}
	else {
		cout << "Insufficient funds\n";
	}
	return;
}

