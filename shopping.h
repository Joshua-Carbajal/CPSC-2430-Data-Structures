// Carbajal, Joshua
// shopping.h
// 4/18/2020
// Purpose: Specification file for the ShoppingList class used to implement 
//					a Queue ADT to store a list of shopping items. 

#ifndef SHOPPING_H
#define SHOPPING_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ShoppingList 
{
	public:
	
		ShoppingList();
		// Default constructor
		// pre(conditions): None
		// post(conditions): Front and Rear assigned -1, size set to 4
		
		ShoppingList(const ShoppingList &);
		// Copy constructor
		// pre(conditions): 
		// post(conditions): Allocates queue with identical values 
		//									 from previous queue
		
		~ShoppingList(); 
		// Deletes queue
		// pre(conditions): Dynamically allocated queue
		// post(conditions): Deletes dynamically allocated queue
		
		void enqueue(string itemName);
		// Appends value to end of queue
		// pre(conditions): None
		// post(conditions): Appends items to queue
		
		void dequeue();
		// Removes value from head of queue
		// pre(conditions): Queue is not empty
		// post(conditions): Removes item, number of items decremented
		
		bool isEmpty();
		// Returns if queue is empty
		// pre(conditions): None
		// post(conditions): Returns true if Front and Rear assigned -1
		
		int getSize();
		// Acceses and returns the capacity atribute
		// pre(conditions): None
		// post(conditions): Returns number of items in queue
		
		//float getPrice(string name);
		// Returns price of item name
		// pre(conditions):
		// post(conditions): Returns price of item
		
		void printList();
		// Returns searched price of item to user
		// pre(conditions): None
		// post(conditions): Return item price, if not found returns 0
		
		void createList(ShoppingList& s2, string categ);
		// Adds items of user input category to queue
		// pre(conditions):
		// post(conditions): Items added to queue of input category 
		
		void doubleCapacity();
		// Doubles capacity of queue when full
		// pre(conditions): Queue must be full
		// post(conditions): Doubles capacity of queue
				
	private:
	
		string* arr;
		int capacity; // The queue size
		int front; // Subscript of the queue front
		int rear; // Subscript of the queue rear
		/* struct Item
		{
			string item_name;
			float price;
			string category;
			Item (string itemName, float priceValue, string productType) 
			{
				item_name = itemName;
				price = priceValue;
				category = productType;
			}
		}; */
};

#endif
