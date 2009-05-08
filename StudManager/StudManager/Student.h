
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

#ifndef STUDENT
#define STUDENT
class Student
{
public:
	Student();
	Student(string a_id, string a_firstName, string a_lastName, string a_category);
	void setFirstName(string a_firstName);
	string getFirstName();
	void setLastName(string a_lastName);
	string getLastName();
	void setId(string a_id);
	string getId();
	void setCategory(string a_category);
	string getCategory();
	virtual void displayAssessment();
	~Student(void);

private:
	string m_firstName, m_lastName, m_category, m_id;


};
#endif