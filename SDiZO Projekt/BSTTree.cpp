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

void BSTTree::add(int val) {
	Node* p = new Node;
	p->key = val;
	p->left = NULL; //najpierw ustawiamy lewego,prawego syna i rodzica na NULL
	p->right = NULL;
	p->parent = NULL;

	if (root == nullptr) { //jesli drzewo nie ma korzenia (jest puste)
		root = p;
		return;
	}

	Node* temp = root; //wezel do iteracji, zaczynamy od korzenia
	Node* parentP=new Node; //wezel do zapamietania rodzica nowo wstawianego wezla

	while (temp != NULL) { //dopoki nie dojdziemy do liscia NULL
		parentP = temp; //rodzicem nowego wezla moze byc aktualnie sprawdzany wezel

		if (p->key < temp->key) { //sprawdzamy czy klucz wstawianego wezla jest rozny od wezla iteracyjnego
			temp = temp->left; //jesli tak, idziemy w lewo
		}

		else temp = temp->right; //w przeciwnym razie w prawo

	}

	p->parent = parentP; //ustawienie wskaznika na rodzica nowego wezla

	if (p->key < parentP->key) { //ustawienie u rodzica jako syna nowo wstawianego wezla
		parentP->left = p;
	}

	else parentP->right = p;


}

void BSTTree::deleteNodeM(int val) {

}

void BSTTree::deleteNode(int val) { //usuniecie elementu z drzewa BST
	Node* deleteNode = new Node;
	deleteNode = search(root, val);

	Node* x;
	Node* y;

	if (deleteNode->left == nullptr || deleteNode->right == nullptr) { //przypadek 1., gdy wezel nie ma synow
		y = deleteNode;
	}

	else { //przypadek 3., gdy wezel ma 2 synow, znajdujemy nastepnika
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
	while (option != 6) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "1. Dodac element do BST" << endl;
		cout << "2. Usunac element z BST" << endl;
		cout << "3. Wyswietl elementy BST (preorder)" << endl;
		cout << "4. Wyswietl elementy BST jako drzewo" << endl;
		cout << "5. Znajdz element w BST" << endl;
		cout << "6. Inna struktura danych" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		Node* p;

		switch (option) {
		case 1:
			number = loadNumber();
			add(number); break;
		case 2:
			number = loadNumber();
			deleteNode(number);
			 break;
		case 3:
			preorder(root);
			 break;
		case 4:
			printAsTree(); break;
		case 5:
			number = loadNumber();
			p=search(root, number);
			if (p == nullptr) cout << "Nie znaleziono klucza o podanej wartosci" << endl;
			else cout << "Znaleziono klucz: " << number << " w BST" << endl;
			break;
		case 6:
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