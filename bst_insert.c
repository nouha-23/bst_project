#include "bst_node.h"

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
