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
	intArrayRef = NULL;
}

ElementRef& ElementRef::operator=(const ElementRef& rhs) {
	// a[i+5] = b[i];
	// memory realloc needed
	if(index >= intArrayRef->size) {
		int old_size = intArrayRef->size;
		int new_size = index+1;
		intArrayRef->arrayPointer = (int*)realloc(intArrayRef->arrayPointer, sizeof(int)*(new_size));
				
		for(int i=old_size; i<new_size; i++) {
			intArrayRef->arrayPointer[i] = 0;
		}
		intArrayRef->size = new_size;
	}
	intArrayRef->arrayPointer[index] = rhs.intArrayRef->arrayPointer[rhs.index];
	return *this;
}

ElementRef& ElementRef::operator=(int val) {
	// a[i] = i;
	// memory realloc needed

	if(index >= intArrayRef->size) {
		int old_size = intArrayRef->size;
		int new_size = index+1;
		intArrayRef->arrayPointer = (int*)realloc(intArrayRef->arrayPointer, sizeof(int)*(new_size));
				
		for(int i=old_size; i<new_size; i++) {
			intArrayRef->arrayPointer[i] = 0;
		}
		intArrayRef->size = new_size;
	}

	intArrayRef->arrayPointer[index] = val;
	return *this;
}

ElementRef::operator int() const {
	// cout << a[i] << endl;
	// no memory realloc
	if(index >= intArrayRef->size) return 0;	
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
	delete[] arrayPointer;
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
	ElementRef ret(*this, i);
	return ret;	
}


