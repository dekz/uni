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

bool Customer::isRenting(Movie* a_movie)
{
	if (m_movies.search(a_movie))
		return true;
	else return false;
}

void Customer::removeMovie(Movie* a_movie)
{
	if (m_movies.search(a_movie))
	{
		//take the movie out of the custoemrs ADT
		m_movies.remove(a_movie);
		//add movie to our top list
/*		if (m_rentedMovies.find(a_movie->getTitle()) != 0)
		{
			/*time_t rawtime;
			struct tm * timeinfo;
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			//add a new rented and add the time
			list<string> _list = m_rentedMovies[a_movie->getTitle()]; 
			string _test = asctime(timeinfo);
			_list.push_back(_test);
			m_rentedMovies.erase(m_rentedMovies.find(a_movie->getTitle()));
			insertIntoRented(a_movie, _list);
		} else 
		{
			/*time_t rawtime;
			struct tm * timeinfo;
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			string _test = asctime(timeinfo);
			list<string> _list;
			_list.push_back(_test);
			insertIntoRented(a_movie, _list);*/
		//}
		//tell the movie object one was returned
		
		a_movie->returnCopy();
	}
}

void Customer::insertIntoRented(Movie* a_movie, list<string> a_list)
{
	//m_rentedMovies[a_movie->getTitle()] = _list;

	map<string,list<string>>::iterator iter;
	for( iter = m_rentedMovies.begin(); iter != m_rentedMovies.end(); ++iter ) {
		//cout << "Key: '" << iter->first << "', Value: " << iter->second << endl;
		if (iter->first.size() > a_list.size())
		{
			m_rentedMovies.insert(iter, make_pair(a_movie->getTitle(), a_list));
		}
	}
}

void Customer::displayTopMovies()
{
	int counter = 1;
	map<string,list<string>>::iterator iter;
	for(iter = m_rentedMovies.begin(); iter != m_rentedMovies.end(); ++iter ) {
		if(counter == 10){  break; }	
			cout << counter << ". Movie: '" << iter->first << "', Dates: "  << endl; // << iter->second
			counter++;
	}
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
