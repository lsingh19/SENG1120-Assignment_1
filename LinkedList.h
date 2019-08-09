/*
 * File Name: LinkedList.h
 * Course: SENG1120
 * Last Modified: 05/04/2019
 */

// Macroguard for LinkedList
 #ifndef LOVEKESH_LINKEDLIST
 #define LOVEKESH_LINKEDLIST
 
 #include "Node.h"
 #include <cstdlib> 
 
 using namespace std; 
 class LinkedList
 {
	public:
		// Using typedef for Student which acts as synonym for Student throughout the code.
	typedef Student value_type; 
	
	
	// ----------------------------------
	//			Constructors
	// ----------------------------------
	/* 
		Purpose: Create an instance of LinkedList. 
		Pre-condition: None
		Post-condition: An instance of linked list is created which will contain a head, tail and current pointer which will
		be set to NULL upon initilisation of the linked list.
	*/
	LinkedList();
	
	/* 
		Purpose: Creates an instance of LinkedList with a paramater for Data that will be placed within a newly created Node within the LinkedList. 
		Pre-condition: Valid data is provided to the function
		Post-condition: An instance of linked list is created with the data provided, which will be stored within a newly created node within the LinkedList.
		The head, tail and current pointer will be set according to the the number of nodes within the linked list, if any.
	*/
	LinkedList(const value_type& data);
	
	
	// ------------------------------------
	//			Destructors
	// ------------------------------------
	/* 
		Purpose: To deletes the LinkedList and any Nodes within it. 
		Pre-condition: An instance of Linked List exists.
		Post-condition: the instance of linked list is deleted with it all the nodes, pointers and data that are contained within it. 
	*/
	~LinkedList();
	
	/* 
		Purpose: Creates a Node object within the Linked List and the input paramater (data) is stored with the newly created Node. 
		Pre-condition: Valid data is provided and the Linked List is initialised
		Post-condition: there are 2 possibilites to using this method: 
		1.	Creates a Node object and sets 'tail' pointer to the new Node. The 'previous' pointer 
			within node will be set to the node before the new node within the linked list. The node before the new node
			will have it's 'next' pointer will set to the new node.  
		  
		  OR
		  
		2.	If the 'head' pointer is set to the NULL, meaning that there does not exist any nodes within the linkedlist.
			In that case a node object will be created in which its 'next' and 'previous' pointers will be set to NULL.
			the 'head', 'tail' and 'current' within the Linkedlist will all be set to newly created node.
	*/
	void addToTail(const value_type& data); 
	
	
	/* 
		Purpose: Adds on Nodes of RHS LinkedList to the LHS Linked List. 
		Pre-condition: Both linkedlist are initilised and contain nodes within them.
		Post-condition: The LHS linked list will have nodes added to the back of the list from the RHS linked list. All the 'next' and 'previous' pointers
		will be adjusted according ensuring that they point where they should and the LinkedList is maintained. 
	*/
	LinkedList& operator += (LinkedList& list);
	
	
	/* 
		Purpose: Moves the current pointer to the front of the LinkedList aka the head Node.
		Pre-condition: None
		Post-condition: The current pointer within linked list will be moved to the head of the linked list. 
	*/
	void move_To_Head(); 
	
	
	/* 
		Purpose: Checking whether if the Current Pointer is set to NULL.
		Pre-condition: None
		Post-condition: a boolean value is returned when this method is called. The boolean value depends on whether the Current pointer is NULL or not. 
	*/
	bool check_current() const; 
	
	
	/* 
		Purpose: Moves the current pointer down the LinkedList, by assigning the node after the current node to the pointer. 
		Pre-condition: none 
		Post-condition: The currrent pointer will now point to the next node in the linked list or it will
						point to null if it reaches the end of the linked list. 
	*/
	void forward();
	
	
	/* 
		Purpose: Retrieves the data stored within the Node that the current pointer is pointing too. 
		Pre-condition: The current pointer is not set to NULL and the LinkedList exists. 
		Post-condition: the data stored within node that the current pointer is pointing too is returned. 
	*/
	value_type get_current_data() const; 

	
	/* 
		Purpose:	The linked list will be checked to see if any student names match that of the input 'name', if it matchs then the node is removed from
					the LinkedList. 
		Pre-condition: a Valid parameter is provided and the Linked List exists. 
		Post-condition: If the input name matchs any student names within the linked list then the node with the data storing 
		the matching student name is removed from the linked list. All pointers of node are adjusted accordingly to maintain the LinkedList. 
	*/
	void remove(const string name);
	
	
	/* 
		Purpose: Calculates the average of the students score within the Linked List. 
		Pre-condition: The Linked List exists. 
		Post-condition: The average of all the student score's within the linked list is returned. 
	*/
	double calcAverage(); 
	
	
	/* 
		Purpose: the number of students with the name that matchs that of the input 'name' will returned
		Pre-condition: None 
		Post-condition: The number of students with the name that matchs the name provided within the linked list is returned to the user. 
	*/
	int count(const string name);
	
	
	/* 
		Purpose: If any Node within the RHS LinkedList is in the LHS LinkedList aswell, then it is removed from the LHS LinkedList. 
		Pre-condition: Both LinkedList exist and contain Nodes within them. 
		Post-condition: If any of the students in LHS linked list match any of the students in the RHS linked list then 
		that student is removed from the LHS linked list. At the end of the function there should be no matching 
		students within both LinkedLists.
		
	*/
	LinkedList& operator -= (LinkedList& list);
	
	
	/* 
		Purpose: if the provided data exists within the LinkedList then the Node containing this data is removed from teh LinkedList. 
		Pre-condition:	The node exists within the linked list and data exists within the node
						the provided data is valid
		Post-condition: If the data matchs any of the data within the linked list then the node that contians 
						the data will be removed from the linked list and with it the data. 
	*/
	void remove_data(const value_type data);
	
	
	/* 
		Purpose: Retrieves the data that the node after the current node (the node that the current pointer is pointing too) is storing.
		Pre-condition: 	The node after the current node(the node that the current pointer is pointing too) is not NULL and 
						the data exists within it. 
		Post-condition: The data within node after the current node is returned.
	*/
	value_type get_next_data();
	
	
	/* 
		Purpose: Orders the Linked List alphabetically by Student Name
		Pre-condition: The linked list is initialised and contain nodes within it which contain valid data.
		Post-condition: The linkedlist will be sorted into alphabetical order by the student name's. 
	*/
	void order();
	
	private: 
		// Declaring private variables. 
		Node* head;			// head pointer
		Node* tail;			// tail pointer 
		Node* current; 		// current pointer
		int list_length;	// stores the numebr of nodes within the linked list. 
		
	/* 
		Purpose: the current node (the Node that the current pointer is pointing too) and the node after it will switch positions within the LinkedList 
		and the pointers will be adjusted accordingly. 
		Pre-condition: the current pointer is pointing to a node and there is another node after the current node in the 
						linked list. The linked list itself is initilised and contains nodes which contain data within it. 
		Post-condition: the current node and the next node will switch positions within the linked list and their pointer will 
						also change to account for the change of nodes in the linked list. 
	*/
		void swap(); 
 };
	// Operator Overloading cout '<<' (pipeline)  
	ostream& operator << (ostream& out, LinkedList& list); 
 
 #endif