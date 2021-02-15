// Carbajal, Joshua
// movie.h
// 5/27/2020
// Purpose: Specification file for Movie class.  

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

class Movie
{
	private:
		string title, genre, contentRating, tagline, director;
		long id;
		int year;
		
	public:
		Movie();
		// Default constructor
		// pre(conditions): None
		// post(conditions): Assigns empty string to string variables 
		//									 and 0 to int and long variables. 
		
		Movie(long, string, string, int, string, string, string);
		// Parameterized constructor
		// pre(conditions): None
		// post(conditions): Assigns variables to parameters 
		//									 passed into constructor
		
		string getTitle();
		// Returns title of the movie
		// pre(conditions): None
		// post(conditions): Returns movie title
		
		string getGenre();
		// Returns genre of the movie
		// pre(conditions): None
		// post(conditions): Returns movie genre
		
		string getRating();
		// Returns content rating of the movie
		// pre(conditions): None
		// post(conditions): Returns movie content rating
		
		string getTagline();
		// Returns tagline of the movie
		// pre(conditions): None
		// post(conditions): Returns movie tagline
		
		string getDirector();
		// Returns director of the movie
		// pre(conditions): None
		// post(conditions): Returns movie director
		
		long getID();
		// Returns id of the movie
		// pre(conditions): None
		// post(conditions): Returns movie id
		
		int getYear();
		// Returns year of the movie
		// pre(conditions): None
		// post(conditions): Returns movie year
			
};

#endif