#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <iostream>
#include <string>
#include <vector>
#include "FoodItem.h"
#include "MachineBank.h"
#include "Storage.h"

using namespace std;

class UserInterface {
	public:
		UserInterface(Storage storageSystem, MachineBank bankingSystem);
		UserInterface();
		int getChoice();
		void selectionMenu();
		void DisplayItems(vector<vector<FoodItem>> inventory);
		string ItemSelection(vector<vector<FoodItem>> inventory);
		void ItemPurchase( string name);
		bool IsValid(vector<vector<FoodItem>> inventory, string name);
	private:
		Storage vendingStorage;
		MachineBank vendingBank;
};

#endif