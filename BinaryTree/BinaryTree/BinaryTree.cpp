#include <iostream>
#include <queue>
#include "BinaryTree.h"

BinaryTree::BinaryTree(int d) {
	root = new Node;
	root->key = d;
	root->left = NULL;
	root->right = NULL;
};

void BinaryTree::insert(int d) {
	if (!root) {
		root->key = d;
		root->left = NULL;
		root->right = NULL;
		return;
	};

	Node *newnode = new Node;
	newnode->key = d;

	queue<struct Node*> q;
	q.push(root);
	Node *tmp = new Node;

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		if (tmp->left == NULL) {
			tmp->left = newnode;
			break;
		}
		else {
			q.push(tmp->left);
		};

		if (tmp->right == NULL) {
			tmp->right = newnode;
			break;
		}
		else {
			q.push(tmp->right);
		};
	};
};

void BinaryTree::inorder() {
	inorderTrav(root);
};

void BinaryTree::inorderTrav(Node *n) {
	if (!n) {
		return;
	};
	inorderTrav(n->left);
	cout << n->key << endl;
	inorderTrav(n->right);
};