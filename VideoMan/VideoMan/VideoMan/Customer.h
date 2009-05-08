#pragma once

#include <iostream>
#include <string>
#include "MovieCollection.h"
using namespace std;
class Customer
{
public:
	Customer(const string a_name, const string a_address, const string a_phonenumber);
	Customer(void);
	~Customer(void);
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	void addMovie(Movie a_movie);
	void removeMovie(Movie* a_movie);
	bool searchMovie(Movie a_movie);
	friend ostream & operator<<(ostream &os, const Customer &e);
private:
	string m_name;
	string m_address;
	string m_phonenumber;
	MovieCollection m_movies;
	void __cleanUp();

};
