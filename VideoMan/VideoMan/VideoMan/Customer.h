#pragma once


#ifndef _Customer
#define _Customer

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <time.h>
#include "MovieCollection.h"

using namespace std;
class Customer
{
public:
	Customer(const string a_name, const string a_address, const string a_phonenumber);
	Customer();
	Customer(const string a_name);
	~Customer();
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	void addMovie(Movie* a_movie);
	void removeMovie(Movie* a_movie);
	bool searchMovie(Movie* a_movie);
	void ToString();
	void displayMovies();
	bool isRenting(Movie* a_movie);
	void displayTopMovies();
	void getHighest(map<string, int> map);
	friend ostream & operator<<(ostream &os, const Customer &e);

private:
	string m_name;
	string m_address;
	string m_phonenumber;
	MovieCollection m_movies;
	map<string, list<string>> m_rentedMovies;
	void __cleanUp();

};

#endif