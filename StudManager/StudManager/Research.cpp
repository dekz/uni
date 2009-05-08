#include "Research.h"

Research::Research(void)
{
}

Research::Research(string a_id, string a_firstName, string a_lastName, string a_category, string a_degreeType, string a_studyStatus)
: Student(a_id, a_firstName, a_lastName, a_category)
{
	this->m_degreeType = a_degreeType;
	this->m_studyStatus = a_studyStatus;
}

void Research::displayAssessment()
{
	Student::displayAssessment();
	cout << "Degree Enrolled: " << getDegreeEnrolled() <<  endl;
	//implement next step thing
	cout << "Next Milestone: " << getNextStep() << endl;
	cout << endl;
}

string Research::getStudyStatus()
{
	return m_studyStatus;
}

string Research::getNextStep()
{
	/*
	new-enrolled, topic-confirmed, candidature-confirmed, and 
	degree-completion student should be “research proposal 
	submission”, “confirmation report submission”, “thesis 
	submission”, and “finished”
	*/
	string nextStep;
	if (this->m_studyStatus == "new-enrolled")
	{
		nextStep = "research proposal submission";
	} else if (this->m_studyStatus == "topic-confirmed")
	{
		nextStep = "confirmation report submission";
	} else if (this->m_studyStatus == "candidature-confirmed")
	{
		nextStep = "thesis submission";
	} else if (this->m_studyStatus == "degree-completion")
	{
		nextStep = "finished";
	} else nextStep = "error";
	return nextStep;

}
string Research::getDegreeEnrolled()
{
	return this->m_degreeType;
}


Research::~Research(void)
{
}


