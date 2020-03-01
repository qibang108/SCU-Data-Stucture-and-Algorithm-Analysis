#include "LinkStack.h"
#include<iostream>
using namespace std;

template <class Elem>void LinkStack<Elem>::clear() {
	
	while (top!=NULL)
	{
		Link <Elem> *temp = top;
		top = top->next;
		size = 0;
		delete temp;
	}
}

template <class Elem>bool LinkStack<Elem>::push(const Elem& item) {
	
	top = new Link<Elem>(item, top);   //第一次push操作top=NULL，之后的push操作把之前的top地址赋值给新结点的next域，top指向新结点
	size++;
	return true;
}

template <class Elem>bool LinkStack<Elem>::pop(Elem&it) {

	if (size == 0) return false; 
	it=top->element;          //返回栈顶元素
	Link<Elem>* ltemp = top->next;       
	delete top;               //删除top所指结点
	top = ltemp;              //将ltemp的地址赋值给top
	size--;
	return true;
}

template <class Elem>Elem LinkStack<Elem>::topValue(){

	if (size == 0) return -1;
	return top->element;
}

template <class Elem>void LinkStack<Elem>::printStack() {

	Link<Elem> *ptemp = top;
	cout << "[";
	for (int i = 1; i < size; i++)
	{
		cout << ptemp->element << " ";
		ptemp = ptemp->next;
	}
	cout << ptemp->element << "]"<<endl;
}

//test
int main() {
	
	int popValue; //定义变量保存pop返回值
	LinkStack<int>stack1;
	stack1.push(3);
	stack1.push(5);
	stack1.push(9);
	stack1.push(20);
	stack1.printStack();
	stack1.pop(popValue); //passed-by-refenence，可改变其值
	cout << popValue;
	stack1.printStack();

	system("pause");
	return 0; 
}  


