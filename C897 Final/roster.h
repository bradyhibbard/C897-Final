#pragma once
#include "string"
#include "degree.h"
#include "student.h"
#include<iostream>
#include <vector>
#include<string>

using namespace std;

class roster
{
public:
	Student *classRosterArray[15];
	roster();
	~roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

