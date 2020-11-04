#include<iostream>
//#include<conio.h>
#include<stdio.h>
#include<string>
#include "student.h"
#include "roster.h"
using namespace std;
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Steven,Hibbard,Brady.Hibbard@gmail.com,33,20,40,33,SOFTWARE" };
int main()
{
	cout << "Course Title : Scripting and Programming Applications - C867" << endl;
	cout << "Programming Language Used : C++" << endl;
	cout << "Student ID: 001212075" << endl;
	cout << "Name : Steven Hibbard" << endl << endl;
	roster classRoster;
	string data[9];
	string s = "";
	int in = 0;
	//int k = 0;
	cout << "Adding Students" << endl;
	//This for loop adds the elements of studentData table into classRoster
	for (int i = 0; i < 5; i++)
	{
		in = 0;
		for (int j = 0; j < studentData[i].size(); j++)
		{
			if (studentData[i].at(j) == ',')
			{
				data[in] = s;
				s = "";
				in++;
			}
			else
			{
				s = s + studentData[i].at(j);
				if (j + 1 == studentData[i].size())
				{
					data[in] = s;
					s = "";
					in++;
				}
			}
		}
		if (data[8] == "SECURITY")
		{
			classRoster.add(data[0], data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[7]), SECURITY);
		}
		else if (data[8] == "SOFTWARE")
		{
			classRoster.add(data[0], data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[7]), SOFTWARE);
		}
		else if (data[8] == "NETWORK")
		{
			classRoster.add(data[0], data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[7]), NETWORK);
		}
	}
	classRoster.printAll();						//Prints all the students data
	cout << endl;
	classRoster.printInvalidEmails();			//Prints emails without @ or .
	cout << endl << "Average is : " << endl;
    
	//This loop traverses through the elements and finds average of their course times
	for (int i = 0; i < 5; i++)
	{
		Student c = *classRoster.classRosterArray[i];
		classRoster.printAverageDaysInCourse(c.getstudentID());
		cout << endl;
	}
	cout << endl << "Students by degree : " << endl;
	classRoster.printByDegreeProgram(SOFTWARE);				//Prints Students with Software degree
	cout << endl << endl << "Removing A3" << endl;
	classRoster.remove("A3");								//Removes A3 from classRoster
	cout << "Printing All : " << endl;
	classRoster.printAll();									
	classRoster.remove("A3");
	classRoster.~roster();
	//_getch();
	return 0;
}
