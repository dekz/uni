
#include <iostream>
#include <string>
#include "CustomerCollection.h"
#include "MovieCollection.h"
#include "Customer.h"
#include "Movie.h"

using namespace std;

void addMovie(Movie a_movie);
void removeMovie(Movie a_movie);
void addCustomer(Customer a_customer);
void removeCustomer(Customer a_customer);
void addMovie();
void addCustomer();
void removeMovie();
void removeCustomer();

MovieCollection g_MOVIES;
CustomerCollection g_CUSTOMERS;
Customer bob, jacob, jack;
Movie e5;
Movie a5;

int main()
{
	Movie* e5 = new Movie("Lion King 1.5",10,"A","a","19th");
	Movie* a5 = new Movie("Lion King 2",10,"A","a","19th");
	//Customer* jacob = new Customer("a", "152","323");
	//Customer* jack = new Customer("x", "152","323");
	//Customer* bob = new Customer("bob", "152","323");
	//g_CUSTOMERS.insert(jacob);
	//g_CUSTOMERS.insert(bob);
	//g_CUSTOMERS.insert(jack);
	g_MOVIES.insert(e5);
	g_MOVIES.insert(a5);
	bob.addMovie(a5);
	cout << "search for bob " << g_CUSTOMERS.search(bob) << endl;
	g_CUSTOMERS.InOrderTraverse();
	g_CUSTOMERS.PostOrderTraverse();
	g_CUSTOMERS.PreOrderTraverse();
	cout << "search for movie in bob " << bob.searchMovie(e5)  << endl;
	g_CUSTOMERS.deleteItem(bob);
	string test = "";
	cin >> test;
	return 0;
}

void addMovie()
{
}
void removeMovie()
{
}
void addMovie(Movie a_movie)
{
}
void removeMovie(Movie a_movie)
{
}
void addCustomer()
{
}
void removeCustomer()
{
}
void addCustomer(Customer a_customer)
{
}
void removeCustomer(Customer a_customer)
{
}