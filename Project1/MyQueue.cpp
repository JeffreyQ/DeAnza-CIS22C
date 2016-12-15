/*
* Name:		Jeffrey Qiu
* Class:	CIS 22C
* Date:		07/09/2016
* Instructor:	Professor Eftekhari
* File Name:	MyQueue.cpp
*
* Description:	This is the implementation file for the MyQueue class.
*/



#include <iostream>
#include <exception>

#include "MyQueue.h"


const int INITIAL_QUEUE_SIZE = 100;






template <typename T>
MyQueue<T>::MyQueue() 
{
	queue.reserve(INITIAL_QUEUE_SIZE);	// Allocate memory to speed up pushbacks
	qSize = INITIAL_QUEUE_SIZE;
}



template <typename T>
MyQueue<T>::MyQueue(int size) 
{
	queue.reserve(size);	// Allocate memory to speed up pushbacks
	qSize = size;
}



template <typename T>
bool MyQueue<T>::enqueue(const T & item) 
{
	bool ret = true;
	
	try {
		queue[(tail % qSize)] = item;
		tail = (tail + 1) % qSize;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		ret = false;
	}
	
	return ret;
}



template <typename T>
bool MyQueue<T>::dequeue(T & item) 
{
	bool ret = false;

	if (!isEmpty()) {
		item = queue[head];
		queue[head] = NULL;

		head = (head + 1) % qSize;

		ret = true;
	}

	return ret;
}



template <typename T>
bool MyQueue<T>::isEmpty(void) const 
{
	bool ret = false;

	if (head == tail) {
		ret = true;
	}
	
	return ret;
}



template <typename T>
void MyQueue<T>::print(void) const 
{
	int i = head;
	std::cout << "Contents of queue: ";

	while(i != tail) {
		std::cout << ' ' << queue[i];
		i = (i + 1) % qSize;
	}
	std::cout << '\n';
}