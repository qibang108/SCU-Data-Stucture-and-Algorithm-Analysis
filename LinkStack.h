#pragma once
#include "node.h"
template <class T>class Link {                               
public:
	T element;     //结点处的值
	Link*next;     //指向下一结点处的指针
	Link(const T& elemval, Link* nextval = NULL)  //拷贝构造函数
	{
		element = elemval; next = nextval;
	}
	Link(Link* nextval = NULL) { next = nextval; }  //设置尾结点
};
template <class Elem>
class LinkStack{
private:
	Link<Elem>* top;
	int size;
public:
	LinkStack() { top = NULL; size = 0; }
	~LinkStack() { clean(); }
	void clean();
	bool push(const Elem& item);
	bool pop(Elem& it);
	Elem topValue();
	int length() const { return top; }
	void printStack();
};

