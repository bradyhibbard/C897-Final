#include "roster.h"
#include "student.h"
#include<iostream>
#include <vector>
#include<string>

using namespace std;

int index = 0;
roster::roster()
{
	
}
//destructor deletes the memory allocated to classRosterArray
roster::~roster()
{
	delete classRosterArray;
}
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int ch[] = {daysInCourse1,daysInCourse2,daysInCourse3};
	Student b(studentID, firstName, lastName, emailAddress, age, ch, degreeprogram);	//Creates student object
	classRosterArray[index] = &b;			//Add objects to classRosterArray
	index++;
}
void roster::printAll()
{
	//traverses and prints elements of classRosterArray
	for (int i = 0; i < index; i++)
	{
		Student c = *classRosterArray[i];
		c.print();
	}
}
void roster::remove(string studentID)
{
	//Traverses the classrosterArray
	for (int i = 0; i < index; i++)
	{
		Student c = *classRosterArray[i];
		if (studentID == c.getstudentID())			//If element found
		{
			classRosterArray[i] = NULL;
			return;
		}
		else if (i + 1 == index)					//if element doesn't exist
		{
			cout << "Student with ID " + studentID + " does not exist.";
		}
	}
}
void roster::printAverageDaysInCourse(string studentID)
{
	//This loop seperates the values given as string
	for (int i = 0; i < index; i++)
	{
		string data[3];
		int in = 0;
		string s = "";
		Student c = *classRosterArray[i];
		if (studentID == c.getstudentID())
		{
			string dic=c.getdays_in_course();
			for (int j = 0; j < dic.size(); j++)
			{
				if (dic.at(j) == ',')
				{
					data[in] = s;
					s = "";
					in++;
				}
				else
				{
					s = s + dic.at(j);
					if (j + 1 == dic.size())
					{
						data[in] = s;
						s = "";
						in++;
					}
				}
			}
			int average = stoi(data[0]) + stoi(data[1]) + stoi(data[2]);	//adds the values
			average = average / 3;
			cout << average;
		}
	}
}
void roster::printInvalidEmails()
{
	cout << "Invalid emails are : "<<endl;
	for (int i = 0; i < index; i++)
	{
		Student c = *classRosterArray[i];
		string email = c.getemailAddress();
		int at = -1, dot = -1, space = -1;
		at = email.find('@');						//checks if the email has @
		dot = email.find('.');						//checks if email has .
		space = email.find(' ');					//checks if email has space
		if (at == -1 || dot == -1 || space != -1)
		{
			cout << email;
		}
	}
}
void roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < index; i++)
	{
		Student c = *classRosterArray[i];
		if (c.getdegree() == degreeProgram)				//If the student has same degree program
		{
			c.print();
		}
	}
}
