#pragma once
template <class Elem>
class ArrayStack
{
private:
	int size;
	int top;
	Elem *array;
public:
	ArrayStack(int insize);
	~ArrayStack() { delete[] array; }
	void clear() { top = 0; }
	bool push(const Elem& item);
	Elem pop();
	bool topValue(Elem& it) const;
	int length() const { return top; }
	void printStack();
};
