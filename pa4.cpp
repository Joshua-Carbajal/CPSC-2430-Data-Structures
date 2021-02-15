// Carbajal, Joshua
// pa4.cpp
// 5/27/2020

// DESCRIPTION: Implements a hash table using separate chaining. A movie 
//							playlist is created with information for each movie 
//							displayed to the user. Movies are inserted by parsing csv 
//							file and collisions are addressed through separate chaining.
//							User has option of browsing all movies in playlist, browsing
//							in certain genre, watch a movie and view information about a
//							movie in the playlist.

// ASSUMPTIONS: Hash table size was calculated using load factor of 0.7 and 
//							number of items (100) in csv file. Table size could be as 
//							small as 100 or as large as 143. I chose to the make my 
//							table size 101, smaller on that spectrum and a prime number.

// SOURCES: CSPC 2430 Lab5.cpp file

#include "movie.h"
#include "hash.h"

int main()
{
	HashTable ht;
	
	// Reading and parsing csv file
	ifstream infile;
	infile.open("movies.csv");
	if (infile) {
		string header; //
		getline(infile, header); // Discards header line
		string movieInfo; //
		while(getline(infile, movieInfo)) {
			int comma = movieInfo.find(',');
			string mID = movieInfo.substr(0, comma);
			long iD = stol(mID);
			string remaining = movieInfo.substr(comma + 1);
			int comma1 = remaining.find(',');
			string tMovie = remaining.substr(0, comma1);
			string remaining2 = remaining.substr(comma1 + 1);
			int comma2 = remaining2.find(',');
			string mGenre = remaining2.substr(0, comma2);
			string remaining3 = remaining2.substr(comma2 + 1);
			int comma3 = remaining3.find(',');
			string y = remaining3.substr(0, comma3);
			int yrMovie = stoi(y);
			string remaining4 = remaining3.substr(comma3 + 1);
			int comma4 = remaining4.find(',');
			string rMovie = remaining4.substr(0, comma4);
			string remaining5 = remaining4.substr(comma4 + 1);
			int comma5 = remaining5.find(',');
			string tagMovie = remaining5.substr(0, comma5);
			int lengthTag = tagMovie.length();
			for (int i = 0; i < lengthTag; i++) {
				if (tagMovie[i] == ';') {
					tagMovie[i] = ',';
				}
			}
			string dirMovie = remaining5.substr(comma5 + 1);
			int lengthDir = dirMovie.length();
			for (int i = 0; i < lengthDir; i++) {
				if (dirMovie[i] == ';') {
					dirMovie[i] = ',';
				}
			}
			Movie m = Movie(iD, tMovie, mGenre, yrMovie, rMovie, tagMovie, dirMovie);
			ht.addToPlaylist(iD, m);
		}
	} else {
		cout << "Error opening the file> \n";
	}
	infile.close();
	cout << endl;
	cout << "Welcome to my movie world! What would you like to do?" << endl;
	int selection; // User input for playlist functionality 
	cout << "1. Browse all movies, 2. Browse the genre, 3. Watch a movie, \n";
	cout << "4. View more information about a movie, 0. Exit Program: ";
	cin >> selection;
	cout << endl;
	
	// Playlist functionality
	if (selection == 0) {
		cout << "Hope you enjoyed the movies. Goodbye!" << endl;
	}
	if (selection == 1) { 
		ht.displayAll();
	}
	if (selection == 2) {
		string genre;
		cout << "Which genre are you looking for? ";
		cin >> genre;
		ht.displayGenre(genre);
	}
	if (selection == 3) {
		long targetID;
		cout << "Enter the ID of the movie you want to watch: ";
		cin >> targetID;
		bool watched = ht.watchMovie(targetID);
		if (!watched) {
			cout << "Sorry, movie " << targetID 
					 << " is not on your playlist" << endl;
		}
	}
	if (selection == 4) {
		long searchID;
		cout << "Enter the ID of the movie: ";
		cin >> searchID;
		ht.displayMovie(searchID);
	}	
}






