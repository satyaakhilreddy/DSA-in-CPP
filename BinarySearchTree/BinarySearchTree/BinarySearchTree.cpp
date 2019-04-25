#include <iostream>

using namespace std;

class BST {
private:
	struct Node {
		int key;
		Node *left = NULL;
		Node *right = NULL;
	};

public:
	Node *root;

	BST(int d) {
		root = new Node;
		root->key = d;
	};

	void inorder(Node *n) {

		if (n == NULL) {
			return;
		};

		inorder(n->left);
		cout << n->key << " ";
		inorder(n->right);

		return;
	};

	void insertUtil(Node *n, Node* i) {
		if (n->key < i->key) {
			if (i->left == NULL) {
				i->left = n;
				return;
			}
			else {
				insertUtil(n, i->left);
			};
		}
		else {
			if (n->key > i->key) {
				if (i->right == NULL) {
					i->right = n;
				}
				else {
					insertUtil(n, i->right);
				};
			};
		};

		return;
	};

	Node* minVal(Node *n) {
		Node *current = n;
		while (!current->left) {
			current = current->left;
		};
		return current;
	};

	void insert(int d) {
		Node *n = new Node;
		n->key = d;

		if (root == NULL) {
			root = n;
			return;
		};

		insertUtil(n, root);
	};

	Node* delnodeUtil(Node* n, int d) {
		if (!n) {
			return n;
		};

		if (n->key > d) {
			n->left=delnodeUtil(n->left, d);
		}
		else {
			if (n->key < d) {
				n->right=delnodeUtil(n->right, d);
			}
			else {
				if (n->right == NULL) {
					Node *tmp = n->left;
					free(n);
					return tmp;
				}else{
					if (n->left == NULL) {
						Node *tmp = n->right;
						free(n);
						return tmp;
					};
				};

				Node* t = minVal(n->right);
				n->key = t->key;
				n->right = delnodeUtil(n->right, t->key);
			};
		};
	};

	void delnode(int d) {
		root=delnodeUtil(root, d);
	};

};

int main() {

	BST bt(1);
	bt.insert(4);
	bt.insert(5);
	bt.insert(2);
	bt.insert(3);
	bt.insert(6);

	bt.inorder(bt.root);
	bt.delnode(3);
	cout << "After deletion: " << endl;
	bt.inorder(bt.root);


	return 0;
};