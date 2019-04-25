#include <iostream>
#include "Hashing.h"

int main() {
	Hashing h(7);
	h.insertItem(1);
	h.insertItem(1);
	h.insertItem(2);
	h.insertItem(3);
	h.insertItem(4);
	h.insertItem(5);
	h.insertItem(6);
	h.insertItem(7);
	h.insertItem(8);

	h.dispHash();

	h.deleteItem(1);

	h.dispHash();
	return 0;
};