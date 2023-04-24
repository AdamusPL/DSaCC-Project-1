#include <cmath>
#include <iostream>
#include <queue>
#include "PrintBST.h"
using namespace std;

void PrintBST::printSpace(double n, BSTTree::Node* deleteNode) //wypisz odstêp
{
    for (; n > 0; n--) {
        cout << "\t";
    }

    if (deleteNode == nullptr) {
        cout << " ";
    }
    else {
        cout << deleteNode->key;
    }
}

int PrintBST::height(BSTTree::Node* root) //funkcja do liczenia wysokosci drzewa
{
    if (root == nullptr) { //jesli drzewo jest puste
        return 0;
    }
    return 1 + max(height(root->left), height(root->right)); //w przeciwnym razie policz wysokosc drzewa (maksimum wysokosc poddrzewa)
}

void PrintBST::printBST(BSTTree::Node* root)
{
    queue<BSTTree::Node*> treeLevel, temp; //kolejka
    treeLevel.push(root); //odlozenie korzenia na stos
    int i = 0; //licznik
    int h = height(root) - 1;
    double numberOfElements = pow(2, (h + 1)) - 1; //ilosc elementow na danym poziomie drzewa 2^(h+1)-1
    while (i <= h) {
        BSTTree::Node* deleteNode = treeLevel.front(); //kolejny element w kolejce
        treeLevel.pop(); //zdjecie ze stosu
        if (temp.empty()) {
            printSpace(numberOfElements / pow(2, i + 1), deleteNode);
        }
        else {
            printSpace(numberOfElements / pow(2, i), deleteNode);
        }
        if (deleteNode == nullptr) {
            temp.push(nullptr);
            temp.push(nullptr);
        }
        else {
            temp.push(deleteNode->left);
            temp.push(deleteNode->right);
        }
        if (treeLevel.empty()) {
            cout << endl << endl;
            treeLevel = temp;
            while (!temp.empty()) {
                temp.pop();
            }
            i++;
        }
    }
}

void PrintBST::print(BSTTree::Node* root) //wypisz drzewo
{
    printBST(root);
}