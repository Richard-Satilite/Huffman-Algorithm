#include <stdio.h>
#include "huffman.h"

int main() {

	char string[] = "abcdef";
	char string2[] = "AAAAAABBBBBCCCCDDDEEF";
	char string2unique[] = "ABCDEF";
	int frequencies[] = {45, 13, 12, 16, 9, 5};
	int frequencies2[] = {6,5,4,3,2,1};

	int n = (int) sizeof(frequencies) / sizeof(frequencies[0]);
	int n2 = (int) sizeof(frequencies2) / sizeof(frequencies2[0]);
	
	printf("Para o caso:\nCaractere\tFrequencia\na\t\t45\nb\t\t13\nc\t\t12\nd\t\t16\ne\t\t9\nf\t\t5\n\n");

	Node* root = buildHuffmanTree(string, frequencies, n);
	printTree(root, "");

	printf("\n\n\nPara a sequencia: %s\n\n", string2);
	Node *root2 = buildHuffmanTree(string2unique, frequencies2, n2);
	printTree(root2, "");

	return 0;
}
