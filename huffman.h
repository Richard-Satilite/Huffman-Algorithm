#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX 1000;

typedef struct Frequency{
	char c;
	int freq;
} Frequency;

typedef struct PriorityQueue{
	Frequency itens[MAX];
	int length;
}Queue;

typedef struct Node{
	Frequency e;
	struct Node *left;
	struct Node *right;
}Node;

#endif

