// Carbajal, Joshua
// citybst.h
// 5/7/2020
// Purpose: Specification file for CityBST class.  

#ifndef CITYBST_H
#define CITYBST_H

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

class CityBST 
{
	private:
	  struct TreeNode {
			string key; // Name of the city
			string country; 
			int population;
			TreeNode *left; // Pointer to left child node
			TreeNode *right; // Pointer to right child node
		};
		TreeNode *root; // Pointer to root of tree
		
		void insert(TreeNode *&, TreeNode *&);
		// Private helper function that inserts node recursively.
		// pre(conditions): None
		// post(conditions): Inserts node into binary tree
		
		void print(TreeNode *);
		// Private helper function that prints entire tree in an 
		// inorder traversal.
		// pre(conditions): None
		// post(conditions): Prints tree in inorder traversal
		
		void destroyTree(TreeNode *&);
		// Private helper function that passes the node and deletes 
		// in a postorder traversal.
		// pre(conditions): Node must not be nullptr
		// post(conditions): Traverses postorder and deletes nodes 
		
		void printCity(TreeNode *, string);
		// Private helper function that passes the node and searches the
		// binary tree until it finds the node and prints the information
		// of the city.
		// pre(conditions): None
		// post(conditions): Prints all information of the city
		
		int getHeight(TreeNode *);
		// Private helper function that traverses the left and right subtree
		// recursively and returns the height of the binary tree.
		// pre(conditions): None
		// post(conditions): Returns height of the tree
		
		string biggestCity(TreeNode *, int, string);
		// Private helper function that returns biggest city as a string
		// pre(conditions): None
		// post(conditions): Returns biggest city as string 
		
		bool deleteNode(TreeNode *&, string);
		// Private helper function that take a node, searches the binary
		// tree, deletes the node and reattaches the childrend of the node. 
		// pre(conditions): None
		// post(conditions): Returns true if node is deleted, false if not
		//									 found.
		
		TreeNode * clone(TreeNode *);
		// Private helper function that created and inserts nodes to 
		// binary tree.
		// pre(conditions): None
		// post(conditions): Assigns root to nullptr, attaches nodes to
		//									 binary tree
		 
	public:
		CityBST();
		// Default constructor
		// pre(conditions): None
		// post(conditions): Assigns root to nullptr
		
		~CityBST();
		// Deletes binary search tree
		// pre(conditions): None
		// post(conditions): Deletes entire binary tree
		
		CityBST(const CityBST &); 
		// Copies and assigns a binary search tree
		// pre(conditions): Addresses must not be equal
		// post(conditions): Creates binary tree and inserts nodes from 
		//									 current binary tree
		
		CityBST& operator=(const CityBST &);
		// Copy constructor
		// pre(conditions): Binary tree must not be empty
		// post(conditions):

		void insert(string, string, int);
		// Adds a node to the tree with city name, country and population.
		// pre(conditions): None
		// Post(conditions): Inserts node into binary tree sorted by city name
		
		bool remove(string);
		// Returns if city name is within the tree.
		// pre(conditions): None
		// Post(conditions): Returns false if the city is not in the tree,
		//									 else deletes the node.
		
		int getHeight();
		// Returns the height of the tree.
		// pre(conditions): None
		// Post(conditions): Returns the height of the tree
		
		void print();
		// Prints the names of all the cities in the tree using an
		// inorder traversal.
		// pre(conditions): None
		// Post(conditions): Prints entire binary tree to the user
		
		void printCity(string);
		// Searches and prints all information of the input city 
		// to the user. 
		// pre(conditions): City name must be in binary search tree 
		// Post(conditions): Prints all information of the city to the user
		
		string biggestCity();
		// Returns population of biggest city within tree
		// pre(conditions): None
		// Post(conditions): Returns population of biggest city, "" if 
		//									 binary tree is empty
		
		void destroyTree();
		// Deletes all nodes in binary tree.
		// pre(conditions): None
		// Post(conditions): All nodes in tree deleted from memory.
};

#endif

		