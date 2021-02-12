// Carbajal, Joshua
// pa2.cpp
// 5/4/2020

// DESCRIPTION: Program that implements a stack ADT using a 
// singly linked list. Implements basic class and stack functions.
// A positive integer is input by the user. A linked list is created 
// with nodes corresponding to each digit in the integer. The linked 
// list is displayed to the user along with "*" corresponding to each
// node in the linked list. All functions of the class and stack are 
// tested thoroughly in the program.

// ASSUMPTIONS: None

// SOURCES: CPSC 1230 Lab 8 Stack and Queue code WQ19

#include <iostream>
#include "recursiveStack.h"
using namespace std;

int main()
{
	RecursiveStack stack;
	int catchDigit; // To hold values from top of stack
	int posInteger; // User input positive integer
	cout << "Welcome. Please enter a positive integer: ";
	cin >> posInteger;
	stack.recInsert(posInteger);
	cout << "Elements on the stack are: " << endl;
	stack.print();
	cout << endl;
	cout << "Star print: " << endl;
	stack.printStars();
	cout << endl;
	
	// Testing of class and stack functions
	cout << "Pushing 4" << endl;
	stack.push(4);
	cout << "Elements on the first stack are: " << endl;
	stack.print();
	cout << "Top of the stack... ";
	stack.top(catchDigit);
	cout << catchDigit << endl;
	cout << "Popping from stack... ";
	stack.pop(catchDigit);
	cout << catchDigit << endl;
	cout << "Elements on the first stack are: " << endl;
	stack.print();
	cout << "Second stack created.\n";
	RecursiveStack stack2 = stack;
	cout << "Popping from stack... ";
	stack2.pop(catchDigit);
	cout << catchDigit << endl;
	cout << "Elements on second stack are: " << endl;
	stack2.print();
	cout << "Third stack created, with elements from first stack." << endl;
	RecursiveStack stack3;
	stack3 = stack;
	cout << "Pushing 9" << endl;
	stack3.push(9);
	cout << "Elements on third stack are: " << endl;
	stack3.print();
}