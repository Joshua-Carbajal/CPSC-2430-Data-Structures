// Carbajal, Joshua
// recursiveStack.h
// 5/4/2020
// Purpose: Specification file for RecursiveStack class.  

#ifndef RECURSIVESTACK_H
#define RECURSIVESTACK_H

class RecursiveStack 
{
	public:
		RecursiveStack();
		// Default constructor
		// pre(conditions): None
		// post(conditions): Assigned front to nullptr
		
		~RecursiveStack();
		// Deletes stack
		// pre(conditions): Stack is not empty
		// post(conditions): Stack is deallocated from memory
		
		RecursiveStack(const RecursiveStack &); 
		// Copies and assigns a stack
		// pre(conditions): Addresses must not be equal
		// post(conditions): Deletes stack, dynamically allocates and 
		//									 populates new stack
		
		RecursiveStack& operator=(const RecursiveStack &);
		// Copy constructor
		// pre(conditions): Stack must be empty
		// post(conditions): Allocates stack with identical values 
		//									 from the previous stack
		
		void push(int digit);
		// Appends value to front of the stack
		// pre(conditions): None
		// post(conditions): Appends value to front of the stack
		
		void pop(int &digit);
		// Removes value from stack
		// pre(conditions): Stack is not empty
		// post(conditions): Deletes value from the front of the stack and 
		//									 returns the value to the user.
		
		void top(int &digit);
		// Returns value at the top of the stack
		// pre(conditions): Stack is not empty
		// post(conditions): Returns integer at top of the stack
		 
		bool isEmpty();
		// Returns if stack is empty
		// pre(conditions): None
		// post(conditions): Returns true if stack is empty
		
		void recInsert(int posInteger);
		// Appends each digit of integer to the stack recursively
		// pre(conditions): Must be positive integer
		// post(conditions): Stack containing each digit of integer
		
		void print();
		// Prints values in linked list
		// pre(conditions): None
		// Post(conditions): Displays values of linked list to user
		
		void printStars();
		// Prints number of stars corresponding to value in the stack.
		// pre(conditions): None
		// post(conditions): Prints star character corresponding to each value
		//									 in	the stack to the user.
		
	private:
	  struct StackNode {
			int data; // Value in the node 
			StackNode* next; // Pointer to the next node 
		};
		StackNode* front; // Pointer to the top of the stack
		void printStars(StackNode* front); // Helper function
};

#endif

		