/*
* Name:		Jeffrey Qiu
* SID: 		20277789
* Class:	CIS 22C
* Date:		07/26/2016
* Instructor:	Professor Eftekhari
* File Name:	Entry.h
*/



#ifndef Entry_h
#define Entry_h


template <typename K, typename V>
class Entry {						// a (key, value) pair
public:						// public types
	typedef K Key;					// key type
	typedef V Value;					// value type

public:						// public functions
	Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) { }	// constructor

	const K& key() const { return _key; }		// get key (read only)
	const V& value() const { return _value; }		// get value (read only)

	void setKey(const K& k) { _key = k; }		// set key
	void setValue(const V& v) { _value = v; }		// set value

private:						// private data
	K _key;						// key
	V _value;						// value
};

#endif /* Entry_h */
