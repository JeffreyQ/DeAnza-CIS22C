/*
* Name:		Jeffrey Qiu
* Class:	CIS 22C
* Date:		07/09/2016
* Instructor:	Professor Eftekhari
* File Name:	MyQueue.h
*
* Description:	This is the header file for the MyQueue class.
*/

#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <vector>
#include <iterator>

/*
 * MyQueue class definition
 *
 * There are four private members:
 *		std::vector<T> queue;
 *			The queue is circularly implemented in a "dynamically allocated" std::vector.
 *
 *		int head;
 *			The head int is initialized to 0 and points to the first element of the queue.
 *
 *		int tail;
 *			The tail int is initialized to 0 and points to the next available space for enqueue().
 *
 *		int qSize;
 *			The qSize int keeps track of the size of the queue.
 *
 *
 * There are two constructors, with one taking no parameters and the other taking one parameter.
 *
 *	MyQueue();
 *		//Post-condition: MyQueue object is initialized with a size of 100.
 *		//Pre-condition: None.
 *
 *	MyQueue(int size);
 *		//Pre-condition: One int type parameter size.
 *		//Post-condition: MyQueue object is initialized with the size of size.
 *
 * 
 * There are four queue operations:
 *  
 *	bool enqueue(const T & item);
 *		The enqueue() function takes a const object of generic type T and inserts it at the back of the queue.
 *		It returns true if the item was successfully inserted and false if otherwise.
 *		
 *	bool dequeue(T & item);
 *		The dequeue() function takes an object of generic type T and assigns it the front-most element of the 
 *		queue. Then it removes the front-most element and returns true if successful and false if not.
 *
 *	bool isEmpty(void) const;
 *		The isEmpty() function does not take any parameters and returns true if the queue is empty and false if not empty.
 *
 *	void print(void) const;
 *		The print() function prints the elements of the queue from front to back separated by a single space.
*/






template <typename T> class MyQueue {
private:
	std::vector<T> queue;
	int head = 0; 
	int tail = 0;
	int qSize = 0;

public:
	MyQueue();
	MyQueue(int size);
	bool enqueue(const T & item);
	bool dequeue(T & item);
	bool isEmpty(void) const;
	void print(void) const;
};
#endif
