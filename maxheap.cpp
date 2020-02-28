#include "maxheap.h"
#include<iostream>

using namespace std;

template<class Elem>void maxheap<Elem>::siftdown(int pos){

	while (!isLeaf(pos)) 
	{
		int j = leftchild(pos);

		int rc = rightchild(pos);

		if ((rc < n) && (Heap[j] < Heap[rc])) { j = rc; }	//choose the node which value bigger

		if (Heap[pos] > Heap[j]) { break; }

		else swap(Heap, pos, j);	//swap root and its max-childnode

		pos = j;			//restart in childnode

	}
}

template<class Elem>bool maxheap<Elem>::insert(const Elem &val){

	if (n >= size) return false;	// Heap is full 

	int curr = n++;

	Heap[curr] = val;

	// Now sift up until curr's parent> curr 
	while ((curr != 0) && (Heap[curr]>Heap[parent()]))
	{
		swap(Heap, curr, parent(curr));
		curr = parent(curr);
	}

	return true;
}

template<class Elem>bool maxheap<Elem>::removemax(Elem &it){

	if (n == 0) return false; 	// Heap is empty 

	swap(Heap, 0, --n);

	if (n != 0) siftdown(0); 	// Siftdown new root val 

	it = Heap[n]; 

	return true;
}



template<class Elem>void maxheap<Elem>::printHeap(){

	cout << "[";

	for (int i = 0; i < n; i++) 
	{
		cout << Heap[i] << " ";
	}

	cout << "]"<<endl;
}

//test
int main() {

	int h[10] = { 23,45,72,89,9,7,2,38,90,25 };

	int *hh = h;

	maxheap<int>h1(hh, 10, 20);

	h1.printHeap();

	system("pause");
	return 0;
}
