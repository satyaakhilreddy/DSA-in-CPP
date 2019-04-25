#include <iostream>
using namespace std;

class Linkedlist {
private:
	struct Node {
		int data;
		Node *next;
	};
	int count;
	Node *head;
public:
	Linkedlist() {
		head = nullptr;
		count = 0;
	};

	void addHead(int d) {
		Node *newnode = new Node;
		newnode->data = d;
		if (count == 0) {
			head = newnode;
			count++;
			return;
		};
		newnode->next = head;
		head = newnode;
		count++;
		return;
	};

	void addTail(int d) {
		Node *newnode = new Node;
		newnode->data = d;
		if (count == 0) {
			head = newnode;
			count++;
			return;
		};

		Node *curr = new Node;
		curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		};
		curr->next = newnode;
		count++;
		return;
	};

	void addIndex(int i, int d) {
		if (i > count - 1) {
			return;
		};

		if (i == 0) {
			addHead(d);
			return;
		};

		if (i == count - 1) {
			addTail(d);
			return;
		};

		Node *curr = new Node;
		Node *prev = new Node;
		curr = head;
		prev = head;
		for (int k = 0; k < i; k++) {
			prev = curr;
			curr = curr->next;
		};
		Node *newnode = new Node;
		newnode->data = d;
		prev->next = newnode;
		newnode->next = curr;
		count++;
		return;
	};

	void delnode(int i) {
		if (i > count - 1 || count == 0) {
			return;
		};

		if (i == 0) {
			Node *tmp = head;
			head = head->next;
			delete tmp;
			count--;
			return;
		};

		Node *curr = new Node;
		Node *prev = new Node;
		curr = head;
		prev = head;
		for (int k = 0; k < i; k++) {
			prev = curr;
			curr = curr->next;
		};
		prev->next = curr->next;
		count--;
		delete curr;
		return;
	};

	int getSize() {
		return count;
	};

	void printList() {
		if (count == 0) {
			cout << "List is empty" << endl;
			return;
		};
		Node *tmp = new Node;
		tmp = head;
		for (int i = 0; i < count; i++) {
			cout << tmp->data << endl;
			tmp = tmp->next;
		};

		return;
	};
};

int main() {
	Linkedlist lt;
	lt.addHead(5);
	lt.addHead(5);
	lt.addHead(5);
	lt.addTail(10);
	lt.addTail(10);
	lt.addIndex(3, 7);
	lt.addIndex(3, 7);
	lt.delnode(3);
	cout << "Size: " << lt.getSize() << endl;
	lt.printList();
};