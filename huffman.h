#ifndef HUFFMAN_H
#define HUFFMAN_H


// -- Estrutura da arvore --- //
typedef struct Node{
	char c;
	int frequency;
	struct Node *left;
	struct Node *right;
}Node;


// --- Funcao para gerar um no da arvore --- //
Node *genNode(char c, int frequency);


// --- Funcao auxilixar para comparar dois valor --- //
int comp(const void *a, const void *b);


// --- Funcao para gerar arvore de Huffman --- //
Node *buildHuffmanTree(char *string, int *frequencies, int n);


// --- Funcao para exibir arvore de Huffman --- //
void printTree(Node *root, char *preffix);

#endif

