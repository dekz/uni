#include "Coursework.h"

Coursework::Coursework() : Student ()
{
}

Coursework::Coursework(string a_id, string a_firstName, string a_lastName, string a_category)
: Student(a_id, a_firstName, a_lastName, a_category)
{

}

void Coursework::setUnits(const std::map<string, int> &a_map)
{
	this->m_units = a_map;
}

void Coursework::addUnit(string a_unitCode, int a_grade) 
{
	this->m_units[a_unitCode] = a_grade;
}


Coursework::~Coursework(void)
{
}

int Coursework::getTotalUnits()
{
	return this->m_units.size();
}
void Coursework::displayAssessment()
{
	int count = 0;
	int noUnits = m_units.size();
	Student::displayAssessment();
	cout << "Number of units taken: " << noUnits <<  endl;
	cout << "Grades: ";
	cout << getUnits() << endl;
	cout << "GPA: " << getGpa() << endl << endl;

}

string Coursework::getUnits()
{
	std::stringstream outputString;
	int noUnits = m_units.size();
	map<string,int>::iterator it;
	for (it=m_units.begin() ; it != m_units.end(); it++ ) 
	{
		//count++;
		outputString << it->first << " " << it->second << " ";

	/*	if (count != noUnits)
		{
			cout << ", ";
		} else 
		{
			cout << endl;
		}*/
	}
	return outputString.str();
}

string Coursework::getGpa()
{
	std::stringstream out;
	map<string,int>::iterator it;
	double gpacache = 0;
	for (it=m_units.begin() ; it != m_units.end(); it++)
		gpacache += double(it->second);
	out << (gpacache/m_units.size());
	return out.str();
}