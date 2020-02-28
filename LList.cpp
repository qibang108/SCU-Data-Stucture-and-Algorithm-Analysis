#include <iostream>
#include "LList.h"
using namespce std;

//申请新结点空间-->新结点指针域指向原fence指针下一结点-->原fence指针指向新结点
template <class Elem>
bool LList<Elem>::insert(const Elem& item)  
{            
	fence->next = new Link<Elem>(item, fence->next);    
	if (tail == fence) tail = fence->next;
	rightcnt++;
	return true;
}

// Append Elem to end of the list，在表尾插入元素
template <class Elem>
bool LList<Elem>::append(const Elem& item)
{
	tail = tail->next = new Link<Elem>(item, NULL);
	rightcnt++;
	return true;
}

// Remove and return first Elem in right，删除左边最后一个结点
template <class Elem> 
bool LList<Elem>::remove(Elem& it) {
	if (fence->next == NULL) return false;
	it = fence->next->element; // Remember value
	Link<Elem>* ltemp = fence->next;  // Remember link node
	fence->next = ltemp->next; // Remove
	if (tail == ltemp) // Reset tail
		tail = fence;
	delete ltemp;      // Reclaim space
	rightcnt--;
	return true;
}

//fence指针移动到指定位置
template <class Elem>
bool LList<Elem>::setPos(int pos) {         
	if ((pos < 0) || (pos > rightcnt + leftcnt))
		return false;
	fence = head;
	for (int i = 0; i < pos; i++)
		fence = fence->next;
	return true;
}

template <class Elem> 
void LList<Elem>::printList() {
	Link<Elem>* temp = head;
	cout << "< ";
	while (temp != fence) {        //输出左半边
		cout << temp->next->element << " ";
		temp = temp->next;
	}
	cout << "||";
	while (temp->next != NULL) {    //输出右半边
		cout << temp->next->element << "  ";
		temp = temp->next;
	}
	cout <<">"<< endl;
}

// Move fence one step left; no change if left is empty
template <class Elem> void
LList<Elem>::prev() {
	Link<Elem>* temp = head;
	if (fence == head) return; 	// No prev Elem
	while (temp->next != fence)
		temp = temp->next;	//将temp指针移到fence前一位
	fence = temp;
	leftcnt--;
	rightcnt++;
}

template <class Elem>
void LList<Elem>::printElem(const int n) {
	int i = 0;
	fence = head;
	for ( i = 0; i < n; i++)
	{
		fence = fence->next;
	}
	cout << "the " << n << "th number in this list is " <<"'"<< fence->element<<"'"<< endl;
}

//在链表中查找元素，如果存在输出位置，不存在输出0
template <class Elem>
int LList<Elem>::findElem(Elem x) {
	int i = 1;
	fence = head;
	while(fence!= NULL) {
		if (fence->element == x) {
			return i;
		}
		i++;
		fence = fence->next;
	}
	return 0;
}

//test
int main() {
	LList<int> list_01;
	list_01.insert(3);
	list_01.insert(6);
	list_01.insert(1);
	list_01.insert(0);
	list_01.setPos(2);
	list_01.insert(13);
	list_01.insert(134);
	list_01.insert(23);
	list_01.insert(44);
	list_01.insert(35);
	list_01.insert(56);
	list_01.printList();
	list_01.printElem(4);
	cout << list_01.findElem(10) << endl;
	list_01.~LList();
	system("pause");
	return 0;
}
