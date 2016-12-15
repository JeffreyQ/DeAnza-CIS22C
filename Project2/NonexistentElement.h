/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/26/2016
* Instructor:	Professor Eftekhari
* File Name:	NonexistentElement.h
*/
//
//  NonexistentElement.h
//  BinarySearchTree
//
//  Created by Kamran Eftekhari on 7/16/16.
//  Copyright © 2016 Kamran Eftekhari. All rights reserved.
//



#ifndef NonexistentElement_h
#define NonexistentElement_h



#include <string>
using namespace std;




class NonexistentElement {
public:
	NonexistentElement(const string& err) :errMsg(err) {}
	string gerError() { return errMsg; }
private:
	string errMsg;
};

#endif /* NonexistentElement_h */
