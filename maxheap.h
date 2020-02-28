#include<iostream>
using namespace std;

template<class Elem> class maxheap {
private:
	Elem* Heap;   // Pointer to the heap array
	int size;     // Maximum size of the heap
	int n;        // Number of elems now in heap
	void siftdown(int); 	// Put element in place
public:
	void swap(Elem* h,int a,int b) {
		Elem temp=0;
		temp =h[a] ;
		h[a] = h[b];
		h[b] = temp;
	}
	
	maxheap(Elem* h, int num, int max) {
		Heap = h; n = num; size=max; buildHeap(); 
	}
	
	int heapsize() const { return n; }
	
	bool isLeaf(int pos) const { 	//TRUE if it's a leaf
		return (pos >= n/2) && (pos < n);
	}
	
	int leftchild(int pos) const { 
		return 2*pos + 1;
	}
	
	int rightchild(int pos) const { 
		return 2*pos + 2;
	}
	
	int parent(int pos) const { 
		return (pos-1)/2; 
	}
	
	bool insert(const Elem&);
	bool removemax(Elem&);
	bool remove(int, Elem&);
	void printHeap();
	void buildHeap() {for (int i = n/2 - 1; i >= 0; i--) siftdown(i); };
};
