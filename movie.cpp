// Carbajal, Joshua
// movie.cpp
// 5/27/2020
// Purpose: Implementation file for the Movie class.

#include "movie.h"
#include "hash.h"

Movie::Movie()
{
	title = genre = contentRating = tagline = director = "";
	id = 0;
	year = 0;
}

Movie::Movie(long i, string t, string g, int y, string c, string tag, string d) 
{
	id = i;
	title = t;
	genre = g;
	year = y;
	contentRating = c;
	tagline = tag;
	director = d;
}

string Movie::getTitle()
{
	return title;
}

string Movie::getGenre()
{
	return genre;
}

string Movie::getRating()
{
	return contentRating;
}

string Movie::getTagline()
{
	return tagline;
}

string Movie::getDirector()
{
	return director;
}

long Movie:: getID()
{
	return id;
}

int Movie::getYear()
{
	return year;
}