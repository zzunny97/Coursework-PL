#include "ExtendableArray.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ElementRef::ElementRef(ExtendableArray& theArray, int i) {
	intArrayRef = &theArray;
	index = i;	
}
ElementRef::ElementRef(const ElementRef& other) {
	intArrayRef = other.intArrayRef;
	index = other.index;
}

ElementRef::~ElementRef() {

}

ElementRef& ElementRef::operator=(const ElementRef& rhs) {
	intArrayRef->arrayPointer[index] = rhs.intArrayRef->arrayPointer[rhs.index];
	return *this;
}

ElementRef& ElementRef::operator=(int val) {
	cout << "ref operator=" << endl;
	intArrayRef->arrayPointer[index] = val;
	return *this;
}

ElementRef::operator int() const {
	cout << "ref operator int()" << endl;
	return intArrayRef->arrayPointer[index];
}


ExtendableArray::ExtendableArray() {
	arrayPointer = (int*)malloc(sizeof(int)*2);
	arrayPointer[0] = 0;
	arrayPointer[1] = 0;
	size = 2;
}

ExtendableArray::ExtendableArray(const ExtendableArray& other) {
	int len = other.size;
	arrayPointer = (int*)malloc(sizeof(int)*len); 
	size = len;
	
	for(int i=0; i<len; i++){
		arrayPointer[i] = other.arrayPointer[i];
	}
}

ExtendableArray::~ExtendableArray() {

}

ExtendableArray& ExtendableArray::operator=(const ExtendableArray& rhs) {
	int len = rhs.size;
	delete[] arrayPointer;
	arrayPointer = (int*)malloc(sizeof(int)*len);
	size = len;

	for(int i=0; i<len; i++) arrayPointer[i] = rhs.arrayPointer[i];
	return *this;
}


ElementRef ExtendableArray::operator[](int i) {
	if(i >= size) {
		int old_size = size;
		int new_size = i+1;
		arrayPointer = (int*)realloc(arrayPointer, sizeof(int)*(new_size));
		for(int i=old_size; i<new_size; i++) {
			arrayPointer[i] = 0;
		}
		size = new_size;
	}
	ElementRef ret(*this, i);
	return ret;	
}


