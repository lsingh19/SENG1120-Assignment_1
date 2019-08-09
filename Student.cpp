// Student.cpp - Student Object
// ****************************
//
// Written by : SENG1120 Staff c9876543
// Modified   : 2019-03-08
// 
// Program Description: Student Object that will be stored in, and used to test the LinkedList (Assignment 1)


#include "Student.h"
#include <cstdlib>

// Constructors
Student::Student()
{
	name = "";
	score = 0;
}

Student::Student(string name_, int score_)
{
	name = name_;
	score = score_;	
}

// empty destructor
Student::~Student(){}

// Mutator methods (setters)
void Student::set_name(const string name_) {name = name_;}
void Student::set_score(const int score_){ score = score_;}

// Accessor methods (getters)
string Student::get_name() const {return name;}
int Student::get_score() const {return score;}

// overloaded ostream operator
ostream& operator <<(ostream& out, const Student& value)
{
    out << "(" << value.get_name() << "," << value.get_score() << ") ";
    return out;
}

// overloaded == operator
bool operator == (const Student& s1, const Student& s2)
{
    if ((s1.get_name() == s2.get_name()) && (s1.get_score() == s2.get_score()))
    {
		return true;
    }
	else
	{
		return false;
	}
}

int operator < (const Student& s1, const Student& s2)
{
	int check = s1.get_name().compare(s2.get_name());  // comparing the two strings to see which one comes first 
	return check; 		// return check
}