#include "Customer.h"

Customer::Customer()
{
}

Customer::Customer(const string a_name)
{
	m_name = a_name;
	m_address = "";
	m_phonenumber = "";
	MovieCollection m_movies;
}

Customer::Customer(const string a_name, const string a_address, const string a_phonenumber)
{
	m_name = a_name;
	m_address = a_address;
	m_phonenumber = a_phonenumber;
	MovieCollection m_movies;
}

void Customer::addMovie(Movie* a_movie)
{
	//look through the global list of movies, add a pointer to that object into our list
	if (a_movie->leaseCopy()) m_movies.insert(a_movie);
}

bool Customer::searchMovie(Movie* a_movie)
{
	return m_movies.search(a_movie);
}

void Customer::displayMovies()
{
	m_movies.traverse();
	//cout << "
}

void Customer::removeMovie(Movie* a_movie)
{
	if (m_movies.search(a_movie))
	{
		//take the movie out of the custoemrs ADT
		m_movies.remove(a_movie);
		//add movie to our top list
		if (m_rentedMovies.find(a_movie->getTitle()) != 0)
		{
			m_rentedMovies[a_movie->getTitle()] += 1; 
		} else 
		{
			m_rentedMovies.insert( make_pair(a_movie->getTitle(), 0));
		}
		//tell the movie object one was returned
		a_movie->returnCopy();
	}
}


void Customer::displayTopMovies()
{
	
}

void Customer::getHighest(map<string, int> map)
{

}

string Customer::getName() const
{
	return m_name;
}

string Customer::getAddress() const
{
	return m_address;
}

string Customer::getPhone() const
{
	return m_phonenumber;
}

void Customer::__cleanUp()
{
	//go through our local list of movies and delete the pointers
}

ostream & operator<<(ostream& os, const Customer& e) 
{
	os <<  e.getName() << endl; 
	return os;
}

void Customer::ToString()
{
	cout << m_name << endl;
	cout << m_address << endl;
	cout << m_phonenumber << endl;
}

Customer::~Customer(void)
{
	__cleanUp();
}
