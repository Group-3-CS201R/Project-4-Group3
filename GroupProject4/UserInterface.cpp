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

/* 
Every time you create a function, you need to put [type] UserInterface::funcName() {} (example: void UserInterface::PrintOptions() {})
void UserInterface::PrintOptions() {
}

Requirements for other functions:

Whatever function you use to get user input needs to return a name in the form of a string

FoodItem functions that you will need:
	getName();
	getPrice();
	getNumItem();

Storage functions that you will need:
	getVect(); [This gets the vecotr containing all of the elements of type vector<vector<FoodItem>>, so each FoodItem is located at an at(i).at(j)]
*/

int UserInterface::getChoice() {  // gets a menu choice from the user
	int choice = 0;
	while ((choice < 1) || (choice > 4)) {
		cout << "What would you like to do at the vending machine?\n";
		cout << "  1) View avaliable items\n";
		cout << "  2) Make an item selection\n";
		cout << "  3) Restock machine\n";
		cout << "  4) Leave machine\n";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if ((choice < 1) || (choice > 4)) {
			cout << "Please enter a number selection between 1-4\n\n";
		}
	}
	return choice;
}

void UserInterface::selectionMenu() { // uses menu choices to select the correct function for the user
	Storage vendingStorageSystem = Storage();
	vendingStorageSystem.FillItemArray();
	int choice = 0;
	while (choice != 4) {
		choice = getChoice();
		switch (choice) {
		case 1: 
			DisplayItems(vendingStorageSystem.getVect());
			break;
		case 2: 
			ItemPurchase(vendingStorageSystem.getVect(), ItemSelection());
			break;
		case 3: 
			ItemRestock(vendingStorageSystem.getVect());
			break;
		case 4: cout << "\nHave a great day!\n";
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
			cout << static_cast<char>('A' - 1 + (i+1)) << j+1 << " - ITEM: " << inventory.at(i).at(j).getName() << "\tPRICE: " << inventory.at(i).at(j).getPrice() << "\tQUANTITY: " << inventory.at(i).at(j).getNumItem() << endl;
		}
	}
	cout << endl;
	return;
}

vector<int> UserInterface::ItemSelection() {  // gets a letter and number key and converts it to a vector with two integer to use as a location on the item vector
	int row;
	int column=1;
	char charRow='a';

	while (((charRow != 'A') && (charRow != 'B') && (charRow != 'C') && (charRow != 'D') && (charRow != 'E')) || !((column > 0) && (column < 6))) {
		
		cout << "Choose an item with key A-E + 1-6 (i.e. A2) \n";
		cin >> charRow;
		cin >> column;
		charRow = toupper(charRow);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (((charRow != 'A') && (charRow != 'B') && (charRow != 'C') && (charRow != 'D') && (charRow != 'E')) || (column < 1) || (column > 6)) {
			cout << "Please use a valid key (A-E + 1-6)\n\n";
		}
	}
	vector<int> selection{ static_cast<int>(charRow - 65), column - 1 };
	return selection;
}

void UserInterface::ItemPurchase(vector<vector<FoodItem>> inventory, vector<int> location) {  // takes an item and its location to get its price and checks if there is enough money before vending, showing in suffiecent funds, or out of stock
	cout << fixed << setprecision(2);
	if (inventory.at(location.at(0)).at(location.at(1)).getNumItem() >= 1) {
		cout << "Please insert at least $" << inventory.at(location.at(0)).at(location.at(1)).getPrice() << endl;
		if (GetPayment() > inventory.at(location.at(0)).at(location.at(1)).getPrice()) {
			cout << "Thank you for your purchase\nVENDING...\n\n";
			// add bank and storage adjustments
		}
		else {
			cout << "Insufficient funds\n";
		}
	}
	else {
		cout << "OUT OF STOCK\n";
	}
	return;
}

int UserInterface::GetPayment() { // gets the number of each bill and returns it as a total, while writing this I realised that this needs to change the bank totals for each bill
	int tens;
	int fives;
	int ones;
	cout << "How many tens, fives and ones will you be using?\n";
	cout << "Tens ==> ";
	tens = GetInt();
	cout << "Fives ==> ";
	fives = GetInt();
	cout << "Ones ==> ";
	ones = GetInt();
	int payment = (10 * tens) + (5 * fives) + (1 * ones);
	return payment;
}

int UserInterface::GetInt() { // gets a positive integer for the bills
	int num = -1;
	while (num < 0) {
		try {
			cin >> num;
			if (!cin || (num < 0))
				throw 1;
		}
		catch (int error) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "(Please enter a postive integer or zero)\n";
			num = -1;
		}
	}
	return num;
}

void UserInterface::ItemRestock(vector<vector<FoodItem>> inventory) {  // asks the user what they want to restock and how much they want to restock to

	int choice = RestockMenu();
	int stock = GetQuantity();
	vector<int> location;
	switch (choice) {
	case 1:
		location = ItemSelection();
		// change storage number here inventory.at(location.at(0)).at(location.at(1))
		cout << "The item has been restocked\n\n";
		break;
	case 2:
		for (int i = 0; i < inventory.size(); ++i) {
			for (int j = 0; j < inventory.at(0).size(); ++j) {
			// change storage number here inventory.at(i).at(j)
			}
		}
		cout << "The item has been restocked\n\n";
		break;
	case 3:
		break;
		}
	return;
}

int UserInterface::RestockMenu() {  // the printed menu for restocking
	int choice = 0;
	while ((choice < 1) || (choice > 3)) {
		cout << "Would you like to restock one item or all items? \n";
		cout << "   1) One Item\n";
		cout << "   2) All Items\n";
		cout << "   3) Go back\n";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if ((choice < 1) || (choice > 3)) {
			cout << "Please enter a number selection between 1-\n\n";
		}
	}
	return choice;
}

int UserInterface::GetQuantity() {  // Gets a number for the items to be stocked to
	int stock = 0;
	cout << "How many items will be stocked? ";
	while (!(stock >= 1 && stock <= 10)) {
		cin >> stock;
		if (!(stock >= 1 && stock <= 10)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "(Please enter a number between 1-10)\n";
			stock = 0;
		}
	}
	return stock;
}

