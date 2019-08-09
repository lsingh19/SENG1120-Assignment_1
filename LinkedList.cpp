/*
 * File Name: LinkedList.cpp
 * Course: SENG1120
 * Last Modified: 05/04/2019
 */
 
 #include "LinkedList.h" 
 #include <cstdlib> 
 using namespace std; 
 
 LinkedList::LinkedList()
 {
	 head = NULL;	
	 tail = NULL;
	 current = NULL; 
	 list_length = 0; 
 }
 
 LinkedList::LinkedList(const value_type& data)
 {
	 addToTail(data);   // calling the 'addToTail' fucntion which will insert the the data as a node into the linkedlist
						// the head, tail and current pointer within the functions are set depending on the number of nodes in the LinkedList.
 }
 

LinkedList::~LinkedList()
{
	current = NULL; 		//setting current to NULL
	while (head != NULL)	// as long as the head does not reach the tail of the LinkedList then the while loop will keep executing
	{
		Node* temp = head;		// creating a temporary pointer which will be used to delete the node
			if (head == tail)		// if the head reaches the tail that means that only one node remains within the linkedlist
			{
				head = NULL;		// setting head to NULL 
				tail = NULL;		// setting tail to NULL
				delete temp;		// delete temp which deletes the last remaining node
			}
			else 
			{
				head = head->get_next(); 	// 'head' is moved to the following node in the linked list
				head->set_previous(NULL);	// the 'previous' pointer on the head node is set to NULL.
				temp->set_next(NULL);		// setting the 'next' on the to be deleted node to NULL
				delete temp; 				// the node is deleted as well as the 'temp' pointer.
			}
	}
	list_length=0;
}


 void LinkedList::addToTail(const value_type& data)
 {
	 if (head == NULL)							// if the head is equal to NULL meaning that there is no nodes within the linked list. 
	 {
		 head = new Node(data);					// the 'head' pointer is set to the newly created Node. 
		 tail = head;							// the 'tail' pointer is set to the newly created Node.
		 current = head; 						// the 'current' pointer is set to the newly created Node
		 list_length = 1; 						// the list length is set 1 as there is only one node that's in the Linked List and it's the one created in this 'if'. 
	 }
		 else 		
		 {
			Node* temp = new Node(data);		// creating a temp node with the data parameter
			tail -> set_next(temp);				// sets 'next' pointer of the tail node to the temp node 
			temp -> set_previous(tail); 		// the previous of the temp node to the tail node
			tail = temp; 						// assiging the tail pointer to the new tail node of the Linked List
			temp = NULL; 						// setting the temp node to NULL 
			list_length++;						// incrementing the list length
		 }
 }

 
 LinkedList& LinkedList::operator += (LinkedList& list)
 {
	 list.move_To_Head();							// moving the current of the RHS LinkedList to head of the LinkedList 
	 while (list.check_current() != true)			// checking if the current pointer within the RHS is NULL 
	 {
		this->addToTail(list.get_current_data());	//adding the Node of the RHS LinkedList to the LHS LinkedList
		list.forward();								// moving the current pointer within the RHS LinkedList to the next node within the LinkedList
	 }
	 return *this;									
 }
 

 void LinkedList::move_To_Head()
 {
	 current = head; 				// assigning the current pointer to the head pointer
 }

 
bool LinkedList::check_current() const
 {
	 if (current == NULL) 			// checking if current is NULL
		 return true;
	 else 
		 return false; 
 }


 void LinkedList::forward()
 {
	 current = current->get_next();   // Moving the current pointer to the next node within the LinkedList
 }


LinkedList::value_type LinkedList::get_current_data() const
 {
	return current -> get_data();			// returning the data within the Node that the current pointer is pointing too. 
 }	 


void LinkedList::remove(const string name)
 {
	 move_To_Head();					// moving the current to the head of the list
	 while (current != NULL)   			// checking if the current node is not NULL 
	 {
		 if (name == current->get_StudentName() && current == head)				// checking to see if the student name for the node matchs the input 'name'. also checking if the current pointer is equal to the head pointer 
		 {
			 Node* temp = head;				// creating a temp pointer and setting it to the head pointer
			 head = head->get_next();		// moving the head to the following node in the LinkedList 
			 head->set_previous(NULL);		// setting the 'previous' on the head pointer node to NULL 
			 temp->set_previous(NULL);		// setting the next pointer on the temp node to NULL 
			 temp->set_next(NULL);			// setting the previous pointer on the temp node to NULL 
			 delete temp;					// deleting the temp Node. 
			 list_length--;					// decrementing the list length
			 current = head; 				// setting the current pointer to the head pointer
		 }
			 else if (name == current->get_StudentName() && current == tail)	// checking to see if the student name for the node matchs the input 'name'. also checking if the current pointer is equal to the tail pointer
			 {
				 Node* temp = current; 		// creating a temp pointer and setting it to the current pointer
				 current = current->get_previous();		// moving the current pointer back one node on the linked list
				 current->set_next(NULL);				// setting the 'next' pointer on Node to NULL. 
				 tail = current; 						// setting the tail pointer to the current pointer. 
				 temp->set_previous(NULL);		// setting the next pointer on the temp node to NULL 
				 temp->set_next(NULL);			// setting the previous pointer on the temp node to NULL
				 delete temp; 					// deleting the temp pointer and Node. 
				 list_length--;					// decreasing the list lenght size
			 }
				 else if (name == current->get_StudentName()) 	// checking to see if the student name for the node matchs the input 'name'.
				 {
					 Node* temp = current; 				// creating a temp pointer that's set to the current pointer node
					 forward();							// moving the current pointer to the following node
					 current->set_previous(temp->get_previous()); 	// setting the 'previous' on the current node to the 'previous' node of the temp pointer
					 temp->get_previous()->set_next(current);		// getting the 'previous' node before temp and setting the 'next ' on that node to the current pointer node
					 temp->set_previous(NULL);		// setting the next pointer on the temp node to NULL 
					 temp->set_next(NULL);			// setting the previous pointer on the temp node to NULL
					 delete temp; 					//deleting the temp pointer and node
					 forward(); 					// moving the current pointer to the following node in the linked List 
					 list_length--; 				// decreasing the list lenght size
				 }
					 else 
					 {
						 forward();					// moving the current pointer to the following node
					 }
	 }
 }


double LinkedList::calcAverage()
 {
	 double average, total=0;     // creating new variables that are used to calculate the average 
	 move_To_Head();			// moving the current pointer to the head of the list
	 while (current != NULL) 			// ehecking if the current is NULL 
	 {
		 total += current->get_StudentScore();		// adding the student score to the total variable
		 forward();									// moving the current pointer to the following node in the linked List 
	 }
	 average = total/list_length;				// dividing the total by list length. the ouptu is assigned to the variable average
	 return average;							// returning the average
 }
	
	
int LinkedList::count(const string name)
 {
	int count = 0; 				// creaating an int variable called 'count' and setting that to 0. 
	move_To_Head();				// moving the current pointer to the head of the linked List 
	while (current != NULL)     // checking if the current pointer is NULL
	{
		if (name == current->get_StudentName())		// checking if the current pointer node's student name match the input 'name'
		{
			count++;				// incrementing the count variable
		}
		forward(); 		// moving the current pointer to the following node in the linked List 
	}
	return count;  // return the count variable. 
 }


 LinkedList& LinkedList::operator -= (LinkedList& list)
 {
	 this->move_To_Head();   // moving the LHS current pointer to the head of the LinkedList
	 list.move_To_Head();	// moving the RHS current pointer to the head of the LinkedList
	while (list.check_current() != true)      // checking if the current pointer of the RHS Linked List is NULL 
	 {
		while (this->check_current() != true)		// checking if the current pointer of the LHS Linked List is NULL 
		 {
				 this->remove_data(list.get_current_data());			// sending the RHS LinkedList current pointer node data to the method remove_data() on the LHS LinkedList to have the data removed. 
		 }
		 this->move_To_Head();					 // moving the LHS current pointer to the head of the LinkedList
		 list.forward();			// moving the current pointer to the following node in the RHS linked List 
	 }
	 
	 return *this;
 }
	
	
void LinkedList::remove_data(const value_type data)
{
 while (current != NULL) 		// checking if the pointer is NULL
	 {
		if (data == get_current_data() && current == head)			// checking to if the data and the data from the current pointer node match. Also checking if the current is equal to the head
			 {
				 Node* temp = head;				// creating a temp pointer and assigning that to the head
				 head = head->get_next();       // moving the head to teh next node in teh linked list
				 head->set_previous(NULL);		// setting the previous on the head pointer node to NULL 
				 temp->set_previous(NULL);		// setting the next pointer on the temp node to NULL 
				 temp->set_next(NULL);			// setting the previous pointer on the temp node to NULL
				 delete temp;					// deleting the temp poinert and the node that its pointing too.
				 list_length--;					// decrementing te list lenght
				 current = head; 				// setting the head to current
				 forward();						// moving the current pointer to the next node in the linked list 
			 }
				 else if (data == get_current_data() && current == tail)	// checking to if the data and the data from the current pointer node match. Also checking if the current is equal to the tail
				 {
					 Node* temp = current;						// creating a temp pointer and assigning that to the head
					 current = current->get_previous();        // moving the current pointer back one node in the linked list
					 current->set_next(NULL);					// setting the 'next' pointer on the current pointer node to NULL.
					 tail = current; 							// setting tail to current. 
					 temp->set_previous(NULL);		// setting the next pointer on the temp node to NULL 
					 temp->set_next(NULL);			// setting the previous pointer on the temp node to NULL
					 delete temp; 				// deleting temp 
					 list_length--;				// decrementing list length 
					 forward();					// moving the current pointer to the next node in the linked list 
				 }
					 else if (data == get_current_data() )					// checking to if the data and the data from the current pointer node match.
					 {
						 Node* temp = current;    							// creating a temp pointer and assigning that to the head
						 forward();											// moving the current pointer to the next node in the linked list 
						 current->set_previous(temp->get_previous()); 		// setting the previous of the current pointer node to the node before the temp pointer node. 
						 temp->get_previous()->set_next(current);			// get the node before temp and setting next on that node to the current poiter node
						 temp->set_previous(NULL);							// setting the next pointer on the temp node to NULL 
					     temp->set_next(NULL);								// setting the previous pointer on the temp node to NULL
						 delete temp; 										// deleting temp 
						 forward(); 										// moving the current pointer to the next node in the linked list 
						 list_length--; 									// decrementing list length 
					 }
						 else 
						 {
							 forward();										// moving the current pointer to the next node in the linked list 
						 }
	 }
}	 


 LinkedList::value_type LinkedList::get_next_data()
 {
	return current -> get_next() -> get_data(); 	// returns the data of the node after the current pointer node.
 }	 


 void LinkedList::order()
 {
	 move_To_Head();   				// moving the current pointer to the head of the list 
	 bool isSorted = false; 		// creating a boolean variable and setting that to false 
	 int lastUnsorted = list_length - 1; 		// creating a int variable and assigning that the value of list_length - 1
	 while (!isSorted)					
	 {
		isSorted = true; 		
		for (int i=0; i < lastUnsorted; i++) 
		{
			 if ((get_current_data() < get_next_data()) > 0) 	// checking to see the student name for the current pointer node comes before the node after the current node student name
			 {
				swap (); 				// swapping the current pointer node and node after it.
				isSorted = false; 		// setting the isSorted to false
			 }
				forward();				// moving the current pointer to the next node in the linked list 
		}
			 lastUnsorted--;			// decrementing the lastUnsorted
			 move_To_Head();			// moving the current pointer to the head of the list 
	 }
 }
	
	
void LinkedList::swap()
{
	if (current == head) 				// checking if the current is equal to head
	{
		forward();						// moving the current pointer to the next node in the linked list
		head->set_next(current->get_next());		// setting the 'next' to the ndoe after the current pointer node
		current->set_next(head);					// setting the 'next' of the current pointer node to the head pointer node
		
		head->get_next()->set_previous(head);		// getting tet node after the ehad pointer node and setting it's previous to the head
		head->set_previous(current);				// setting the 'previous' on the head pointer node to the current pointer node. 
		current->set_previous(NULL);				// setting the 'previous' of the current pointer node to NULL 
		head = current; 							// setting the head to the current
	}
		else if (current->get_next() == tail)		// checking if the current is equal to tail 
		{
			current ->get_previous()->set_next(tail);			// getting the previous node of current and setting it's next to the tail 
			tail->set_previous(current->get_previous());		// setting the previous of the tail pointer node to the ndeo before the current pointer node
			tail->set_next(current);							// setting the next of the tail node to the current pointer node
			current->set_previous(tail); 						// setting the previous on the current node to the tail 
			current->set_next(NULL);							// setting the next of the current pointer ndoe to NULL
			tail = current;										// assigning the tail to the current 
			current = current-> get_previous(); 				// moving the current pointer bak one node in the linked list  
		}		
			else
			{
				Node* temp = current->get_next();				// creating a temp pointer and assigning it the node after the current pointer node
				current->get_previous()->set_next(temp);		// getting the previous node before the current pointer node and setting its next to the temp pointer node
				current->set_next(temp->get_next());			// setting the next of the current pointer node to the node after the temp pointer node 
				temp->set_next(current);						// setting the next of the temp pointer node to the current node 
				
				temp->set_previous(current->get_previous());	// settting the previous of the temp pointer node to the node before the current pointer node 
				current->get_next()->set_previous(current);		// getting the node after the current pointer node and setting it's previous to the current node
				current->set_previous(temp);					// setting the previous of the current pointer node to the temp pointer node 
				current = temp;									// assiging the current the value of temp
				temp = NULL; 									// setting temp to NULL  
			}
 }
 
 
 ostream& operator << (ostream& out, LinkedList& list)
 {
	 list.move_To_Head();				// moving current pointer of the linkedlist to the head of the list 
	 while (list.check_current() != true)			// checking to see the current is equal to NULL 
	 {
		 out << list.get_current_data();		
		 list.forward();			// moving the current pointer to the next node in the linked list
	 }
	 return out;
 }