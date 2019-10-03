#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "FoodItem.h"
#include "MachineBank.h"
#include "Storage.h"
#include "UserInterface.h"

using namespace std;

/* 
Every time you create a function, you need to put [type] UserInterface::funcName() {} (example: void UserInterface::PrintOptions() {})

FoodItem functions that you will need:
	getName();
	getPrice();
	getNumItem();

Storage functions that you will need:
	getVect(); [This gets the vecotr containing all of the elements of type vector<vector<FoodItem>>, so each FoodItem is located at an at(i).at(j)]


*/