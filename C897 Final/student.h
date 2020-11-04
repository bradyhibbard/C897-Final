#pragma once
#include "degree.h"
#include <string>
using namespace std;
class Student
{
private:
    
	string studentID, firstName, lastName, emailAddress;
	int age, days_in_course[3];
	DegreeProgram degree;
    
public:
	
    //This file only declares the functions
	Student(string sID, string fn, string ln, string email, int ag, int dic[3], DegreeProgram d);
	~Student();
	Student();
	void setstudentID(string sID);
	string getstudentID();
	void setfirstName(string fn);
	string getfirstName();
	void setlastName(string ln);
	string getlastName();
	void setemailAddress(string email);
	string getemailAddress();
	void setage(int ag);
	int getage();
	void setdays_in_course(int dic[3]);
	string getdays_in_course();
	void setdegree(DegreeProgram d);
	DegreeProgram getdegree();
	void print();
};

