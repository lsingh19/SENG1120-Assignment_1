# SENG1120-Assignment_1
Mark: 100%

# INTRODUCTION 

You are required to build the infrastructure to manipulate data related to student scores. Your client further specifies that you are to create a class named LinkedList to store the students’ information. The LinkedList will store each name of the student and their score in a Node of the list, using the provided class Student. 
 
# ASSIGNMENT TASK 

You are required to use a linked list, as discussed in lectures, to create your own implementation of the LinkedList class. It will use instances of Node to store instances of value_type (in this assignment, each Node will be used to store an instance of Student). 
The LinkedList class will be used by a main program, to be supplied to you, as well as a makefile. You will need to design LinkedList and Node in a way that it communicates seamlessly with the main program and the class Student provided, and compiles with the makefile also supplied. Please refer to the lecture slides and recordings for guidance on how to implement both classes.  

Compiling and running your files together with the demo file provided should output the following result: 

Start lists: 

List 1: (Alex,15)  (Peter,10)  (John,32)  (Mary,50)  (Carol,31) 

List 2: (Michelle,12)  (Carol,27)  (Tim,20)  (Michelle,90)  (John,75)  (Tony,60) 
 
Concatenating the two lists onto list '1': 

List 1: (Alex,15)  (Peter,10)  (John,32)  (Mary,50)  (Carol,31)  (Michelle,12)  (Carol,27)  (Tim,20)  (Michelle,90)  (John,75)  (Tony,60)  

List 2: (Michelle,12)  (Carol,27)  (Tim,20)  (Michelle,90)  (John,75)  (Tony,60) 
 
Removing student 'Alex' from list '1': 

List 1: (Peter,10)  (John,32)  (Mary,50)  (Carol,31)  (Michelle,12)  (Carol,27)  (Tim,20)  (Michelle,90)  (John,75)  (Tony,60) 

List 2: (Michelle,12)  (Carol,27)  (Tim,20)  (Michelle,90)  (John,75)  (Tony,60) 
 
Removing student 'John' from list '2': 

List 1: (Peter,10)  (John,32)  (Mary,50)  (Carol,31)  (Michelle,12)  (Carol,27)  (Tim,20)  (Michelle,90)  (John,75)  (Tony,60) 

List 2: (Michelle,12)  (Carol,27)  (Tim,20)  (Michelle,90)  (Tony,60) 
 
Removing student 'Michelle' from both lists: 

List 1: (Peter,10)  (John,32)  (Mary,50)  (Carol,31)  (Carol,27)  (Tim,20)  (John,75)  (Tony,60) 

List 2: (Carol,27)  (Tim,20)  (Tony,60) 
 
Removing student 'Fred' from list '2': 

List 1: (Peter,10)  (John,32)  (Mary,50)  (Carol,31)  (Carol,27)  (Tim,20)  (John,75)  (Tony,60) 

List 2: (Carol,27)  (Tim,20)  (Tony,60) 
 
Average of list '1': 28.75 

Average of list '2': 67.00 
 
Number of students named 'Carol': 3 
 
Removing the contents of list '2' from list '1': 

List 1: (Peter,10)  (John,32)  (Mary,50)  (Carol,31)  (John,75) 

List 2: (Carol,27)  (Tim,20)  (Tony,60) 

The program has finished. 

# Feedback
DEMO: 

1. Program compiles and works correctly with the files provided (each incorrectly printed line will attract a 3-mark penalty). 

2. Implementation of order(). 

3. Late Deduction :  

4. Coversheet Deduction :  
 
A: Total (  15.0 /15.0  )         

B: Bonus for order() (  3.0 / 3.0  ) 
 
REMOVE MARKS IF: 

Code leads to memory leaks during execution or there are no destructors (  0.0 /1.0  ) 

Lack of macroguards (  0.0 /1.0  )  Lack of const qualifiers (  0.0 /1.0  ) 

Lack of documentation in the code (  0.0 /2.0  ) 

Use of Student unnecessarily in the code, i.e. other than in typedef statements (  0.0 /2.0  ) 

Declaration of temporary variables as member variables of the class (  0.0 /1.0  ) 

Lack of use of dynamic memory allocation in Node or LinkedList (  0.0 /15.0  ) 

Use of friend qualifier (  0.0 /2.0 ) 

Violation of encapsulation / information hiding (e.g. use of global variables) (  0.0 /5.0  ) 
 
C: Total deductions (  0.0 / 30.0  ) 

FINAL MARK [ MIN (15.0, A+B-C) ]:   15.0 /15.0 

Comments: 
Excellent work on the ordering method. (+3 bonus). Your Node object has an incomplete destructor, as the Student object that it stores will not be deleted under the control of the program / programmer. Whilst you are correct in that it will be deleted once out of scope, that relies on the operating system to control memory management and garbage collection. A good programmer should strive to control memory management themselves where possible. In saying that, you have delivered a perfect assignment, including your ordering methods. Overwhelmingly perfect!
