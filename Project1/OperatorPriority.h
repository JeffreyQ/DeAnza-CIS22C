/*
* Name:		Jeffrey Qiu
* Class:	CIS 22C
* Date:		07/09/2016
* Instructor:	Professor Eftekhari
* File Name:	OperatorPriority.cpp
*
* Description:	This is the header file that enumerates priorities of mathematical operations
*				used by the bool priorityCompare(char, char) function.
*/

#ifndef OPERATOR_PRIORITY_
#define OPERATOR_PRIORITY_

/*

*/






enum OpISP { ISPexpo = 3, ISPmultiply = 2, ISPdivide = 2, ISPplus = 1, 
	ISPminus = 1, ISPleftParen = 0, ISPothers = -1 };

enum OpICP { ICPexpo = 4, ICPmultiply = 2, ICPdivide = 2, ICPplus = 1, 
	ICPminus = 1, ICPleftParen = 4, ICPothers = -1 };


#endif