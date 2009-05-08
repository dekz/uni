#pragma once
#include "student.h"

class Research :
	public Student
{
public:
	Research(void);
	~Research(void);
	Research(string a_id, string a_firstName, string a_lastName, string a_category, string a_degreeType, string a_studyStatus);
	virtual void displayAssessment() override;
	string getDegreeEnrolled();
	string getStudyStatus();
	string getNextStep();

private:
	string m_degreeType, m_studyStatus;
};
