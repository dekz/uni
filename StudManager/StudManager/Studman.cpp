
#include "Coursework.h"
#include "Research.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

void displayStudents();
void loadStudents(string a_filename);
void loadStudents();
void writeStudents(string a_filename);
void getInput(string keyboardInput);
void displayInstructions();
list<Student*>* g_students;


int main()
{
	//Coursework sutdents[20];
	string keyboardInput;
	displayInstructions();
	g_students = new list<Student*>();
	while (true)
	{
		cout << "# ";
		cin >> keyboardInput;
		if (keyboardInput != "quit")
		{
			getInput(keyboardInput);
		} else break;
	}
	delete g_students;
	return 0;
}

void getInput(string keyboardInput)
{
	if (keyboardInput == "input")
	{
		loadStudents();
	} else if (keyboardInput == "inputfile")
	{
		string textfile;
		cout << "Enter the filename\n# ";
		cin >> textfile;
		loadStudents(textfile);
	} else if (keyboardInput == "outputfile")
	{
		string textfile;
		cout << "Enter the filename\n# ";
		cin >> textfile;
		writeStudents(textfile);
	} else if (keyboardInput == "report")
	{
		displayStudents();
	} else if (keyboardInput == "help")
	{
		displayInstructions();
	} else cout << "Unknown command - " << keyboardInput << endl;

}

void displayInstructions()
{
	cout << "\nCommands - \n input - input each student indivdually\n inputfile - input a file of studens \n outputfile - output the students to a file \n report - display studens in the terminal \n quit - quit this loop\n help - displays this menu\n";
}

void writeStudents(string a_filename)
{
	ofstream thefile;
	thefile.open(a_filename.c_str());
	int totalStudents = g_students->size();
	thefile << totalStudents << endl;
	list<Student*>::iterator ci;
	for (ci = g_students->begin(); ci != g_students->end(); ++ci)
	{
		thefile << (*ci)->getFirstName() << " " << (*ci)->getLastName() << " " << (*ci)->getId() << " " << (*ci)->getCategory() << endl;
		if ((*ci)->getCategory() == "course")
		{
			thefile << ((Coursework*)(*ci))->getTotalUnits() << " " << ((Coursework*)(*ci))->getUnits() << endl;
		} else if ((*ci)->getCategory() == "research")
		{
			thefile << ((Research*)(*ci))->getDegreeEnrolled() << " " << ((Research*)(*ci))->getStudyStatus() << endl;
		}
	}
	
	thefile.close();
}

//overload method, make it take a filename or something
void loadStudents(string a_filename)
{
	/*
	cin >> textfile
	wstring temp(textfile.length(),L' ');
	copy(textfile.begin(), textfile.end(), temp.begin());
	*/

	ifstream thefile;
	thefile.open(a_filename.c_str());
	//grab our stuff from the text file, assign it to variables and call the constructor
	unsigned loop;
	thefile >> loop;
	Student* student;
	for (unsigned i = 0; i < loop; i++)
	{
		unsigned noUnits;
		string id, firstName, lastName, category, degreeType, studyStatus;
		thefile >>  firstName >> lastName >> id >> category;
		bool success = true;
		//***** check for a category for the right constructor
		if (category == "course") 
		{
			thefile >> noUnits;
			Coursework* courseworkStudent = new Coursework(id, firstName, lastName, category);
			student = dynamic_cast<Student*>(courseworkStudent);

			for (unsigned j = 0; j < noUnits; j++)
			{
				string unitCode;
				int grade;
				thefile >> unitCode >> grade;
				courseworkStudent->addUnit(unitCode, grade);
			}


		} else if (category == "research")
		{
			string degreeType, studyStatus;
			thefile >> degreeType >> studyStatus;
			Research* researchStudent = new Research(id, firstName, lastName, category, degreeType, studyStatus);
			student = dynamic_cast<Student*>(researchStudent);
		} else success = false;

		if (success) 
		{

			g_students->push_back(student);
		}

	}
	thefile.close();
}

void loadStudents()
{
	Student* student;
	string id, firstName, lastName, category, degreeType, studyStatus;
	cout << "Please enter the student information\n id firstname lastname category\n# ";
	cin >> id >> firstName >> lastName >> category ;
	bool success = true;
	if (category == "course") 
	{
		unsigned noUnits;
		cout << "\nEnter how many units taken\n# ";
		cin >> noUnits;
		//cout << id << firstName << lastName << category << noUnits ;
		Coursework* courseworkStudent = new Coursework(id, firstName, lastName, category);
		cout << (courseworkStudent)->getFirstName();
		student = dynamic_cast<Student*>(courseworkStudent);
		for (unsigned j = 0; j < noUnits; j++)
		{
			cout << "\n Enter Unit details\nunitcode grade\n# ";
			string unitCode;
			int grade;
			cin >> unitCode >> grade;
			courseworkStudent->addUnit(unitCode, grade);
		}
	} else if (category == "research")
	{
		string degreeType, studyStatus;
		cout << "\nEnter degreetype studystatus\n# ";
		cin >> degreeType >> studyStatus;
		Research* researchStudent = new Research(id, firstName, lastName, category, degreeType, studyStatus);
		student = dynamic_cast<Student*>(researchStudent);
	}else success = false;

	if (success) 
	{
		g_students->push_back(student);
	}

}

void displayStudents()
{

	cout << "\nCourse Work Students \n---------------------------------\n";
	list<Student*>::iterator ci;
	for (ci = g_students->begin(); ci != g_students->end(); ++ci)
	{
		if ((*ci)->getCategory() == "course")
		{
			(*ci)->displayAssessment();
		}


	}
	cout << "\nResearch Students \n---------------------------------\n";
	for (ci = g_students->begin(); ci != g_students->end(); ++ci)
	{
		if ((*ci)->getCategory() == "research")
		{
			(*ci)->displayAssessment();
		}

	}
}