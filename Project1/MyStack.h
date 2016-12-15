/*
* Name:		Jeffrey Qiu
* Class:	CIS 22C
* Date:		07/09/2016
* Instructor:	Professor Eftekhari
* File Name:	MyStack.h
*
* Description:	This is the header file for the MyStack class.
*/

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <vector>

/*
* MyStack class definition
*
* There are two private members:
*	std::vector<T> stack;
*		The stack is implemented with a std::vector and automatically extends when it runs out of space.
*
*	int top;
*		The top int is initialized to 0 and points to the next available space for push().
*
*
* There is one constructor that does not take any parameters.
*
*	MyStack();
*		//Pre-condition: None.
*		//Post-condition: MyStack object is initialized with a size of 100.
*	
*
* There are six stack operations:
*
*	bool push(const T item);
*		The push() function takes a const object of generic type T and pushes it on top of the stack.
*		It returns true if the item was successfully pushed and false if otherwise.
*
*	bool pop(T & item);
*		The pop() function assigns an object of generic type T the top-most element of the stack.
*		Then it removes the top-most element and returns true if successful and false if not.
*
*	bool getTop(T & item) const;
*		The getTop() function assigns an object of generic type T the top-most element of the stack. 
*		Then it returns true if it was successful and false if otherwise.
*
*	bool isEmpty(void) const;
*		The isEmpty() function does not take any parameters and returns true if the stack is empty and false if not empty.
*	
*	void print(void) const;
*		The print() function does not take any parameters and prints the elements of the stack from top to bottom separated by a single space.
*
*	void printNums(void) const;
*		The print() function does not take any parameters and prints the elements of the stack from top to bottom separated by a single space.
*/






template <typename T> class MyStack {
private:
	std::vector<T> stack;
	int top = 0;

public:
	MyStack();
	bool push(const T item);
	bool pop(T & item);
	bool getTop(T & item) const;
	bool isEmpty(void) const;
	void print(void) const;
	void printNums(void) const;
};
#endif