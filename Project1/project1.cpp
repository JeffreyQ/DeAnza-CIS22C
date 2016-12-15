/*
* Name:		Jeffrey Qiu
* Class:	CIS 22C
* Date:		07/09/2016
* Instructor:	Professor Eftekhari
* File Name:	project1.cpp
*
* For this first programming project I implemented the stack and queue by means of templates
* for evaluating simple mathematical expressions entered by the user. The expressions are 
* first converted from infix notation (e.g. 1 + 2 * 3), and then evaluated in the postfix 
* notation (e.g. 1 2 3 * +). 
*	
*
*/



#include <iostream>
#include <string>
#include <math.h>

#include "OperatorPriority.h"
#include "MyStack.cpp"
#include "MyQueue.cpp"




/*
*	Function Prototypes
*/
int evaluateExpression(void);
void getUserInput(MyQueue<char> &, std::string);
void inToPostfix(MyQueue<char> &, MyQueue<char> &, MyStack<char> &);
bool priorityCompare(char, char);
void evaluatePostfix(MyQueue<char> &, MyStack<double> &);





int main() 
{
	char cont = 'N';
	do {
		evaluateExpression();

		std::cout << "\nWould you like to evaluate another expression? (Y/N) ";
		std::cin >> cont;
		std::cin.ignore();

	} while (cont != 'n' && cont != 'N');

	std::cout << "\nBye, press any key to exit." << std::endl;
	

	return 0;
}






/*
* We initialize a std::string and then assign it the infix expression inputted by the user. Then we determine the size of  
* the user input and initialize MyQueue<char> objects that have a queue size greater than that of the user input.
*
* Input parameters: None
* Output parameters: int
*/
int evaluateExpression() 
{
	std::string inStr = "";
	std::cout << "Please enter an expression in infix: ";
	std::getline(std::cin, inStr);
	std::cout << "You typed: " << inStr << std::endl;
	int inputLength = inStr.length() + 5;	//	setting queue size

	MyQueue<char> Q1(inputLength);
	MyQueue<char> Q2(inputLength);
	MyStack<char> S1;
	MyStack<double> S2;
	
	getUserInput(Q1, inStr);
	
	//Convert infix to postfix
	inToPostfix(Q1, Q2, S1);
	
	//Evaluate postfix expression
	evaluatePostfix(Q2, S2);
	
	S2.printNums();

	return 0;
}






/*
* We enqueue characters from inStr one at a time to inQ1 if they are not some form of whitespace.
*
* Input parameters: MyQueue<char> object, and an input std::string
* Output parameters: None
*/
void getUserInput(MyQueue<char> & inQ1, std::string inStr) 
{
	
	for (int i = 0; i < (int)inStr.length(); i++) {
		char x = inStr[i];	//	if whitespace we do not enqueue

		if (x != ' ' && x != '\t' && x != '\n' && x != '\r') {
			inQ1.enqueue(x);
		}
	}
}






/*
* Having implemented the stack and queue, we can convert the given formatted (whitespace removed)
* mathematical expression from infix notation to postfix notation. inQ1 stores the tokens that make
* up the infix equation entered by the user. Then, it is converted to a postfix expression that is 
* stored in Q2. The stack facilitates the conversion by temporarily storing operators in order of priority.
* 
* Input parameters: MyQueue<char> object, another MyQueue<char> object, and a MyStack<char> object
* Output parameters: None
*/
void inToPostfix(MyQueue<char> & inQ1, MyQueue<char> & inQ2, MyStack<char> & inS1) 
{
	char c = '\0';
	char top = '\0';

	inQ1.enqueue('#');
	inS1.push('#');
	inQ1.dequeue(c);
	inQ1.print();

	while (c != '#') {
		if (c >= '0' && c <= '9') {
			inQ2.enqueue(c);
		}
		else if (c == ')') {
			inS1.getTop(top);
			while (!inS1.isEmpty() && top != '(') {
				inS1.pop(top);
				inQ2.enqueue(top);
				inS1.getTop(top);
			}
			inS1.pop(top);
			inS1.getTop(top);
		}
		else {
			inS1.getTop(top);
			while (!inS1.isEmpty() && priorityCompare(top, c)) {
				inS1.pop(top);
				inQ2.enqueue(top);
				inS1.getTop(top);
			}
			inS1.push(c);
			inS1.getTop(top);
		}
		inQ1.dequeue(c);
	}

	if (!inS1.isEmpty()) {
		inS1.getTop(top);
		while (!inS1.isEmpty() && top != '#') {
			inS1.pop(top);
			inQ2.enqueue(top);
			inS1.getTop(top);
		}
		inS1.pop(top);
	}
	std::cout << "Expression in postfix: ";
	inQ2.print();
}






/*
* This function compares the operator priority (given by our ISP/ICP table) of two character literals
* passed by value, and returns true if the first parameter priority is greater than or equal to the 
* second parameter priority.
*
* Input parameters: two character literals
* Output parameters: boolean value
*/
bool priorityCompare(char stackTop, char incomingChar)
{
	enum OpISP instack;
	enum OpICP incoming;

	switch (stackTop) {
	case '^': instack = ISPexpo;
		break;
	case '*': instack = ISPmultiply;
		break;
	case '/': instack = ISPdivide;
		break;
	case '+': instack = ISPplus;
		break;
	case '-': instack = ISPminus;
		break;
	case '(': instack = ISPleftParen;
		break;
	default: instack = ISPothers;
	}

	switch (incomingChar) {
	case '^': incoming = ICPexpo;
		break;
	case '*': incoming = ICPmultiply;
		break;
	case '/': incoming = ICPdivide;
		break;
	case '+': incoming = ICPplus;
		break;
	case '-': incoming = ICPminus;
		break;
	case '(': incoming = ICPleftParen;
		break;
	default: incoming = ICPothers;
	}

	return instack >= incoming;
}






/*
* We take the postfix notation stored in inQ2 and evaluate it, pushing the results to inS2.
*
* Input parameters: MyQueue<char> object, and MyStack<double> object
* Output parameters: None
*/
void evaluatePostfix(MyQueue<char> & inQ2, MyStack<double> & inS2) 
{
	char op = '\0';
	double op1 = 0.0;
	double op2 = 0.0;

	while (!inQ2.isEmpty()) {
		inQ2.dequeue(op);
		inQ2.print();
		if (op >= '0' && op <= '9') {
			double dubOp = (double)(op - '0');
			inS2.push(dubOp);
		}
		else {
			inS2.pop(op2);
			inS2.pop(op1);

			switch (op) {
			case '+':
				inS2.push(op1 + op2);
				break;
			case '-':
				inS2.push(op1 - op2);
				break;
			case '/':
				inS2.push(op1 / op2);
				break;
			case '*':
				inS2.push(op1 * op2);
				break;
			case '^':
				inS2.push(pow(op1, op2));
				break;
			}
		}
		inS2.print();
	}
}














/*

Please enter an expression in infix: ((2-1)*2^2^3+8/4)
You typed: ((2-1)*2^2^3+8/4)
Contents of queue:  ( 2 - 1 ) * 2 ^ 2 ^ 3 + 8 / 4 ) #
Expression in postfix: Contents of queue:  2 1 - 2 2 3 ^ ^ * 8 4 / +
Contents of queue:  1 - 2 2 3 ^ ^ * 8 4 / +
Contents of stack: 2
Contents of queue:  - 2 2 3 ^ ^ * 8 4 / +
Contents of stack: 1 2
Contents of queue:  2 2 3 ^ ^ * 8 4 / +
Contents of stack: 1
Contents of queue:  2 3 ^ ^ * 8 4 / +
Contents of stack: 2 1
Contents of queue:  3 ^ ^ * 8 4 / +
Contents of stack: 2 2 1
Contents of queue:  ^ ^ * 8 4 / +
Contents of stack: 3 2 2 1
Contents of queue:  ^ * 8 4 / +
Contents of stack: 8 2 1
Contents of queue:  * 8 4 / +
Contents of stack: 256 1
Contents of queue:  8 4 / +
Contents of stack: 256
Contents of queue:  4 / +
Contents of stack: 8 256
Contents of queue:  / +
Contents of stack: 4 8 256
Contents of queue:  +
Contents of stack: 2 256
Contents of queue:
Contents of stack: 258
The result is: 258
Would you like to evaluate another expression? (Y/N) Y
Please enter an expression in infix: ( (2-1)* 2^2^ 3+ 8/ 4)
You typed: ( (2-1)* 2^2^ 3+ 8/ 4)
Contents of queue:  ( 2 - 1 ) * 2 ^ 2 ^ 3 + 8 / 4 ) #
Expression in postfix: Contents of queue:  2 1 - 2 2 3 ^ ^ * 8 4 / +
Contents of queue:  1 - 2 2 3 ^ ^ * 8 4 / +
Contents of stack: 2
Contents of queue:  - 2 2 3 ^ ^ * 8 4 / +
Contents of stack: 1 2
Contents of queue:  2 2 3 ^ ^ * 8 4 / +
Contents of stack: 1
Contents of queue:  2 3 ^ ^ * 8 4 / +
Contents of stack: 2 1
Contents of queue:  3 ^ ^ * 8 4 / +
Contents of stack: 2 2 1
Contents of queue:  ^ ^ * 8 4 / +
Contents of stack: 3 2 2 1
Contents of queue:  ^ * 8 4 / +
Contents of stack: 8 2 1
Contents of queue:  * 8 4 / +
Contents of stack: 256 1
Contents of queue:  8 4 / +
Contents of stack: 256
Contents of queue:  4 / +
Contents of stack: 8 256
Contents of queue:  / +
Contents of stack: 4 8 256
Contents of queue:  +
Contents of stack: 2 256
Contents of queue:
Contents of stack: 258
The result is: 258
Would you like to evaluate another expression? (Y/N) Y
Please enter an expression in infix: (9*2^8)/3*(3+8*(8/4))
You typed: (9*2^8)/3*(3+8*(8/4))
Contents of queue:  9 * 2 ^ 8 ) / 3 * ( 3 + 8 * ( 8 / 4 ) ) #
Expression in postfix: Contents of queue:  9 2 8 ^ * 3 / 3 8 8 4 / * + *
Contents of queue:  2 8 ^ * 3 / 3 8 8 4 / * + *
Contents of stack: 9
Contents of queue:  8 ^ * 3 / 3 8 8 4 / * + *
Contents of stack: 2 9
Contents of queue:  ^ * 3 / 3 8 8 4 / * + *
Contents of stack: 8 2 9
Contents of queue:  * 3 / 3 8 8 4 / * + *
Contents of stack: 256 9
Contents of queue:  3 / 3 8 8 4 / * + *
Contents of stack: 2304
Contents of queue:  / 3 8 8 4 / * + *
Contents of stack: 3 2304
Contents of queue:  3 8 8 4 / * + *
Contents of stack: 768
Contents of queue:  8 8 4 / * + *
Contents of stack: 3 768
Contents of queue:  8 4 / * + *
Contents of stack: 8 3 768
Contents of queue:  4 / * + *
Contents of stack: 8 8 3 768
Contents of queue:  / * + *
Contents of stack: 4 8 8 3 768
Contents of queue:  * + *
Contents of stack: 2 8 3 768
Contents of queue:  + *
Contents of stack: 16 3 768
Contents of queue:  *
Contents of stack: 19 768
Contents of queue:
Contents of stack: 14592
The result is: 14592
Would you like to evaluate another expression? (Y/N) N

Bye, press any key to exit.

*/