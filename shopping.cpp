// Carbajal, Joshua
// shopping.cpp
// 4/18/2020
// Purpose: Implementation file for the ShoppingList class used to implement 
//					a Queue ADT to store a list of shopping items.

#include "shopping.h"

ShoppingList::ShoppingList() 
{
	capacity = 4;
	front = rear = -1;
	//Item* arr = new Item[capacity];
	arr = new string[capacity];
}

ShoppingList::ShoppingList(const ShoppingList &obj) 
{
	// Allocate the queue array
	arr = new string[obj.capacity];
	
	// Copy the other object's attributes
	capacity = obj.capacity;
	front = obj.front;
	rear = obj.rear;
	
	// Copy other object's queue array
	for (int i = 0; i < obj.capacity; i++)
		arr[i] = obj.arr[i];
}

ShoppingList::~ShoppingList()
{
	delete[] arr;
}

void ShoppingList::enqueue(string itemName) 
{
	/* Item singleItem;
	singleItem.item_name = itemName;
	singleItem.price = priceValue;
	singleItem.category = productType; */
	if ((front == 0 && rear == capacity - 1) || (front == rear + 1)) {
		doubleCapacity();
	} else {
		if (front == -1) {
			front = 0;
		}
		rear = (rear + 1) % capacity;
	}
	arr[rear] = itemName;
}

void ShoppingList::dequeue() 
{	
	if (isEmpty()) {
		cout << "Queue is empty. \n";
	} else {
		if (front == rear) {
			front = rear = -1;
		} else {
			cout << "Bought " << arr[front] << endl;
			front = (front + 1) % capacity;
		}
	}
}

bool ShoppingList::isEmpty() 
{
	if (front == -1 && rear == -1) {
		return true;
	} else {
		return false;
	}
}

int ShoppingList::getSize() 
{
	if (rear >= front) {
		return (rear - front) + 1;
	} else {
		return capacity - (front - rear) + 1;
	}
}

/* float ShoppingList::getPrice(string name) 
{
	int idx = 0;
	while (idx < capacity) {
		if (arr[idx] == name) {
			return arr[idx];
		}
		idx++;
	}
	return 0;
} */

void ShoppingList::printList() 
{
	if (isEmpty()) {
		cout << "Queue is empty. \n";
	}
	if (rear >= front) {
		for (int j = front; j <= rear; j++) {
			cout << j << ". " << arr[j] << endl;
		}
	} else {
		for (int n = 0; n <= rear; n++) {
			cout << n << ". " << arr[n] << endl;
		}
		for (int m = front; m < capacity; m++) {
			cout << m << ". " << arr[m] << endl;
		}
	}
}

void ShoppingList::createList(ShoppingList& s2, string categ)
{
	int count = 0;
	while (count < capacity) {
		if (arr[count] == categ) {
			s2.enqueue(arr[count]);
		}
		count++;
	}
}

void ShoppingList::doubleCapacity() 
{
	int numberItems = getSize(); // Returns number of items in queue
	string *tempArr = new string[capacity * 2];
	for (int i = 0; i < numberItems; i++) {
		tempArr[i] = arr[i];
	}
	capacity *= 2;
	front = 0;
	rear = numberItems;
	delete[] arr;
	arr = tempArr;
	cout << "Capacity doubled to X" << endl;
}




	
