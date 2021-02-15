// Carbajal, Joshua
// hash.h
// 5/27/2020
// Purpose: Specification file for Hash class.  

#ifndef HASH_H
#define HASH_H

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

const int ARR_SIZE = 101; // Size of static array playlist

class HashTable
{
	private:
		struct MovieNode {
			long key; // Key index
			Movie mov; // Movie object 
			MovieNode *next;
		};
		MovieNode *playlist[ARR_SIZE];
		
	public:
		HashTable();
		// Default constructor
		// pre(conditions): None
		// post(conditions): Assigns all pointers to nullptr
		
		~HashTable();
		// Destructor
		// pre(conditions): None
		// post(conditions): Deletes all pointers
		
		int hashFunc(long);
		// Returns valid key index within playlist
		// pre(conditions): None
		// post(conditions): Returns key index
		
		void addToPlaylist(long, Movie);
		// Inserts key-value pair into playlist
		// pre(conditions): None
		// post(conditions): Inserts key-value pair into playlist, if 
		//									 key exists, prints message that the movie
		//									 is already in the playlist.
		
		bool watchMovie(long);
		// Searches playlist and plays movie if found in playlist, deletes
		// it thereafter.
		// pre(conditions): None
		// post(conditions): Prints to user movie was watched and deletes movie
		//									 from playlist, if false prints message that the 
		//									 movie was not in the playlist.
		
		void displayMovie(long);
		// Searches playlist and displays movie information
		// pre(conditions): None
		// post(conditions): If key exits, displays movie information else 
		//									 tells user movie is not in the playlist.
		
		void displayAll();
		// Displays specific information of all the movies in the playlist
		// pre(conditions): None
		// post(conditions): Displays title and movie id of all movies in the 
		//									 playlist
		
		void displayGenre(string);
		// Searches playlist and displays information of all movies in specific
		// genre
		// pre(conditions): None
		// post(conditions): Displays title and movie id of all movies in
		//									 the genre

};

#endif