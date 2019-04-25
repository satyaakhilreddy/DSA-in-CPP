#include <iostream>
#include <list>

using namespace std;

class Hashing {
private:
	int bucket;
	list<int> *li;
public:
	Hashing(int v);
	void insertItem(int d);
	void deleteItem(int d);
	int hashFunc(int d);
	void dispHash();
};