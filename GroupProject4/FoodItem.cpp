#include "pch.h"
#include <iostream>
#include <string>
#include "FoodItem.h"

using namespace std;

// constructor that creates a new food object with a given name, price, and sets the number of this item that is available
FoodItem::FoodItem(string name, double price) {
	maxItems = 10;
	itemName = name;
	itemPrice = price;
	numItems = 5;
}

// default constructor. necessary to use vectors/arrays elsewhere in the Storage module
FoodItem::FoodItem() {
	maxItems = 10;
	itemName = "empty";
	itemPrice = 0;
	numItems = 0;
}

void FoodItem::setName(string name) {
	itemName = name;
}

string FoodItem::getName() {
	return itemName;
}

void FoodItem::setPrice(double price) {
	itemPrice = price;
}

double FoodItem::getPrice() {
	return itemPrice;
}

int FoodItem::getNumItem() {
	return numItems;
}

void FoodItem::restockItem() {
	numItems = maxItems;
}

// removes one from the count of the item if it is greater than 0 or leaves it at 0 otherwise. Returns no value
void FoodItem::removeItem() {
	if (numItems > 0) {
		numItems--;
	}
	else {
		numItems = 0;
	}
}

// FIXME: Might need to be removed
// checks if the item is out of stock. returns true if is, false otherwise
bool FoodItem::isOut() {
	if (numItems == 0) {
		return true;
	}
	else {
		return false;
	}
}