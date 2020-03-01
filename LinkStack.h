#pragma once
#include "node.h"

template <class Elem>class LinkStack{
private:
	Link<Elem>* top;
	int size;
public:
	LinkStack() { top = NULL; size = 0; }
	~LinkStack() { clean(); }
	void clear();
	bool push(const Elem& item);
	bool pop(Elem& it);
	Elem topValue();
	int length() const { return top; }
	void printStack();
};
