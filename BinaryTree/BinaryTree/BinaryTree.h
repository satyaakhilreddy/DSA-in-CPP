#include <iostream>

using namespace std;

class BinaryTree {
private:
	struct Node {
		int key;
		struct Node *left=NULL, *right=NULL;
	};
	Node *root;
public:
	BinaryTree(int d);
	void insert(int d);
	void inorder();
	void inorderTrav(Node *n);
};