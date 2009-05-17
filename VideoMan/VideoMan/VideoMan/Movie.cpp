#include "Movie.h"

Movie::Movie(void)
{
}

Movie::Movie(string a_movieName)
{
	m_title = a_movieName;
	m_classification = "";
	m_duration = 0;
	m_genre = "";
	m_releaseDate = "";
}


Movie::Movie(const string a_title, const int a_duration, const string a_genre, const string a_classification, const string a_releaseDate)
{
	m_classification = a_classification;
	m_duration = a_duration;
	m_genre = a_genre;
	m_releaseDate = a_releaseDate;
	m_title = a_title;
}

void Movie::ToString()
{
	cout << m_title << endl;
	cout << m_duration << endl;
	cout << m_genre << endl;
}

string Movie::getTitle()
{
	return this->m_title;
}

Movie::~Movie(void)
{
}
