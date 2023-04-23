#include <cmath>
#include <iostream>
#include <queue>
#include "PrintBST.h"
using namespace std;

void PrintBST::printSpace(double n, BSTTree::Node* removed)
{
    for (; n > 0; n--) {
        cout << "\t";
    }
    if (removed == nullptr) {
        cout << " ";
    }
    else {
        cout << removed->key;
    }
}

int PrintBST::heightOfTree(BSTTree::Node* root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1
        + max(heightOfTree(root->left),
            heightOfTree(root->right));
}

void PrintBST::printBinaryTree(BSTTree::Node* root)
{
    queue<BSTTree::Node*> treeLevel, temp;
    treeLevel.push(root);
    int counter = 0;
    int height = heightOfTree(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;
    while (counter <= height) {
        BSTTree::Node* removed = treeLevel.front();
        treeLevel.pop();
        if (temp.empty()) {
            printSpace(numberOfElements
                / pow(2, counter + 1),
                removed);
        }
        else {
            printSpace(numberOfElements / pow(2, counter),
                removed);
        }
        if (removed == nullptr) {
            temp.push(nullptr);
            temp.push(nullptr);
        }
        else {
            temp.push(removed->left);
            temp.push(removed->right);
        }
        if (treeLevel.empty()) {
            cout << endl << endl;
            treeLevel = temp;
            while (!temp.empty()) {
                temp.pop();
            }
            counter++;
        }
    }
}

void PrintBST::print(BSTTree::Node* root)
{
    printBinaryTree(root);
}