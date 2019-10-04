#ifndef FOODITEM_H
#define FOODITEM_H

#include <iostream>
#include <string>

using namespace std;

// See corresponding .cpp file for more detailed comments about functionality

class FoodItem {
public:
	FoodItem();
	FoodItem(string name, double price);
	void setName(string name);
	string getName();
	void setPrice(double price);
	double getPrice();
	int getNumItem();
	void restockItem();
	void removeItem();
	bool isOut();
private:
	string itemName;
	double itemPrice;
	int numItems; // Set to 5 in constructor
	int maxItems; // Set to 10 in constructor
};

#endif