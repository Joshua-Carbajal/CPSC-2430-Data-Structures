// Carbajal, Joshua
// pa1.cpp
// 4/18/2020
// Purpose: Takes in a text file from user. Creates a Queue ADT 
//					that stores a list of shopping items. Each item has an
//					item name, price and category. This program tests thouroughly 
//					the ShoppingList class functions.

#include "shopping.h"

int main() {
	cout << "Could not implement stuct Item as data member of Shopping list. \n"
			 << "Implemented class and queue functions as best as possible. \n \n";
	ShoppingList s = ShoppingList();
	ifstream infile;
	infile.open("items.txt");
	if (infile) {
		string storeItem;
		cout << "List of items: " << endl;
		while(getline(infile, storeItem)) {
			int comma = storeItem.find(',');
			string itemName = storeItem.substr(0, comma);
			string remaining = storeItem.substr(comma + 1);
			int comma2 = remaining.find(',');
			string p = remaining.substr(0, comma2);
			float price = stof(p);
			string prodInfo = remaining.substr(comma2 + 1);
			cout << itemName << " - " << price << " - " << prodInfo << endl;
			s.enqueue(itemName);
		}
	} else {
		cout << "Error opening the file> \n";
	}
	infile.close();
	cout << "\n";
	
	// Testing class functions
	// Print shopping list
	cout << "Updated Shopping List" << endl;
	s.printList();
	cout << "\n";
	s.dequeue();
	s.dequeue();
	cout << "\n";
	cout << "Size of Shopping List: " << s.getSize() << endl;
	cout << "Updated Shopping List" << endl;
	s.printList();
	s.enqueue("mango");
	s.enqueue("headset");
	s.enqueue("pants");
	s.enqueue("apple");
	cout << "\n";
	cout << "Updated Shopping List" << endl;
	s.printList();
	cout << "\n" << "Second Shopping List" << endl;
	ShoppingList s2 = ShoppingList();
	s.createList(s2, "headset");
	s2.printList();
}