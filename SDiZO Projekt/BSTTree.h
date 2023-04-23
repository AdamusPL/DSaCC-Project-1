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
	void deleteNodeM(int);
	void deleteNode(int);
	Node* search(Node*, int);
	Node* findSuccessor(Node*);
	Node* minKey(Node*);
	void printAsTree();
	void displayloop(Node*);
	void preorder(Node*);
	void menu();
	int loadNumber();
	void readData(int*,int);

};