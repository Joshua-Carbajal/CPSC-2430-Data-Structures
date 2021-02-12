// Carbajal, Joshua
// citybst.cpp
// 5/7/2020
// Purpose: Implementation file for the CityBST class.

#include "citybst.h"

CityBST::CityBST() 
{
	root = nullptr; // Pointer to root of binary tree
}
 
CityBST::~CityBST() 
{
	destroyTree();
}

CityBST::CityBST(const CityBST &obj) : root{nullptr}
{
	root = clone(obj.root);
}

CityBST::TreeNode * CityBST::clone(TreeNode *nodePtr)
{
	if (nodePtr == nullptr) {
		return nullptr;
	} else {
		return new TreeNode{nodePtr->key, nodePtr->country, nodePtr->population,
												clone(nodePtr->left), clone(nodePtr->right) };
	}
}

CityBST& CityBST::operator=(const CityBST &obj)
{
	if (this != &obj) {
		destroyTree();
	}
	root = clone(obj.root);
	return *this;
}

void CityBST::insert(string cityName, string countryName, int pop)
{
	TreeNode *newNode = nullptr;
	newNode = new TreeNode;
	newNode->key = cityName;
	newNode->country = countryName;
	newNode->population = pop;
	newNode->left = newNode->right = nullptr;
	insert(root, newNode);
}

void CityBST::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr) {
		nodePtr = newNode;
	} else if (newNode->key < nodePtr->key) {
		insert(nodePtr->left, newNode);
	} else {
		insert(nodePtr->right, newNode);
	}
}

bool CityBST::remove(string cityname)
{
	bool del = deleteNode(root, cityname);
	return del;
}

bool CityBST::deleteNode(TreeNode *&nodePtr, string cityname)
{
	if (nodePtr == nullptr) {
		return false;
	} else if (cityname < nodePtr->key) {
		return deleteNode(nodePtr->left, cityname);
	} else if (cityname > nodePtr->key) {
		return deleteNode(nodePtr->right, cityname);
	} else {
		TreeNode *temp = nullptr; // Temporary pointer
		if (nodePtr->right == nullptr) {
			temp = nodePtr;
			nodePtr = nodePtr->left;
			delete temp;
		} else if (nodePtr->left == nullptr) {
			temp = nodePtr;
			nodePtr = nodePtr->right;
			delete temp;
		} else {
			temp = nodePtr->right;
			while (temp->left) {
				temp = temp->left;
			}
			temp->left = nodePtr->left;
			temp = nodePtr;
			nodePtr = nodePtr->right;
			delete temp;
		}
	}
	return true;
}

int CityBST::getHeight()
{
	
	return getHeight(root);
}

int CityBST::getHeight(TreeNode *nodePtr)
{
	if (nodePtr == nullptr) {
		return -1;
	}
	int left = getHeight(nodePtr->left);
	int right = getHeight(nodePtr->right);
	return  1 + max(left, right);
}

void CityBST::print()
{
	print(root);
}

void CityBST::print(TreeNode *nodePtr)
{
	if (nodePtr) {
		print(nodePtr->left);
		cout << nodePtr->key << endl;
		print(nodePtr->right);
	}
}

void CityBST::printCity(string city)
{
	printCity(root, city);
}

void CityBST::printCity(TreeNode *nodePtr, string city)
{
	bool flag = true; // Stops iteration of while loop
	while (nodePtr and flag) {
		if (nodePtr->key == city) {
			cout << "City: " << nodePtr->key << endl;
			cout << "Country: " << nodePtr->country << endl;
			cout << "Population: ";
			string numWithCommas = to_string(nodePtr->population);
			int insertPosition = numWithCommas.length() - 3;
			while (insertPosition > 0) {
				numWithCommas.insert(insertPosition, ",");
				insertPosition -= 3;
			}
			cout << numWithCommas << endl;
			flag = false;
		} else if (city < nodePtr->key) {
			nodePtr = nodePtr->left;
		} else {
			nodePtr = nodePtr->right;
		}
	}
}

string CityBST::biggestCity()
{
	int maxP = 1; // Temporary place holder for max population
	string maxCity = ""; // Temporary place holder for biggest city
	if (root == nullptr) {
		return "";
	} else {
		string maxCiudad = biggestCity(root, maxP, maxCity);
		return maxCiudad;
	}
}

string CityBST::biggestCity(TreeNode *nodePtr, int maxP, string maxCity)
{
	if (nodePtr) {
		biggestCity(nodePtr->left, maxP, maxCity);
		biggestCity(nodePtr->right, maxP, maxCity);
		if (nodePtr->population > maxP) {
			maxP = nodePtr->population;
			maxCity = nodePtr->key;
		}
	}
	return maxCity;
}

void CityBST::destroyTree()
{
	destroyTree(root);
}

void CityBST::destroyTree(TreeNode *&nodePtr)
{
	if (nodePtr != nullptr) {
		destroyTree(nodePtr->left);
		destroyTree(nodePtr->right);
		delete nodePtr;
	}
	nodePtr = nullptr;
}
