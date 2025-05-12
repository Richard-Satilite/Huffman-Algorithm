#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

Node* genNode(char c, int frequency) {
    Node* node = (Node*) malloc(sizeof(Node));
    
    if (node == NULL) {
        printf("\nErro ao alocar");
        return NULL;
    }
    
    node->c = c;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

int comp(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;
    
    return nodeB->frequency - nodeA->frequency;
}

Node* buildHuffmanTree(char* string, int* frequencies, int n) {
    Node* nodes[n];
    
    for (int i = 0; i < n; i++) {
        nodes[i] = genNode(string[i], frequencies[i]);
    }

    qsort(nodes, n, sizeof(Node*), comp);
    
    while (n > 1) {
        Node* left = nodes[n - 1];
        Node* right = nodes[n - 2];

        Node* newNode = genNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        nodes[n - 2] = newNode;
        n--;
        
        qsort(nodes, n, sizeof(Node*), comp);
    }

    return nodes[0];
}

void printTree(Node* root, char* prefix) {
    if (root == NULL) {
        return;
    }

    if (root->c != '\0') {
        printf("%c: %s\n", root->c, prefix);
    }

    int len = strlen(prefix);
    char leftPrefix[len + 2];
    char rightPrefix[len + 2];

    strcpy(leftPrefix, prefix);
    strcpy(rightPrefix, prefix);

    leftPrefix[len] = '0';
    leftPrefix[len + 1] = '\0';

    rightPrefix[len] = '1';
    rightPrefix[len + 1] = '\0';

    printTree(root->left, leftPrefix);
    printTree(root->right, rightPrefix);
}
