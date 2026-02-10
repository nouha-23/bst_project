#ifndef BST_NODE_H
#define BST_NODE_H

#include <stdlib.h>
#include <stdio.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* NodePtr;

NodePtr createNode(int data);
NodePtr insert(NodePtr root, int data);
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);
void display(NodePtr root);


#endif // BST_NODE_H
