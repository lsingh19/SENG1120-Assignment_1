// Student.h - Student header
// **************************
//
// Written by : SENG1120 Staff c9876543
// Modified   : 2019-03-08
// 
// Program Description:  Student Object that will be stored in, and used to test the LinkedList (Assignment 1)


#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Student 
{
	public:
		
		// Constructors
		Student();
		Student(const string, const int);

		// Destructor
	    ~Student();

		// Setters
	    void set_name(const string);
		void set_score(const int);

		// Getters
		string get_name() const;
		int get_score() const;

	//Private member variables
	private:
		string name; // student's name
		int score;	// student's score
};

// Output Piping Operator
ostream& operator <<(ostream&, const Student&);

// Boolean Equal Operator
bool operator == (const Student& s1, const Student& s2);

// overloaded operator '<' 
int operator < (const Student& s1, const Student& s2);
#endif