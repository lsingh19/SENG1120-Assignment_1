/*
 * File Name: Node.cpp
 * Course: SENG1120
 * Last Modified: 05/04/2019
 */

#include "Node.h"

Node::Node()
{
	next = NULL;				// sets the 'next' pointer to NULL
	previous = NULL;			// sets the 'previous' pointer to NULL
	data = value_type();		// creates an instance of Student using the constructor for Student in the Student class. 
}

Node::Node(const value_type& init_data = value_type())
	{
		data = init_data;		// sets the data within the node to the input data from the user
		next = NULL;			// sets the 'next' pointer to NULL 
		previous = NULL; 		// sets the 'previous' pointer to NULL 
	}
	
Node::Node(const value_type& init_data, Node* nPrevious, Node* nNext)
{
	data = init_data;			// sets the data within the node to the input data from the user
	previous = nPrevious;		// sets the 'next' pointer to the input parameter from the user for this pointer 
	next = nNext;				// sets the 'previous' pointer to the input parameter from the user for the pointer
}
		
void Node::set_data(const value_type& new_data)	
	{
		data = new_data;		// sets the data to the input parameter.  
	}
	
// Note: if we set the input paramater to a constant then an error occurs where the program has a
// problem assigning a const Node* to a Node*. 
void Node::set_next( Node* next_link)				
	{
		next = next_link;				// sets the 'next' pointer within the node to the input parameter
	}
			
void Node::set_previous( Node* previous_link)		
	{
		previous = previous_link;		// sets the 'previous' pointer within the node to the input parameter
	}
			

Node::value_type Node::get_data() const					
	{ 
		return data;	// returns the data stored within the Node. 
	} 
			
Node* Node::get_previous() const 			
	{
		return previous;	// returns the Node that the 'previous' pointer is pointing too. 
	}
			
Node* Node::get_next() const 				
	{
	return next;			// returns the Node that the 'next' pointer is pointing too.
	}
	
string Node::get_StudentName() const
{
	return data.get_name();		// retrieves the student 'name' in the data by using the method 'get_name()' within the student class 
}

double Node::get_StudentScore() const 
{
	return data.get_score();	// retrieves the student 'score' in the data by using the method 'get_score()' within the student class
}

Node::~Node()
{
	next = NULL; 		// sets the 'next' pointer to NULL, so when the function returns the pointer is deleted as it goes out of scope. 
	previous = NULL;	// sets the 'previous' pointer to NULL, so when the function returns the pointer is deleted as it goes out of scope.
	// Note: there is no need to destory the data as it's created on the stack and is not a dynamic variable, therefor
	// the data will be automatically deleted once it goes out of scope. Same applies for the pointer, since they won't point to anything they will be deleted by 
	// the implicit automatic garabge collection on the stack. 
}
