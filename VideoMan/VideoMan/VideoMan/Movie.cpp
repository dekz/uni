#include "Movie.h"

Movie::Movie(void)
{
}

Movie::Movie(string a_movieName)
{
	m_title = a_movieName;
	m_classification = "";
	m_duration = 0;
	m_copies = 1;
	m_avail = 1;
	m_genre = "";
	m_releaseDate = "";
}

bool Movie::isAvail()
{
	if ((m_avail <= m_copies) && (m_avail != 0))
	{
		return 1;
	} else return 0;
}

bool Movie::leaseCopy()
{
	if (isAvail())
	{
		m_avail--;
		return true;
	} else 
	{
		cout << "Not able to lease copy" << endl;
		return false;
	}
}

void Movie::returnCopy()
{
	m_avail++;
}

void Movie::addCopy()
{
	m_copies++;
}
void Movie::setCopies(int a_totalCopies)
{
	m_copies = a_totalCopies;
}

void Movie::remCopy()
{
	if (m_copies > 0)
	{
		m_copies--;
	}
	else cout << "Cannot remove a copy" << endl;
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
	cout << "Total Copies: " << m_copies << endl;
	cout << "Copies in store: " << m_avail << endl;
}

string Movie::getTitle()
{
	return this->m_title;
}

Movie::~Movie(void)
{
}
