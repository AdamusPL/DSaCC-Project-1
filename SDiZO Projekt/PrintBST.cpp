#include <cmath>
#include <iostream>
#include <queue>
#include "PrintBST.h"
using namespace std;

void PrintBST::printSpace(double n, BST::Node* deleteNode) //print space
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

int PrintBST::height(BST::Node* root) //maximum tree depth method
{
    if (root == nullptr) { //if tree is empty
        return 0;
    }
    return 1 + max(height(root->left), height(root->right)); //otherwise - count tree depth
}

void PrintBST::printBST(BST::Node* root)
{
    queue<BST::Node*> treeLevel, temp; //queue
    treeLevel.push(root); //put root in queue
    int i = 0; //counter
    int h = height(root) - 1;
    double numberOfElements = pow(2, (h + 1)) - 1; //no. of elements at the specific level of tree: 2^(h+1)-1
    while (i <= h) {
        BST::Node* deleteNode = treeLevel.front(); //next element in queue
        treeLevel.pop(); //remove it
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

void PrintBST::print(BST::Node* root) //print tree
{
    printBST(root);
}