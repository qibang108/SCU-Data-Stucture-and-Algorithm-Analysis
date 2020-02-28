#include <iostream>
#include "node.h"
using namespace std;

template <class Elem> class LList {
private:
	Link<Elem>* head;        // Point to list header,定义头指针
	Link<Elem>* tail;        // Pointer to last Elem，定义尾指针
	Link<Elem>* fence;       // Last element on left，定义栅栏指针
	int leftcnt;             // Size of left，左边部分元素数
	int rightcnt;            // Size of right，右边部分元素数
	
	// Intialization routine，初始化链表，创建第一个结点
	void init() {            
		fence = tail = head = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}
    
	// Return link nodes to free store，将申请的空间返回给内存
	void removeall()         
	{
		while (head != NULL)
		{
			fence = head;
			head = head->next;
			delete fence;       //当fence不为空指针时，控制fence指针遍历回收内存
		}
	}
public:
	LList() { init(); }
	~LList() { removeall(); }
	void clear() { removeall();   init(); }
	
	void setStart()            
	{
		fence = head;           //令fence=head，定位在表头
		rightcnt += leftcnt;
		leftcnt = 0;
	}

	void setEnd()             
	{
		fence = tail;           //令fence=tail，定位在表尾 
		leftcnt += rightcnt;
		rightcnt = 0;
	}
    
	void next() {
		if (fence != tail)     // Don't move fence if right empty
		{
			fence = fence->next;
			rightcnt--;
			leftcnt++;
		}
	}
	int leftLength() const { return leftcnt; }
	int rightLength() const { return rightcnt; }
	
	bool getValue(Elem& it) const
	{
		if (rightLength() == 0) return false;
		it = fence->next->element;       //获得当前fence指针所指结点下一结点的元素域
		return true;
	}
	
	bool insert(const Elem& item);
	bool append(const Elem& item);
	bool remove(Elem& it);
	bool setPos(int pos);
	void printList();
	void prev();
	void printElem(const int n);
	int findElem(Elem x);
};
