#include "ArrayStack.h"
#include<iostream>
using namespace std;

template <class Elem>ArrayStack<Elem>::ArrayStack(int insize) {      //定义数组大小
	
	size = insize;
	top = 0;
	array = new Elem[insize];
}

template <class Elem>bool ArrayStack<Elem>::push(const Elem& item) {
	
	if (top == size) return false;       // Stack is full 
	else {
		array[top++] = item;        //先执行listArray[top]=item,  再执行top=top+1
		return true;
	}
}

template <class Elem>Elem ArrayStack<Elem>::pop() {
	
	if (top == 0) return -1;
	else return array[--top];           //先执行top=top-1，再执行return语句
}

template <class Elem>bool ArrayStack<Elem>::topValue(Elem& it)const {
		
	if (top == 0) return false;
	else { 
		it = array[top - 1]; 
		return true;
	}
}

template <class Elem>void ArrayStack<Elem>::printStack() {
	
	cout << "[ ";
	for (int i = 0; i < top; i++)
	{
		cout << array[i] << " ";
	}
	cout << "] " << endl;
}

//test
int main() {
	ArrayStack<int>stack_01(5);
	stack_01.push(13);
	stack_01.push(35);
	stack_01.push(58);
	stack_01.pop();
	stack_01.push(9);
	stack_01.push(22);
	stack_01.printStack();
	cout <<"one number out:"<< stack_01.pop() << endl;
	cout << "after pop: ";
	stack_01.printStack();
	system("pause");
	return 0;
}
