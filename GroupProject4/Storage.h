#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <vector>
#include "FoodItem.h"

using namespace std;

// see corresponding .cpp file for more detailed comments about functionality

class Storage {
public:
	Storage();
	void FillItemArray();
	void CustomerRequestHandler(string name);
	void ReplenishItemAmount(string name);
	vector<vector<FoodItem>> getVect();
	double getItemCost(string name);
	int getItemStock(string name);
private:
	vector<vector<FoodItem> > rowColVector;
};

#endif