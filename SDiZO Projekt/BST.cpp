#include "BST.h"
#include "PrintBST.h"
#include <iostream>
#include <conio.h>
using namespace std;

BST::BST() {
	root = nullptr;
	size = 0;
}

struct Node {
	int key;
	Node* left;
	Node* right;
	Node* parent;
};

void BST::insert(int val) {
	Node* p = new Node;
	p->key = val;
	p->left = NULL; //firstly, we set left, right child and parent on NULL
	p->right = NULL;
	p->parent = NULL;

	if (root == nullptr) { //if tree is empty
		root = p;
		return;
	}

	Node* temp = root; //node for iteration, we start from root
	Node* parentP = new Node; //root to remember new node's parent

	while (temp != NULL) { //while we don't reach leaf node
		parentP = temp; //new node's parent might be actual checking node

		if (p->key < temp->key) { //check if new node's key is other than iterate node's key
			temp = temp->left; //if yes, go down on the left
		}

		else temp = temp->right; //otherwise, on the right

	}

	p->parent = parentP; //set pointer on new node's parent

	if (p->key < parentP->key) { //set parent as new node's child
		parentP->left = p;
	}

	else parentP->right = p;
}

void BST::deleteNode(int val) { //remove element from BST tree
	Node* deleteNode = new Node;
	deleteNode = search(root, val);
	
	if (deleteNode == nullptr) { //if that node doesn't exist in the tree
		cout << "That node doesn't exist in tree!" << endl;
		return;
	}

	Node* temp;
	Node* y;

	if (deleteNode->left == nullptr || deleteNode->right == nullptr) { //1. case - node doesn't have children
		y = deleteNode;
	}

	else { //3. case - node has 2 children, we search for the successor
		y = findSuccessor(deleteNode);
	}

	if (y->left != nullptr) { //2. case - node has only left child
		temp = y->left;
	}

	else {
		temp = y->right;
	}

	if (temp != nullptr) { //tbc 2. case - set parent's pointer of new node
		temp->parent = y->parent;
	}

	if (y->parent == nullptr) {
		root = temp;
	}

	else {
		if (y == y->parent->left) {
			y->parent->left = temp;
		}
		else {
			y->parent->right = temp;
		}
	}

	if (y != deleteNode) {
		deleteNode->key = y->key;
	}

}

BST::Node* BST::findSuccessor(Node* node) {

	if (node->right != nullptr) { //1. case - node does have right child
		return minKey(node->right); //find node that have the lowest value of key in the right subtree
	}

	Node* tmp = node->parent;

	while (tmp != nullptr && tmp->left != node) {
		node = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

BST::Node* BST::minKey(Node* node) { //find key that have minimum value in the tree
	while (node->left != nullptr) { //while left child exists
		node = node->left;
	}
	return node;
}

BST::Node* BST::search(Node* node, int key) { //find key that have value = key in the tree
	if (node == nullptr || node->key == key) {
		return node;
	}

	if (key < node->key) {
		return BST::search(node->left, key);
	}

	return BST::search(node->right, key);
}

void BST::readData(int* data, int size) { //read data to BST
	for (int i = 0; i < size; i++) {
		insert(data[i]);
	}
}


void BST::preorder(Node* node) { //print heap's element with PREORDER method
	if (node == nullptr) return;
	cout << node->key << " ";
	preorder(node->left);
	preorder(node->right);
}

void BST::menu() {
	int option = 1;
	while (option != 6) {
		cout << "What would you want to do?:" << endl;
		cout << "====================================" << endl;
		cout << "1. Add element to BST" << endl;
		cout << "2. Remove element from BST" << endl;
		cout << "3. Print BST elements (PREORDER method)" << endl;
		cout << "4. Print tree" << endl;
		cout << "5. Find value in BST" << endl;
		cout << "6. Choose other data structure" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		Node* p;
		PrintBST pBST;

		switch (option) {
		case 1:
			number = loadNumber();
			insert(number); break;
		case 2:
			number = loadNumber();
			deleteNode(number);
			 break;
		case 3:
			preorder(root);
			cout << endl;
			 break;
		case 4:
			pBST.print(root);
			break;
		case 5:
			number = loadNumber();
			p=search(root, number);
			if (p == nullptr) cout << "Didn't find key that has specific value" << endl;
			else cout << "Found key: " << number << " in BST" << endl;
			break;
		case 6:
			return;
		}
	}
}

int BST::loadNumber() { //method to read numbers
	int number;
	cout << "Give the number: ";
	cin >> number;
	cout << endl;
	return number;
}