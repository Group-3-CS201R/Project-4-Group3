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
	int getChoice();
	void selectionMenu();
	void DisplayItems(vector<vector<FoodItem>> inventory);
	vector<int> ItemSelection();
	void ItemPurchase(vector<vector<FoodItem>> inventory, vector<int> location);
	int GetPayment();
	int GetInt();
	private:
	void ItemRestock(vector<vector<FoodItem>> inventory);
	int RestockMenu();
	int GetQuantity();
};

#endif