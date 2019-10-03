#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "FoodItem.h"
#include "Storage.h"

using namespace std;

Storage::Storage() {
	//Average height for vending machine was 6 on Google Images. Width is dynamic(use push_back)
	rowColVector.resize(6);
	for (int i = 0; i < rowColVector.size(); ++i) {
		rowColVector.at(i).resize(5);
	}
}

void Storage::FillItemArray() {
	ifstream inFS;
	string snackName;
	double snackPrice;
	inFS.open("snacks_and_drinks.txt");
	if (!inFS.is_open()) {
		cout << "There was somehow a system error. Vending machine needs maintenance." << endl;
	}
	for (int i = 0; i < rowColVector.size(); ++i) {
		for (int j = 0; j < rowColVector.at(0).size(); ++j) {
			inFS >> snackName;
			inFS >> snackPrice;
			FoodItem temp = FoodItem(snackName, snackPrice);
			rowColVector.at(i).at(j) = temp;
		}
	}
}

//FIXME: THIS IS FOR TESTING ONLY. MUST REMOVE BEFORE SUBMITTING
void Storage::TestPrintVect(vector<vector<FoodItem>> toPrint) {
	for (int i = 0; i < toPrint.size(); ++i) {
		for (int j = 0; j < toPrint.at(0).size(); ++j) {
			cout << toPrint.at(i).at(j).getName() << " " << toPrint.at(i).at(j).getPrice() << " " << toPrint.at(i).at(j).getNumItem() << endl;
		}
	}
}

vector<vector<FoodItem>> Storage::getVect() {
	return rowColVector;
}

void Storage::CustomerRequestHandler() {

}

void Storage::ReplenishItemAmount(string name) {
	for (int i = 0; i < rowColVector.size(); ++i) {
		for (int j = 0; j < rowColVector.at(0).size(); ++j) {
			if (rowColVector.at(i).at(j).getName() == name) {
				rowColVector.at(i).at(j).restockItem();
			}
		}
	}
}