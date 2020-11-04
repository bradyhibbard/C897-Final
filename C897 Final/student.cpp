#include "student.h"
#include<iostream>
using namespace std;
string d[] = { "SECURITY", "NETWORK", "SOFTWARE" };
Student::Student(string sID, string fn, string ln, string email, int ag, int dic[3], DegreeProgram d)
{
	//The constructor assigns respective values to variables
	studentID = sID;
	firstName = fn;
	lastName = ln;
	emailAddress = email;
	age = ag;
	days_in_course[0] = dic[0];
	days_in_course[1] = dic[1];
	days_in_course[2] = dic[2];
	degree = d;
}
Student::~Student()
{
}
//the following functions are setters and getters
void Student::setstudentID(string sID)
{
	studentID = sID;
}
string Student::getstudentID()
{
	return studentID;
}
void Student::setfirstName(string fn)
{
	firstName = fn;
}
string Student::getfirstName()
{
	return firstName;
}
void Student::setlastName(string ln)
{
	lastName = ln;
}
string Student::getlastName()
{
	return lastName;
}
void Student::setemailAddress(string email)
{
	emailAddress = email;
}
string Student::getemailAddress()
{
	return emailAddress;
}
void Student::setage(int ag)
{
	age = ag;
}
int Student::getage()
{
	return age;
}
void Student::setdays_in_course(int dic[3])
{
	days_in_course[0] = dic[0];
	days_in_course[1] = dic[1];
	days_in_course[2] = dic[2];
}
string Student::getdays_in_course()
{
	return to_string(days_in_course[0]) + ", " + to_string(days_in_course[1]) + ", " + to_string(days_in_course[2]);
}
void Student::setdegree(DegreeProgram d)
{
	degree = d;
}
DegreeProgram Student::getdegree()
{
	return degree;
}
//This function prints the details of student
void Student::print()
{
	cout << "Student ID : " + studentID + "   First Name : " + firstName + "   Last Name : " + lastName;
	cout << "   E-Mail : " + emailAddress + "   Age : " + to_string(age) + "   Days in Courses : " + to_string(days_in_course[0]) + ", " + to_string(days_in_course[1]) + ", " + to_string(days_in_course[2]) + "   Degree Program : " + d[degree];
	cout << endl;
}
