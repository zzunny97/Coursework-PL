#include "ExtendableArray.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ElementRef::ElementRef(ExtendableArray& theArray, int i) {
	//cout << "1st constructor" << endl;
	intArrayRef = &theArray;
	index = i;	
}
ElementRef::ElementRef(const ElementRef& other) {
	//cout << "2nd constructor" << endl;
	intArrayRef = other.intArrayRef;
	index = other.index;
}

ElementRef::~ElementRef() {
	//cout << "destructor ElmentRef" << endl;
}

ElementRef& ElementRef::operator=(const ElementRef& rhs) {
	cout << "hello1" << endl;
	cout << "index = " << index << endl;
	cout << "rhs.index = " << rhs.index << endl;
	intArrayRef->arrayPointer[index] = rhs.intArrayRef->arrayPointer[rhs.index];
	cout << "\n\n" << endl;
	return *this;
}

ElementRef& ElementRef::operator=(int val) {
	cout << "hello2" << endl;
	//cout << "2nd ref operatror =" << endl;
	//cout << val << endl;
	//cout << index << endl;
	//cout << intArrayRef->arrayPointer << endl;

	
	intArrayRef->arrayPointer[index] = val;
	
	//cout << "returning" << endl;
	return *this;
}

ElementRef::operator int() const {
	cout << "hello3" << endl;
	//cout << "3rd ref operatror =" << endl;
	return intArrayRef->arrayPointer[index];
}


ExtendableArray::ExtendableArray() {
	arrayPointer = (int*)malloc(sizeof(int)*2);
	arrayPointer[0] = 0;
	arrayPointer[1] = 0;
	size = 2;
}

ExtendableArray::ExtendableArray(const ExtendableArray& other) {
	cout << "copying constructor array" << endl;
	cout << "cur size = " << size << " other size = " << other.size << endl;
	int len = other.size;
	delete[] arrayPointer;
	arrayPointer = (int*)malloc(sizeof(int)*len); 
	size = len;

	for(int i=0; i<len; i++){
		arrayPointer[i] = other.arrayPointer[i];
	}
}

ExtendableArray::~ExtendableArray() {
	cout << "destructor ExtendableArray" << endl;
	//delete[] arrayPointer;
	cout << "why" << endl;
}

ExtendableArray& ExtendableArray::operator=(const ExtendableArray& rhs) {
	int len = rhs.size;
	delete[] arrayPointer;
	arrayPointer = (int*)malloc(sizeof(int)*len);
	size = len;

	for(int i=0; i<len; i++) arrayPointer[i] = rhs.arrayPointer[i];

	//arrayPointer = rhs.arrayPointer;
	//size = rhs.size;

	return *this;
}


ElementRef ExtendableArray::operator[](int i) {
	if(i >= size) {
		//cout << i << " " << size << endl;
		int old_size = size;
		int new_size = i+1;
		arrayPointer = (int*)realloc(arrayPointer, sizeof(int)*(new_size));
		for(int i=old_size; i<new_size; i++) {
			arrayPointer[i] = 0;
		}
		size = new_size;
		cout << "resized to " << new_size << endl;
	}
	cout << "i = " << i << endl;
	ElementRef ret(*this, i);
	cout << "operator[] func end" << endl;	
	return ret;	
}


