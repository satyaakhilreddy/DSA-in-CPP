#include <iostream>
#include "Hashing.h"

Hashing::Hashing(int v) {
	bucket = v;
	li = new list<int>[v];
};

int Hashing::hashFunc(int d) {
	return d % bucket;
};

void Hashing::insertItem(int d) {
	li[hashFunc(d)].push_back(d);
};

void Hashing::deleteItem(int d) {
	list<int>::iterator it;
	for (it = li[hashFunc(d)].begin(); it != li[hashFunc(d)].end(); it++) {
		if (*it == d) {
			break;
		};
	};
	if (it != li[hashFunc(d)].end()) {
		li[hashFunc(d)].erase(it);
	};
};

void Hashing::dispHash() {
	for (int i = 0; i < bucket; i++) {
		cout << i;
		for (auto x : li[i])
			cout << " --> " << x;
		cout << endl;
	};
};