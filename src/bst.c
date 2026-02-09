#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

// createNode implementation
NodePtr createNode(int data) {
    // Dynamic Memory Allocation using malloc
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert implementation
NodePtr insert(NodePtr root, int data) {
    // If tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // if data matches root->data, we don't insert duplicate

    // return the (unchanged) node pointer
    return root;
}

// Helper function for verification (not part of the core API, but needed for testing)
void simple_inorder(NodePtr root) {
    if (root != NULL) {
        simple_inorder(root->left);
        printf("%d ", root->data);
        simple_inorder(root->right);
    }
}
bool search(NodePtr root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;

    if (key > root->data)
        return search(root->right, key);

    return search(root->left, key);
}

NodePtr getSuccessor(NodePtr curr) {
    curr = curr->right;
    while (curr && curr->left)
        curr = curr->left;
    return curr;
}

NodePtr delNode(NodePtr root, int x) {
    if (root == NULL) return root;

    if (x < root->data)
        root->left = delNode(root->left, x);
    else if (x > root->data)
        root->right = delNode(root->right, x);
    else {
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }

        NodePtr succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
    }
    return root;
}


int main() {
    printf("--- Testing BST Insert Operations ---\n");

    NodePtr root = NULL;

    // Test 1: Insert into empty tree
    printf("Inserting 50...\n");
    root = insert(root, 50);

    // Test 2: Insert smaller value (left)
    printf("Inserting 30...\n");
    root = insert(root, 30);

    // Test 3: Insert larger value (right)
    printf("Inserting 70...\n");
    root = insert(root, 70);

    // Test 4: Insert more values
    printf("Inserting 20, 40, 60, 80...\n");
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 16);

    printf("%d (%d)\n", 16, search(&root, 16));
    printf("%d (%d)\n", 15, search(&root, 15));
    printf("%d (%d)\n", 5,  search(&root, 5));
    printf("%d (%d)\n", 20, search(&root, 20));
    printf("%d (%d)\n", 16,delNode(&root, 80));
    
    return 0;
}

    printf("Tree structure (In-order verificaton): ");
    simple_inorder(root);
    printf("\n");
    

    printf("Test Complete.\n");
    return 0;
}
