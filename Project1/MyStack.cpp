/*
* Name:		Jeffrey Qiu
* Class:	CIS 22C
* Date:		07/09/2016
* Instructor:	Professor Eftekhari
* File Name:	MyStack.cpp
*
* Description:	This is the implementation file for the MyStack class.
*/



#include <iostream>
#include <exception>
#include <stdio.h>

#include "MyStack.h"


const int INITIAL_STACK_SIZE = 100;






template <typename T>
MyStack<T>::MyStack()
{
	stack.reserve(INITIAL_STACK_SIZE);	// Allocate memory to speed up pushbacks
	top = 0;
}



template <typename T>
bool MyStack<T>::push(const T item) 
{
	bool ret = true;

	try {
		stack[top] = item;
		top++;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		ret = false;
	}
	
	return ret;
}



template <typename T>
bool MyStack<T>::pop(T & item) 
{
	bool ret = false;

	if (!isEmpty()) {
		item = stack[top - 1];
		stack[top - 1] = NULL;

		top--;
		ret = true;
	}

	return ret;
}



template <typename T>
bool MyStack<T>::getTop(T & item) const 
{
	bool ret = false;

	if (!isEmpty()) {
		item = stack[top - 1];
		
		ret = true;
	}

	return ret;
}



template <typename T>
bool MyStack<T>::isEmpty(void) const 
{
	bool ret = false;

	if (top == 0) {
		ret = true;
	}
	
	return ret;
}



template <typename T>
void MyStack<T>::print(void) const 
{
	std::cout << "Contents of stack: ";
	for (int i = top - 1; i >= 0; i--) {
		char pr[2];
		pr[1] = '\0';
		pr[0] = stack[i];
		std::cout << stack[i] << ' ';
		
	}
	std::cout << '\n';
}



template <typename T>
void MyStack<T>::printNums(void) const 
{
	std::cout << "The result is: ";
	for (int i = top - 1; i < top; i++) {
		std::cout << stack[i] << ' ';
	}
}

