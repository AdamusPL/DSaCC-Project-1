#include "BSTTree.h"
#include <iostream>
#include <conio.h>
using namespace std;

BSTTree::BSTTree() {
	root = nullptr;
	size = 0;
}

struct Node {
	int key;
	Node* left;
	Node* right;
	Node* parent;
};

void BSTTree::add(int val) { //dodanie elementu do drzewa BST
	Node* insertNode=new Node;
	insertNode->key = val;
	insertNode->left = insertNode->right = NULL;

	Node* y;
	y = nullptr;
	Node* x;
	x = root;

	while (x != nullptr) {
		y = x;
		if (insertNode->key < x->key) {
			x = x->left;
		}
		else x = x->right;
	}

	insertNode->parent = y;

	if (y == nullptr) {
		root = insertNode;
	}

	else {
		if (insertNode->key < y->key) {
			y->left = insertNode;
		}
		else y->right = insertNode;
	}

}

void BSTTree::deleteNode(Node* root, int val) { //usuniecie elementu z drzewa BST
	Node* deleteNode = new Node;
	deleteNode = search(root, val);

	Node* x;
	Node* y;

	if (deleteNode->left == nullptr || deleteNode->right == nullptr) {
		y = deleteNode;
	}

	else {
		y = findSuccessor(deleteNode);
	}

	if (y->left != nullptr) {
		x = y->left;
	}

	else {
		x = y->right;
	}

	if (x != nullptr) {
		x->parent = y->parent;
	}

	if (y->parent == nullptr) {
		root = x;
	}

	else {
		if (y == y->parent->left) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
	}

	if (y != deleteNode) {
		deleteNode->key = y->key;
	}

}

BSTTree::Node* BSTTree::findSuccessor(Node* node) {

	if (node->right != nullptr) {
		return minKey(node->right);
	}

	Node* tmp = node->parent;

	while (tmp != nullptr && tmp->left != node) {
		node = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

BSTTree::Node* BSTTree::minKey(Node* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

BSTTree::Node* BSTTree::search(Node* node, int key) { //zeby wyswietlilo ze znalazlo element
	if (node == nullptr || node->key == key) {
		if(node->key == key) cout << "Znaleziono klucz o podanej wartosci!" << endl;
		return node;
	}

	if (key < node->key) {
		return BSTTree::search(node->left, key);
	}

	return BSTTree::search(node->right, key);
}

void BSTTree::readData(int* data, int size) {
	for (int i = 0; i < size; i++) {
		add(data[i]);
	}
}

void BSTTree::printAsTree() {
	system("cls");
	if (root == nullptr) cout << "Drzewo jest puste!" << endl, _getche();
	else
	{
		cout << root->key << "(";
		if (root->left != nullptr) displayloop(root->left);
		else cout << "*";
		cout << ",";
		if (root->right != nullptr) displayloop(root->right);
		else cout << "*";
		cout << ")";
		_getche();
	}
}

void BSTTree::displayloop(Node* out) {
	system("cls");
	if (root == nullptr) cout << "Drzewo jest puste!" << endl, _getche();
	else
	{
		cout << root->key << "(";
		if (root->left != nullptr) displayloop(root->left);
		else cout << "*";
		cout << ",";
		if (root->right != nullptr) displayloop(root->right);
		else cout << "*";
		cout << ")";
		_getche();
	}
}

void BSTTree::preorder(Node* node) {
	if (node == nullptr) return;
	cout << node->key << " ";
	preorder(node->left);
	preorder(node->right);
}

void BSTTree::menu() {
	int option = 1;
	while (option != 5) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "1. Dodac element do BST" << endl;
		cout << "2. Usunac element z BST" << endl;
		cout << "3. Wyswietl elementy BST" << endl;
		cout << "4. Znajdz element w BST" << endl;
		cout << "5. Inna struktura danych" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		switch (option) {
		case 1:
			number = loadNumber();
			add(number); break;
		case 2:
			number = loadNumber();
			deleteNode(root, number);
			 break;
		case 3:
			preorder(root);
			printAsTree();
			 break;
		case 4:
			number = loadNumber();
			search(root, number);
			 break;
		case 5:
			return;
		}
	}
}

int BSTTree::loadNumber() { //metoda do wpisywania liczb
	int number;
	cout << "Podaj liczbe: ";
	cin >> number;
	cout << endl;
	return number;
}