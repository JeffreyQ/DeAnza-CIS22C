/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/26/2016
* Instructor:	Professor Eftekhari
* File Name:	SearchTree.h
*/
//
//  SearchTree.h
//  BinarySearchTree
//
//



#ifndef SearchTree_h
#define SearchTree_h



#include "LinkedBinaryTree.h"
#include "Entry.h"
#include "NonexistentElement.h"
#include <cmath>
#include <vector>



// a binary search tree
template <typename E>
class SearchTree {
public: 						// public types
	typedef typename E::Key K;				// a key
	typedef typename E::Value V;			// a value

protected:
	typedef LinkedBinaryTree BinaryTree;			// linked binary tree
	typedef typename BinaryTree::Position TPos;		// position in the tree

public:
	class Iterator {	                      		// an iterator/position
	private:
		TPos v;						// which entry
	public:
		Iterator(const TPos& vv) : v(vv) { }	// constructor
		const E& operator*() const { return *v; }	// get entry (read only)
		E& operator*() { return *v; }			// get entry (read/write)
		bool operator==(const Iterator& p) const { return v == p.v; } // are iterators equal?
		Iterator& operator++();				// inorder successor
		friend class SearchTree;				// give search tree access
	};

public:						// public functions
	SearchTree();					// constructor
	int size() const { return n; } 					// number of entries
	bool empty() const { return n == 0; }					// is the tree empty?
	void erase(const K& k) throw(NonexistentElement);	// remove key k entry
	void erase(const Iterator& p);			// remove entry at p

	Iterator begin();					// iterator to first entry
	Iterator end();					// iterator to end entry
	Iterator find(const K& k);				// find entry with key k
	Iterator insert(const K& k, const V&x);		// insert (k,x)

	BinaryTree& getTree() { return T; }
	void setTree(BinaryTree incT) { T = incT; }

	void balance();
	void list2Vector(std::list<TPos>& pl, std::vector<TPos>& vc);
	void recursiveInsert(std::vector<TPos> vc, int lowIdx, int highIdx, SearchTree<E> newT);

protected:
	TPos root() const;					// get virtual root
	TPos finder(const K& k, const TPos& v);		// find utility
	TPos inserter(const K& k, const V& x);		// insert utility
	TPos eraser(TPos& v);				// erase utility

private: 						// member data
	BinaryTree T;	// the binary tree
	int n;						// number of entries

public:
	// ...insert Iterator class declaration here
};



template <typename E>					// inorder successor
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++() {
	TPos w = v.right();

	if (!w.isExternal()) {				// have right subtree?
		do {
			v = w;
			w = w.left();
		}			// move down left chain
		while (!w.isExternal());
	}
	else {
		w = v.parent();					// get parent
		while (v == w.right())				// move up right chain
		{
			v = w;
			w = w.parent();
		}
		v = w;						// and first link to left
	}
	return *this;
}



template <typename E>					// constructor
SearchTree<E>::SearchTree() : T(), n(0) {
	T.addRoot();
	T.expandExternal(T.root());
}	// create the super root



template <typename E>					// remove key k entry
void SearchTree<E>::erase(const K& k) throw(NonexistentElement) {
	TPos v = finder(k, root());				// search from virtual root
	if (v.isExternal())					// not found?
		throw NonexistentElement("Erase of nonexistent");
	eraser(v);						// remove it
}



template <typename E>					// erase entry at p
void SearchTree<E>::erase(const Iterator& p) {
	eraser(p.v);
}



template <typename E>					// find entry with key k
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k) {
	TPos v = finder(k, root());				// search from virtual root
	if (!v.isExternal()) return Iterator(v);		// found it
	else return end();					// didn't find it
}



template <typename E>					// insert (k,x)
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x) {
	TPos v = inserter(k, x);
	return Iterator(v);
}




template <typename E>
void SearchTree<E>::balance() {
	std::vector<TPos> vc;
	SearchTree<E> newT;

	std::list<TPos> inList;
	inList = getTree().inPositions();
	list2Vector(inList, vc);
	recursiveInsert(vc, 0, vc.size() - 1, newT);

	while (!empty()) {
		TPos virtualRoot = root();
		eraser(virtualRoot);
	}
	newT.getTree().printTraversals();
}



template <typename E>
void SearchTree<E>::list2Vector(std::list<TPos>& pl, std::vector<TPos>& vc) {
	std::list<TPos>::const_iterator it;
	for (it = pl.begin(); it != pl.end(); ++it) {
		if (!(*it).isExternal()) {
			vc.push_back((*it));
		}
	}
}



template <typename E>
void SearchTree<E>::recursiveInsert(std::vector<TPos> vc, int lowIdx, int highIdx, SearchTree<E> newT) {
	if (lowIdx <= highIdx) {
		int midIdx = (int)floor((lowIdx + highIdx) / 2);
		newT.insert(vc[midIdx].key(), vc[midIdx].value());
		recursiveInsert(vc, lowIdx, midIdx - 1, newT);
		recursiveInsert(vc, midIdx + 1, highIdx, newT);
	}
}



template <typename E>					// iterator to first entry
typename SearchTree<E>::Iterator SearchTree<E>::begin() {
	TPos v = root();					// start at virtual root
	while (!v.isExternal()) v = v.left();		// find leftmost node
	return Iterator(v.parent());
}



template <typename E>					// iterator to end entry
typename SearchTree<E>::Iterator SearchTree<E>::end() {
	return Iterator(T.root());
}



template <typename E>					// get virtual root
typename SearchTree<E>::TPos SearchTree<E>::root() const {
	return T.root().left();
}				// left child of super root



template <typename E>					// find utility
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v) {
	if (v.isExternal())
		return v;			// key not found; don't know if correct
	if (k < v.key())
		return finder(k, v.left());	// search left subtree
	else if (v.key() < k)
		return finder(k, v.right());	// search right subtree
	else
		return v;					// found it here
}



template <typename E>					// insert utility
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x) {
	TPos v = finder(k, root());				// search from virtual root
	while (!v.isExternal())				// key already exists?
		v = finder(k, v.right());				// look further

	T.expandExternal(v);				// add new internal node
	v.setKey(k);
	v.setValue(x);			// set entry

	n++;						// one more entry
	return v;						// return insert position
}



template <typename E>					// remove utility
typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos& v) {
	TPos w;
	if (v.left().isExternal()) w = v.left();		// remove from left
	else if (v.right().isExternal()) w = v.right();	// remove from right
	else {						// both internal?
		w = v.right();					// go to right subtree
		do { w = w.left(); } while (!w.isExternal());	// get leftmost node
		TPos u = w.parent();
		v.setKey(u.key());
		v.setValue(u.value());	// copy w's parent to v
	}
	n--;						// one less entry
	return T.removeAboveExternal(w);			// remove w and parent
}


#endif /* SearchTree_h */
