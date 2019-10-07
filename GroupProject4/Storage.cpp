#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "FoodItem.h"
#include "Storage.h"

using namespace std;

// default constructor for the 
Storage::Storage() {
	//Average height for vending machine was 6 on Google Images
	rowColVector.resize(6);
	// width is 5 items wide, so each row must be resized accordingly
	for (int i = 0; i < rowColVector.size(); ++i) {
		rowColVector.at(i).resize(5);
	}
}

// Uses a file of snack names and prices to fill the rowColVector with FoodItems. returns no value
void Storage::FillItemArray() {
	ifstream inFS;
	string snackName;
	double snackPrice;
	// file is provided with program the name of the file is not dynamic, so name is hardcoded
	inFS.open("snacks_and_drinks.txt");
	if (!inFS.is_open()) {
		cout << "There was somehow a system error. Vending machine needs maintenance." << endl;
	}
	// outer loop accesses each row, inner loop accesses each column of the current row and sets the element at that row, column 
	// position to a new food item with the current snackName and snackPrice
	for (int i = 0; i < rowColVector.size(); ++i) {
		for (int j = 0; j < rowColVector.at(0).size(); ++j) {
			inFS >> snackName;
			inFS >> snackPrice;
			FoodItem temp = FoodItem(snackName, snackPrice);
			rowColVector.at(i).at(j) = temp;
		}
	}
}

// returns the rowColVector to be used elseswhere in the UserInterface module
vector<vector<FoodItem>> Storage::getVect() {
	return rowColVector;
}

// takes in the name of the item customer wishes to purchase and removes one of those items from the current stock
void Storage::CustomerRequestHandler(string name) {
	// outer loop accesses the column and inner loop accesses each element in the current row, searhing for
	// the item in the inventory that is to be removed
	for (int i = 0; i < rowColVector.size(); ++i) {
		for (int j = 0; j < rowColVector.at(0).size(); ++j) {
			if (rowColVector.at(i).at(j).getName() == name) {
				rowColVector.at(i).at(j).removeItem();
			}
		}
	}
}

//FIXME: Probably don't need this function.
// function to restock the item with the name that is passed as a parameter.
void Storage::ReplenishItemAmount(string name) {
	// outer loop accesses the column and inner loop accesses each element in the current row, searhing for
	// the item in the inventory that is to have its inventory replenished
	for (int i = 0; i < rowColVector.size(); ++i) {
		for (int j = 0; j < rowColVector.at(0).size(); ++j) {
			if (rowColVector.at(i).at(j).getName() == name) {
				rowColVector.at(i).at(j).restockItem();
			}
		}
	}
}

// function to find the cost of an item in the inventory using the passed name parameter
double Storage::getItemCost(string name) {
	// outer loop accesses the column and inner loop accesses each element in the current row, searhing for
	// the item in the inventory that needs to be found
	for (int i = 0; i < rowColVector.size(); ++i) {
		for (int j = 0; j < rowColVector.at(0).size(); ++j) {
			if (rowColVector.at(i).at(j).getName() == name) {
				return rowColVector.at(i).at(j).getPrice();
			}
		}
	}
}