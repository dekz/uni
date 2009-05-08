
#include "student.h"
#include <map>


#ifndef COURSEWORK
#define COURSEWORK
class Coursework :
	public Student
{
public:
	Coursework();
	Coursework(string a_id, string a_firstName, string a_lastName, string a_category);
	void setUnits(const map<string, int> &a_mapl);
	void addUnit(string a_unitCode, int a_grade);
	int getTotalUnits();
	string getUnits();
	~Coursework(void);
	virtual void displayAssessment() override;
	

private:
	//data structure
	map<string,int> m_units;
	string getGpa();

};
#endif