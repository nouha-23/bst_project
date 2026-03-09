#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst_node.h"

// Get the height of the tree
int getHeight(NodePtr root) {
    if (root == NULL) return 0;
    int leftH  = getHeight(root->left);
    int rightH = getHeight(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

// Fill a 2D character buffer with the tree nodes and connectors
// - row, col     : current position in the buffer
// - width        : width of the current subtree's column space
void fillBuffer(NodePtr root, char **buf, int row, int col, int width) {
    if (root == NULL) return;

    // Center the node value in the current column space
    char tmp[16];
    sprintf(tmp, "%d", root->data);
    int len    = strlen(tmp);
    int midCol = col + width / 2;
    int startCol = midCol - len / 2;

    // Write the node value into the buffer
    for (int i = 0; i < len; i++) {
        buf[row][startCol + i] = tmp[i];
    }

    int half = width / 4;

    // Draw left subtree connector and recurse
    if (root->left != NULL) {
        // Draw '/' connector going up-left
        int connRow = row + 1;
        int connCol = midCol - 1;
        while (connCol >= col + half && connRow <= row + 2) {
            buf[connRow][connCol] = '/';
            connRow++;
            connCol--;
        }
        fillBuffer(root->left, buf, row + 3, col, width / 2);
    }

    // Draw right subtree connector and recurse
    if (root->right != NULL) {
        // Draw '\' connector going down-right
        int connRow = row + 1;
        int connCol = midCol + 1;
        while (connCol <= col + width - half && connRow <= row + 2) {
            buf[connRow][connCol] = '\\';
            connRow++;
            connCol++;
        }
        fillBuffer(root->right, buf, row + 3, col + width / 2, width / 2);
    }
}

void display(NodePtr root) {
    printf("\n=== Tree Structure ===\n");

    if (root == NULL) {
        printf("       (Empty Tree)\n");
        printf("======================\n");
        return;
    }

    int height  = getHeight(root);
    int rows    = height * 3;          // 3 buffer rows per tree level
    int cols    = 120;                 // fixed canvas width

    // Allocate 2D character buffer, filled with spaces
    char **buf = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        buf[i] = (char *)malloc((cols + 1) * sizeof(char));
        memset(buf[i], ' ', cols);
        buf[i][cols] = '\0';
    }

    fillBuffer(root, buf, 0, 0, cols);

    // Print buffer, trimming trailing spaces per line
    for (int i = 0; i < rows; i++) {
        int last = 0;
        for (int j = 0; j < cols; j++)
            if (buf[i][j] != ' ') last = j;

        // Only print non-empty lines
        if (last > 0) {
            buf[i][last + 1] = '\0';
            printf("%s\n", buf[i]);
        }
    }

    // Free buffer
    for (int i = 0; i < rows; i++) free(buf[i]);
    free(buf);

    printf("======================\n");
}
