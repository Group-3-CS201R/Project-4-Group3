#include "pch.h"
#include <iostream>
#include <string>
#include "FoodItem.h"

using namespace std;

FoodItem::FoodItem(string name, double price) {
	maxItems = 10;
	itemName = name;
	itemPrice = price;
	numItems = 5;
}

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

void FoodItem::removeItem() {
	if (numItems > 0) {
		numItems--;
	}
}

bool FoodItem::isOut() {
	if (numItems == 0) {
		return true;
	}
	else {
		return false;
	}
}