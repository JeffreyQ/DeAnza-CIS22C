/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/26/2016
* Instructor:	Professor Eftekhari
* File Name:	LinkedBinaryTree.h
*/

//
//  LinkedBinaryTree.h
//  BinarySearchTree
//



#ifndef LinkedBinaryTree_h
#define LinkedBinaryTree_h




#include "Entry.h"
#include <list>
#include <iostream>
#include <stdio.h> // printf();




typedef int K; // base element type
typedef int V;

class LinkedBinaryTree {
	typedef Entry<K, V> Elem;

protected:
	struct Node {					// a node of the tree

		Elem elt;                       // element value
		Node*   par;					// parent
		Node*   left;					// left child
		Node*   right;					// right child
		Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
	};

public:

	class Position {					// position in the tree
	private:
		Node* v;						// pointer to the node

	public:
		Position(Node* _v = NULL) : v(_v) { }		// constructor
		Elem& operator*() const { return v->elt; } // get element

		Position left() const { return Position(v->left); }		// get left child
		Position right() const { return Position(v->right); }	// get right child
		Position parent() const { return Position(v->par); } 	// get parent

		bool isRoot() const { return v->par == NULL; }			// root of the tree?
		bool isExternal() const { return v->left == NULL && v->right == NULL; }		// an external node?
		bool operator ==(const Position &p)const { return v == p.v; }

		const K& key() const { return v->elt.key(); }		// get key (read only)
		const V& value() const { return v->elt.value(); }	// get value (read only)
		void setKey(const K& k) { (v->elt).setKey(k); }		// set key
		void setValue(const V& vv) { (v->elt).setValue(vv); }

		friend class LinkedBinaryTree;			// give tree access
	};

	typedef std::list<Position> PositionList;		// list of positions

public:
	LinkedBinaryTree();					// constructor
	int size() const;					// number of nodes
	bool empty() const;					// is tree empty?

	Position root() const;				// get the root
	PositionList prePositions() const;  			// list of nodes
	PositionList inPositions() const;  			// list of nodes
	PositionList postPositions() const;  			// list of nodes
	Position removeAboveExternal(const Position& p);	// remove p and parent

	void addRoot();					// add root to empty tree
	void expandExternal(const Position& p);		// expand external node
	void printTraversals() const;
	// housekeeping functions omitted...

protected: 						// local utilities
	void preorder(Node* v, PositionList& pl) const;	// preorder utility
	void inorder(Node* v, PositionList& pl) const;
	void postorder(Node* v, PositionList& pl) const;
	void iterateList(PositionList& pl) const;

private:
	Node* _root;					// pointer to the root
	int n;						// number of nodes
};



LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) { }		// constructor



																	// number of nodes
int LinkedBinaryTree::size() const {
	return n;
}



// is tree empty?
bool LinkedBinaryTree::empty() const {
	return size() == 0;
}



// get the root
LinkedBinaryTree::Position LinkedBinaryTree::root() const {
	return Position(_root);
}



// list of all nodes
LinkedBinaryTree::PositionList LinkedBinaryTree::prePositions() const {
	PositionList pl;
	preorder(_root, pl);					// preorder traversal

	return PositionList(pl);				// return resulting list
}



LinkedBinaryTree::PositionList LinkedBinaryTree::inPositions() const {
	PositionList pl;
	inorder(_root->left, pl);					// preorder traversal

	return PositionList(pl);				// return resulting list
}



LinkedBinaryTree::PositionList LinkedBinaryTree::postPositions() const {
	PositionList pl;
	postorder(_root, pl);					// preorder traversal

	return PositionList(pl);				// return resulting list
}



LinkedBinaryTree::Position				// remove p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p) {
	Node* w = p.v;
	Node* v = w->par;			// get p's node and parent
	Node* sib = (w == v->left ? v->right : v->left);

	if (v == _root) {					// child of root?
		_root = sib;					// ...make sibling root
		sib->par = NULL;
	}
	else {
		Node* gpar = v->par;				// w's grandparent
		if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
		else gpar->right = sib;
		sib->par = gpar;
	}

	delete w;
	delete v;					// delete removed nodes

	n -= 2;						// two fewer nodes
	return Position(sib);
}



// add root to empty tree
void LinkedBinaryTree::addRoot() {
	_root = new Node;
	n = 1;
}



// expand external node
void LinkedBinaryTree::expandExternal(const Position& p) {
	Node* v = p.v;						// p's node

	v->left = new Node;					// add a new left child
	v->left->par = v;					// v is its parent
	v->right = new Node;				// and a new right child
	v->right->par = v;					// v is its parent

	n += 2;								// two more nodes
}



void LinkedBinaryTree::printTraversals() const {

	PositionList preList;
	PositionList inList;
	PositionList postList;

	preorder(root().v->left, preList);
	inorder(root().v->left, inList);
	postorder(root().v->left, postList);

	std::cout << "Pre-order: " << "\t";
	iterateList(preList);
	std::cout << std::endl;

	std::cout << "In-order: " << "\t";
	iterateList(inList);
	std::cout << std::endl;

	std::cout << "Post-order: " << "\t";
	iterateList(postList);
	std::cout << std::endl;


}



// preorder traversal
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
	pl.push_back(Position(v));				// add this node

	if (v->left != NULL)					// traverse left subtree
		preorder(v->left, pl);

	if (v->right != NULL)					// traverse right subtree
		preorder(v->right, pl);
}



void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const {
	LinkedBinaryTree::Position w = v;

	if (!w.isExternal()) {
		inorder(v->left, pl);
	}

	pl.push_back(Position(v));

	if (!w.isExternal()) {
		inorder(v->right, pl);
	}
}



void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const {
	if (v->left != NULL)
		postorder(v->left, pl);

	if (v->right != NULL)
		postorder(v->right, pl);

	pl.push_back(Position(v));


}



void LinkedBinaryTree::iterateList(PositionList& pl) const {
	std::list<Position>::const_iterator it;
	for (it = pl.begin(); it != pl.end(); ++it) {
		if (!(*it).isExternal())
			printf("%d ", (*it).key());
	}
}

#endif /* LinkedBinaryTree_h */
