#pragma once

class BSTTree {
public:
	BSTTree();
	int size;

	struct Node {
		int key;
		Node* left;
		Node* right;
		Node* parent;
	};
	
	Node* root;

	void add(int);
	void deleteNode(int);
	void printAsTree();
	Node* search(Node*, int);
	Node* findSuccessor(Node*);
	Node* minKey(Node*);
	void preorder(Node*);
	void menu();
	int loadNumber();
	void readData(int*,int);

};