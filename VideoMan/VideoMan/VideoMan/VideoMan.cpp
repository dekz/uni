
#include <iostream>
#include <string>
#include "CustomerCollection.h"
#include "MovieCollection.h"
#include "Customer.h"
#include "Movie.h"

using namespace std;

void addMovie(Movie* a_movie);
void removeMovie(Movie* a_movie);
void addCustomer(Customer* a_customer);
void removeCustomer(Customer* a_customer);
void getMovieDetails();
Movie* getMovie();
//void getMovieDetails(string a_movie);
void getCustomerDetails();
Customer* getCustomer();
//void getCustomerDetails(string a_customer);
void addMovie();
void addCustomer();
void removeMovie();
void removeCustomer();
void searchMovie();
void doInstruction(string a_instruction);
void listCustomers();
void listMovies();
void addMovieToCustomer(Movie* a_movie, Customer* a_customer);
void addMovieToCustomer();
void remMovieFromCustomer(Movie* a_movie, Customer* a_customer);
void remMovieFromCustomer();

MovieCollection g_MOVIES;
CustomerCollection g_CUSTOMERS;
Customer bob, jacob, jack;
Movie e5;
Movie a5;

int main()
{
	Movie* e5 = new Movie("a",10,"A","a","19th");
	Movie* a5 = new Movie("b",10,"A","a","19th");
	Movie* b5 = new Movie("c",10,"A","a","19th");
	Movie* c5 = new Movie("z",10,"A","a","19th");
	Customer* jacob = new Customer("jacob", "152","323");
	//Customer* jack = new Customer("x", "152","323");
	//Customer* bob = new Customer("bob", "152","323");
	g_CUSTOMERS.insert(jacob);
	//g_CUSTOMERS.insert(bob);
	//g_CUSTOMERS.insert(jack);
	g_MOVIES.insert(e5);
	g_MOVIES.insert(a5);
	g_MOVIES.insert(b5);
	g_MOVIES.insert(c5);
	//cout << "Looking for a5: " << g_MOVIES.search(e5) << endl;
	//cout << "Removing a5: " << g_MOVIES.remove(a5) << endl;
	//cout << "Looking for a5: " << g_MOVIES.search(c5) << endl;
	jacob->addMovie(e5);
	//cout << "search for jacob: " << g_CUSTOMERS.search(jacob) << endl;
	/*g_CUSTOMERS.InOrderTraverse();
	g_CUSTOMERS.PostOrderTraverse();
	g_CUSTOMERS.PreOrderTraverse();*/
	//cout << "search for movie in jacob: " << jacob->searchMovie(e5)  << endl;
	//g_CUSTOMERS.deleteItem(jacob);
	//cout << "search for jacob: " << g_CUSTOMERS.search(jacob) << endl;
	string _instruction;
	//cin >> _instruction;
	cout << "# Enter instructions" << endl;
	cout << "# ";
	while (!((cin >> _instruction) == "quit"))
	{
		cout << "you entered" << _instruction << endl;
		cout << "performing instruction: " << _instruction << endl;
		doInstruction(_instruction);
		cout << "\n# ";
	}
	return 0;
}

void addMovie()
{
	string _movieName;
	cout << "Enter Movie information - Enter -1 to quit" << endl;
	cout << "Name: ";
	cin  >> _movieName;
	if (_movieName == "-1") return;
	if (g_MOVIES.search(_movieName))
	{
		cout << "\n# Movie is in database\n";
		return;
	}
	//Movie* _tempMovie = new Movie(_movieName);
	addMovie(new Movie(_movieName));
}

void removeMovie()
{
	removeMovie(getMovie());
}
void addMovie(Movie* a_movie)
{
	//g_MOVIES.insert(a_movie);
	try
	{
		g_MOVIES.insert(a_movie);
	}
	catch(...)
	{
		cout << "Error inserting movie" << endl;
		return;
	}
	cout << "Inserted movie: " << a_movie->getTitle() << endl;

	//not very optimised, try catch will return a success
	/*if(g_MOVIES.search(a_movie->getTitle()))
	{
	cout << "Inserted movie: " << a_movie->getTitle() << endl;
	}
	*/
}

void searchMovie()
{
	string _searchString;
	cout << "# Searching for a Movie" << endl;
	cout << "Movie Name?: "; 
	cin >> _searchString;
	if(g_MOVIES.search(_searchString))
	{
		cout << "Found: " << _searchString << endl;
	}
	else
	{
		cout << "Did not Find: " << _searchString << endl;
	}

}

void searchCustomers()
{
	string _searchString;
	cout << "# Searching for a Customer" << endl;
	cout << "Customer Name?: "; 
	cin >> _searchString;
	if(g_CUSTOMERS.search(_searchString))
	{
		cout << "Found: " << _searchString << endl;
	}
	else
	{
		cout << "Did not Find: " << _searchString << endl;
	}

}

void doInstruction(string a_instruction)
{
	if ((a_instruction == "-1") || (a_instruction == "quit")) return;
	else if (a_instruction == "addmovie") addMovie();
	else if (a_instruction == "removemovie") removeMovie();
	else if (a_instruction == "addcustomer") addCustomer();
	else if (a_instruction == "removecustomer") removeCustomer();
	else if (a_instruction == "listcustomers") listCustomers();
	else if (a_instruction == "findmovie") searchMovie();
	else if (a_instruction == "findcustomer") searchCustomers();
	else if (a_instruction == "listmovies") listMovies();
	else if (a_instruction == "getcustomerdetails") getCustomerDetails();
	else if (a_instruction == "getmoviedetails") getMovieDetails();
	else if (a_instruction == "addmovietocustomer") addMovieToCustomer();
}

void listCustomers()
{
	cout << "# Listing Customers" << endl;
	g_CUSTOMERS.InOrderTraverse();
	cout << endl;
}

void listMovies()
{
	cout << "# Listing Movies" << endl;
	g_MOVIES.traverse();
	cout << endl;
}

void removeMovie(Movie* a_movie)
{
	g_MOVIES.remove(a_movie);
}
void addCustomer()
{
	string _name;
	cout << "Enter Customer information - Enter -1 to quit" << endl;
	cout << "Name: ";
	cin  >> _name;
	if (_name == "-1") return;
	if (g_CUSTOMERS.search(_name))
	{
		cout << "\n# Customer is in database\n";
		return;
	}
	addCustomer(new Customer(_name));

}
void removeCustomer()
{
	removeCustomer(getCustomer());
}

void addCustomer(Customer* a_customer)
{
	try
	{
		g_CUSTOMERS.insert(a_customer);
	}
	catch(...)
	{
		cout << "Error inserting customer" << endl;
		return;
	}
	cout << "Inserted customer: " << a_customer->getName() << endl;
}

void removeCustomer(Customer* a_customer)
{
	g_CUSTOMERS.deleteItem(a_customer);
}

Movie* getMovie()
{
	string _name;
	cout << "Enter Movie information - Enter -1 to quit" << endl;
	cout << "Name: ";
	cin  >> _name;
	if (_name == "-1") return 0;
	if (g_MOVIES.search(_name))
	{
		return g_MOVIES.getMovie(_name);
	}
	else
	{
		cout << "Movie not in database" << endl;
		return 0;
	}
}

void getMovieDetails()
{
	getMovie()->ToString();
}

/*void getMovieDetails(string a_movie)
{
//cout << g_MOVIES.getMovie(a_movie)->getTitle();
g_MOVIES.getMovie(a_movie)->ToString();
}*/

Customer* getCustomer()
{
	string _name;
	cout << "Enter Customer information - Enter -1 to quit" << endl;
	cout << "Name: ";
	cin  >> _name;
	if (_name == "-1") return 0;
	if (g_CUSTOMERS.search(_name))
	{
		return (g_CUSTOMERS.getCustomer(_name));
	}
	else 
	{
		cout << "Customer not in database" << endl;
		return 0;
	}

}

void getCustomerDetails()
{
	getCustomer()->ToString();
}

/*
void getCustomerDetails(string a_customer)
{
g_CUSTOMERS.getCustomer(a_customer)->ToString();
}*/

void addMovieToCustomer()
{
	addMovieToCustomer(getMovie(), getCustomer());
}

void addMovieToCustomer(Movie* a_movie, Customer* a_customer)
{
	if ((a_movie != 0) && (a_customer != 0))
	{
		try 
		{
			a_customer->addMovie(a_movie);
		} catch (...)
		{
			cout << "Could add movie" << endl;
			return;
		}
		cout << "Added " << a_movie->getTitle() << " to " << a_customer->getName() << endl;
	}
	else cout << "Error null pointer" << endl;
}

void remMovieFromCustomer()
{
	remMovieFromCustomer(getMovie(), getCustomer());
}

void remMovieFromCustomer(Movie* a_movie, Customer* a_customer)
{
	if ((a_movie != 0) && (a_customer != 0))
	{
		try 
		{
			a_customer->removeMovie(a_movie);
		}
		catch (...)
		{
			cout << "Could not remove movie" << endl;
			return;
		}
		cout << "Removed " << a_movie->getTitle() << " from " << a_customer->getName() << endl;
	}
	else cout << "Error null pointer" << endl;
}
