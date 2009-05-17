#pragma once

#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
	Movie();
	Movie(const string a_movieName);
	Movie(const string a_title, const int a_duration, const string a_genre, const string a_classification, const string a_releaseDate);
	~Movie();
	string getTitle();
	void ToString();
	void remCopy();
	void addCopy();
	bool isAvail();
	void leaseCopy();
	void returnCopy();
	void setCopies(int a_totalCopies);

private:
	int m_copies;
	int m_avail;
	string m_title;
	int m_duration; //in minutes
	string m_genre;
	string m_classification;
	string m_releaseDate;
};
