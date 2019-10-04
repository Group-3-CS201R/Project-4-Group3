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
	//FIXME: NEEDS TO BE REMOVED BEFORE SUBMITTING. THIS IS HERE FOR TESTING PURPOSES ONLY
	void TestPrintVect(vector<vector<FoodItem>> toPrint);
private:
	vector<vector<FoodItem> > rowColVector;
};

#endif