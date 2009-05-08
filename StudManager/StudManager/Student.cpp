#include "Student.h"
#include <string>
using namespace std;

Student::Student()
{
	this->m_id = "";
	this->m_firstName = "";
	this->m_lastName = "";
	this->m_category = "";
}
Student::Student(string a_id, string a_firstName, string a_lastName, string a_category)
{
	this->m_id = a_id;
	this->m_firstName = a_firstName;
	this->m_lastName = a_lastName;
	this->m_category = a_category;
}

Student::~Student(void)
{
}

void Student::setId(string a_id)
{
	this->m_id = a_id;
}

string Student::getId()
{
	return this->m_id;
}

string Student::getFirstName()
{
	return this->m_firstName;
}

void Student::setFirstName(string a_firstName)
{
	this->m_firstName = a_firstName;
}

string Student::getLastName()
{
	return this->m_lastName;
}

void Student::setLastName(string a_lastName)
{
	this->m_lastName = a_lastName;
}

string Student::getCategory()
{
	return this->m_category;
}

void Student::displayAssessment()
{
	cout << "Student Name: " << getFirstName() << " " << getLastName() << endl;
	cout << "Student ID: " << getId() << endl;
	cout << "Category: " << Student::getCategory() << endl;
}
