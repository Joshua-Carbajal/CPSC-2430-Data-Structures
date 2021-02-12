// Carbajal, Joshua
// recursiveStack.cpp
// 5/4/2020
// Purpose: Implementation file for the RecursiveStack class.

#include <iostream> 
#include "recursiveStack.h"
using namespace std;
   
RecursiveStack::RecursiveStack() 
{
	front = nullptr; // Pointer to front of linked list
}

// Prior CPSC 1230 Lab 8 code sourced to implement destructor
// function  
RecursiveStack::~RecursiveStack() 
{
	StackNode* currNode = nullptr;
	StackNode* nextNode = nullptr;
	currNode = front;
	while (currNode != nullptr) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

// Prior CPSC 1230 Lab 8 code sourced to implement copy
// constructor function
RecursiveStack::RecursiveStack(const RecursiveStack &obj)
{
	StackNode* helper = obj.front;
	while (helper != nullptr) {
		push(helper->data);
		helper = helper->next;
	}
	StackNode* currNode = front;
	StackNode* prevNode = nullptr;
	StackNode* nextNode = nullptr;
	while (currNode != nullptr) {
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	front = prevNode;
}

// Prior CPSC 1230 Lab 8 code sourced to implement copy
// assignment function
RecursiveStack& RecursiveStack::operator=(const RecursiveStack &obj)
{
	if (this != &obj) {
		while (!isEmpty()) {
			StackNode* currNode = nullptr;
			StackNode* nextNode = nullptr;
			currNode = front;
			while (currNode != nullptr) {
				nextNode = currNode->next;
				delete currNode;
				currNode = nextNode;
			}
		}
		StackNode* helper = obj.front;
		while (helper != nullptr) {
			push(helper->data);
			helper = helper->next;
		}
		StackNode* currNode = front;
		StackNode* prevNode = nullptr;
		StackNode* nextNode = nullptr;
		while (currNode != nullptr) {
			nextNode = currNode->next;
			currNode->next = prevNode;
			prevNode = currNode;
			currNode = nextNode;
		}
		front = prevNode;
	}
	return *this;
}

void RecursiveStack::push(int digit) 
{
  StackNode* newNode = nullptr; // Pointer to new node
	newNode = new StackNode;
	newNode->data = digit;
	newNode->next = nullptr;
	if (isEmpty()) {
		front = newNode;
	} else {
		newNode->next = front;
		front = newNode;
	}
}

void RecursiveStack::pop(int &digit) 
{
	StackNode* temp = nullptr; // Temporary pointer
	if (isEmpty()) {
		cout << "The stack is empty. \n";
	} else {
		digit = front->data;
		temp = front->next;
		delete front;
		front = temp;
	}
}
  
void RecursiveStack::top(int &digit) 
{
	if (isEmpty()) {
		cout << "The stack is empty. \n";
	} else {
		digit = front->data;
	}
}

// Prior CPSC 1230 Lab 8 code sourced to implement empty function                             
bool RecursiveStack::isEmpty() 
{
	bool status;
	if (front == nullptr) {
		status = true;
	} else {
		status = false;
	}
	return status;
}

void RecursiveStack::recInsert(int posInteger)
{
	if (posInteger == 0) {
		return;
	} else {
		int digit = posInteger % 10; // Single digit from integer
		push(digit);
		recInsert(posInteger / 10);
	}
}

// Prior CPSC 1230 Lab 8 code sourced to implement print
// function
void RecursiveStack::print()
{
	StackNode* currNode = front; //Pointer to front of linked list
	cout << front->data;
	currNode = front->next;
  while (currNode != nullptr) {
    cout << "," << currNode->data;
    currNode = currNode->next;
  }
	cout << endl;
}

void RecursiveStack::printStars()
{
	printStars(front);
}

void RecursiveStack::printStars(StackNode* front)
{
	if (front == nullptr) { // Base Case
		return;
	} else {
		if (front->data == 0) {
			cout << "-" << endl;
		} else {
			for (int i = 0; i < front->data; i++) {
				cout << "*";
			}
			cout << endl;
		}
		printStars(front->next); // Recursive call
	}
}

