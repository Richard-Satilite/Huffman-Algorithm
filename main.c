#include <stdio.h>
#include "huffman.h"

int main() {

	char string[] = "abcdef";
	int frequencies[] = {45, 13, 12, 16, 9, 5};
	int n = (int) sizeof(frequencies) / sizeof(frequencies[0]);
	
	Node* root = buildHuffmanTree(string, frequencies, n);
	printTree(root, "");

	return 0;
}
