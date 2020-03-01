#pragma once
template <class Elem>
class ArrayStack
{
private:
	int size;
	int top;
	Elem *listArray;
public:
	ArrayStack(int insize);
	~ArrayStack() { delete[] listArray; }
	void clear() { top = 0; }
	bool push(const Elem& item);
	Elem pop();
	bool topValue(Elem& it) const;
	int length() const { return top; }
	void printStack();
};

