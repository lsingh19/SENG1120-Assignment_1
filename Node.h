/*
 * File Name: Node.h
 * Course: SENG1120
 * Last Modified: 05/04/2019
 */

 // Macroguard for Node class
#ifndef LOVEKESH_Node
#define LOVEKESH_Node

#include "Student.h"
#include <cstdlib>
using namespace std; 
	class Node 
	{
		public: 
				// Using typedef for Student which acts as synonym for Student throughout the code.
			typedef Student value_type; 
				
				// -------------------------------- // 
				// 			Constructors 
				// -------------------------------- //
				
				/*
					Purpose:  creates an instance of Node with no parameters. 
					Pre-Condition: None
					Post-Condition: an instance of node with it's pointers set to the NULL 
									and the data is created using the empty constructor within Student,
									which just sets the student name string to an empty string and the score
									to 0. 
				*/
			Node(); 
			
				/*
					Purpose:  creates an instance of Node with 1 parameter that being the data for Node
					Pre-Condition: The data provided is valid
					Post-Condition: An instance of Node is created with the data that's set as the input parameter for the function. Both pointers in Node are set to NULL.
				*/
			Node(const value_type& init_data);
			
			// ----------------------------------------- NOTE -------------------------------------------- //
			// Note: if we set the input paramater to a constant then an error occurs where the program has
			// problems assigning a 'const Node*' variable to a 'Node*' variable.
			// ------------------------------------------------------------------------------------------- // 
			
				/*
					Purpose:  creates an instance of Node with 3 parameter. 
					Pre-Condition: the data provided is valid, both the parameter for the Node pointer are also valid.
					Post-Condition: an instance of Node is created with the data thats set as the input parameter for the data in Node. The next pointer is set to the input 
					paramter for the next pointer and the previous pointer is set to the input parameter for the previous pointer. 
				*/
			Node(const value_type& init_data, Node* nPrevious, Node* nNext);
			
			
				// -------------------------------- // 
				// 			Destructor 
				// -------------------------------- //
				/* 
					Purpose : To delete the Node and with it the data and pointers within it. 
					Pre-condition: A node exists for the method/function to destroy. 
					Post-condition: The data within the node and both pointers (next and previous) are deleted aswell as the node itself.
				*/
			~Node();
			
			
				// -------------------------------- // 
				// 			Methods/Functions 
				// -------------------------------- //
				// Note: The methods/functions are placed in the order they are used in the LinkedListDemo file. 
				
				/*
					Purpose: To set the data within the Node using the input paramater for the data. 
					Pre-Condition: The node exists and the data/paramater provided by the user is a valid paramater.
					Post-Condition:  The 'data' provided in the method is set to the 'data' for the node. 
				*/
			void set_data(const value_type& new_data);
			
			
			/*
				Purpose: Sets the 'next' pointer of the node to the input paramater.  
				Pre-Condition: The node exists within the linked list and a valid paramter is provided. 
				Post-Condition: The 'next' pointer within the node is set to the input parameter. 
			*/
			void set_next(Node* next_link);
			
			/*
				Purpose: Sets the 'previous' pointer of the node to input parameter.
				Pre-Condition: The node exists within the linked list and a valid paramter is provided.  
				Post-Condition: The 'previous' pointer within the node will be set to the input parameter.
			*/
			void set_previous(Node* previous_link);
			
			
			/*
				Purpose: Reterives the data stored within the node.
				Pre-Condition: Data exists within the node and the node itself exists. 
				Post-Condition: The data stored within the node is returned to the user when this function is called. This 
				doesn't remove/delete the data stored within the Node.
			*/
			value_type get_data() const;
			
			
			/*
				Purpose: Retierves the Node that the 'previous' Pointer is pointing too. 
				Pre-Condition: The Node exists
				Post-Condition: Whatever the 'previous' pointer is pointing too is returned. Can either be a Node or NULL, depending on the position of the
								Node within the Linked List. 
			*/
			Node* get_previous() const;
			
			
			/*
				Purpose: Retierves the Node that the 'next' Pointer is pointing too. 
				Pre-Condition: The Node exists
				Post-Condition: Whatever the 'next' pointer is pointing too is returned. Can either be a Node or NULL, depending on the position of the
								Node within the Linked List. 
			*/
			Node* get_next() const; 
			
			
			/*
				Purpose:  Reterives the student 'name' within the data for the Node. 
				Pre-Condition: The data exists within the node and the node itself exists within the linked list. 
				Post-Condition: The name of the student stored within data for the node is returned when the method is called.
			*/
			string get_StudentName() const;
			
			
			/*
				Purpose: Retrieves the student 'score' within the data for the Node. 
				Pre-Condition: The data exists within the node and the node itself exists within the linked list. 
				Post-Condition: The score of the student stored within the node is returned when the method is called. 
			*/
			double get_StudentScore() const; 
			
		private: 
			value_type data; 			// A variable to store the data
			Node* next; 				// A varaible to store the memory address of the 'next' Node
			Node* previous; 			// A variable to store the memory address of the 'previous' Node
	};
#endif 