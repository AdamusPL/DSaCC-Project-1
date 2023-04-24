#pragma once
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key)
    {
        this->key = key;
        left = right = nullptr;
    }
};