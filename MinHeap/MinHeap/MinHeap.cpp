#include <iostream>

using namespace std;

class MinHeap {
private:
	int capacity;
	int size;
	int *hp;
public:
	MinHeap(int v) {
		hp = new int[v];
		capacity = v;
		size = 0;
	};

	int parent(int i) {
		return (i - 1) / 2;
	};

	int left(int i) {
		return (2 * i + 1);
	};

	int right(int i) {
		return (2 * i + 2);
	};

	void swap(int *x,int *y) {
		int tmp = *x;
		*x = *y;
		*y = tmp;
	};

	void insert(int d) {
		if (size > capacity) {
			cout << "Heap is Full" << endl;
		};

		int i=size++;
		hp[i] = d;
		
		while (i != 0 && hp[parent(i)]>hp[i]) {
			swap(&hp[i], &hp[parent(i)]);
			i = parent(i);
		};
	};

	void decrease(int i, int d) {
		hp[i] = d;

		while (i != 0 && hp[parent(i)] > hp[i]) {
			swap(&hp[i], &hp[parent(i)]);
			i = parent(i);
		};
	};

	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;

		if (l < size && hp[l] < hp[i]) {
			smallest = l;
		};

		if (r < size && hp[r] < hp[smallest]) {
			smallest = r;
		};

		if (smallest != i) {
			swap(&hp[i], &hp[smallest]);
			heapify(smallest);
		};
	};

	int extractMin() {
		if (size == 0) {
			return INT_MIN;
		};

		if (size == 1) {
			size--;
			return hp[size];
		};

		int root = hp[0];
		hp[0] = hp[size - 1];
		size--;
		heapify(0);

		return root;
	};

	void delkey(int i) {
		decrease(i, INT_MIN);
		extractMin();
	};

	void printheap() {
		for (int i = 0; i < size; i++) {
			cout << hp[i] << " ";
		};
		cout << endl;
	};
};

int main() {
	MinHeap mh(10);
	mh.insert(0);
	mh.insert(1);
	mh.insert(2);
	mh.insert(3);
	mh.insert(4);
	mh.insert(5);

	mh.printheap();

	mh.delkey(1);

	mh.printheap();
};