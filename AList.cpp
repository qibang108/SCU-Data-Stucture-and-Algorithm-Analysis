#include<iostream>
using namespace std;
class AList {
private:
	int *data; 
	int size;
public:
	AList(int *in,int s){
		data=in ;
		size = s;
	}
	int getSize() {
		return size;
	}
	int setValue(int j, int val) {
		if (j<0 || j>size)return -1;
		data[j] = val;
		return 0;
	}
	void showList() {
		cout << "{ ";
		for (int t = 0; t < size; t++)
		{
			cout << data[t] << " ";
		}
		cout << "}";
	}
};
//Test
int main() {
	int i, size, v;
	int in[6]
	AList al(in,6);
	size = al.getSize();
	
	cout << "Please input numbers: "<<endl;
	for ( i = 0; i < size; i++)
	{
		cin >> v;
		al.setValue(i, v);
	}
	cout << "array["<<size<<"]=";
	al.showList();
	cout << endl;
	
	system("pause");
	return 0;
}
