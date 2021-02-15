// Carbajal, Joshua
// hash.cpp
// 5/27/2020
// Purpose: Implementation file for the Hash class.

#include "movie.h"
#include "hash.h"

HashTable::HashTable()
{
	for (int i = 0; i < ARR_SIZE; i++) {
		playlist[i] = nullptr;
	}
}

HashTable::~HashTable()
{
	for (int i = 0; i < ARR_SIZE; i++) {
		delete playlist[i];
	}
}

int HashTable::hashFunc(long key)
{
	return key % ARR_SIZE;
}

void HashTable::addToPlaylist(long key, Movie m)
{
	int keyIdx = hashFunc(key); // Valid key index
	// Create MovieNode
	MovieNode *newMovie = new MovieNode;
	newMovie->key = keyIdx;
	newMovie->mov = m;
	newMovie->next = nullptr;
	// Insert movie into playlist
	if (playlist[keyIdx] == nullptr) {
		playlist[keyIdx] = newMovie;
	} else {
		MovieNode *nodePtr = playlist[keyIdx]; // Pointer to front of linked list
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		if (nodePtr->mov.getID() == key) {
			cout << "Movie " << key << " is already in your playlist." << endl;
		} else {
			nodePtr->next = newMovie;
		}
	}
}

bool HashTable::watchMovie(long key)
{
	bool foundMovie = false; // Boolean for watched movie
	int keyIdx = hashFunc(key); // Valid key index
	MovieNode *head = playlist[keyIdx]; // Pointer to front of linked list
	MovieNode *nodePtr; // Temporary pointer
	MovieNode *prevNode; // Temporary pointer
	if (head->mov.getID() == key && head->next == nullptr) { 
		cout << "Watched " << head->mov.getTitle() 
						 << ". Removing it from the playlist!" << endl;
		playlist[keyIdx] = nullptr;
		foundMovie = true;
	} else {
		nodePtr = head;
		while (nodePtr && !foundMovie) {
			if (nodePtr->mov.getID() == key) {
				cout << "Watched " << nodePtr->mov.getTitle() 
						 << ". Removing it from the playlist!" << endl;
				if (nodePtr == head) {
					nodePtr = head->next;
					delete head;
					playlist[keyIdx] = nodePtr;
				} else if (nodePtr->next == nullptr) {
					prevNode->next = nullptr;
					delete nodePtr;
				} else {
					prevNode->next = nodePtr->next;
					delete nodePtr;
				}
				foundMovie = true;
			}
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
	}
	return foundMovie;
}

void HashTable::displayMovie(long key)
{
	bool found = false; // Boolean for found movie 
	int keyIdx = hashFunc(key); // Valid key index
	MovieNode *nodePtr = playlist[keyIdx]; // Pointer to front of linked list
	if (nodePtr == nullptr) { // Specific index has no MovieNodes
		cout << "Sorry, movie " << key << " is not on your playlist" << endl;
	} else {
		while (nodePtr) {
			if (nodePtr->mov.getID() == key) {
				cout << endl;
				cout << "IMDb id: " << nodePtr->mov.getID() << endl;
				cout << "Title: " << nodePtr->mov.getTitle() << endl;
				cout << "Director: " << nodePtr->mov.getDirector() << endl;
				cout << "Genre: " << nodePtr->mov.getGenre() << endl;
				cout << "Tagline: " << nodePtr->mov.getTagline() << endl;
				cout << "Year: " << nodePtr->mov.getYear() << endl;
				cout << "Rating: " << nodePtr->mov.getRating() << endl;
				found = true;
			}
			nodePtr = nodePtr->next;
		}
		if (!found) {
			cout << "Sorry, movie " << key << " is not on your playlist" << endl;
		}
	}
}

void HashTable::displayAll()
{
	for (int i = 0; i < ARR_SIZE; i++) {
		MovieNode *nodePtr = playlist[i]; // Pointer to front of linked list
		cout << "Inside index: " << i << endl;
		while (nodePtr) {
			cout << "IMDb id: " << nodePtr->mov.getID() << endl;
			cout << "Title: " << nodePtr->mov.getTitle() << endl;
			cout << endl;
			nodePtr = nodePtr->next;
		}
	}
}

void HashTable::displayGenre(string genre)
{
	for (int j = 0; j < ARR_SIZE; j++) {
		MovieNode *nodePtr = playlist[j]; // Pointer to front of linked list
		while (nodePtr) {
			if (nodePtr->mov.getGenre() == genre) {
				cout << "IMDb id: " << nodePtr->mov.getID() << endl;
				cout << "Title: " << nodePtr->mov.getTitle() << endl;
				cout << endl;
			}
			nodePtr = nodePtr->next;
		}
	}
}