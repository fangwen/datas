#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 10

typedef struct {
	int data;
	int parent;
} Node;

typedef struct {
	Node *node;
	int n;
} Tree;

void init(Tree *tree, int n)
{
	tree->node = (Node *) malloc(sizeof(Node) * n);
	tree->n = n;
}

int find(Tree *tree, int i)
{
	if (i<0 || i>tree->n-1)
		return -1;
	int j;
	for (j=i; tree->node[j].parent>=0; j=tree->node[j].parent)
		;
	return j;
}

void merge(Tree *tree, int i, int j)
{
	if(i<0 || i>tree->n-1 || j<0 || j>tree->n-1)
		exit(1);
	tree->node[i].parent=j;
}

/* print all the nodes under node[j], recursively */
void print_root(Tree *tree, int j)
{
	int temp[MAX_TREE_SIZE];
	int k = 0;
	int i;
	for (i = 0; i < tree->n; i++) {
		if(tree->node[i].parent == j)
			temp[k++] = i;
	}
	for (i = 0; i < k; i++) {
		print_root(tree, temp[i]);
		printf("%-2d", tree->node[temp[i]].data);
	}
}

/* print all the equivalence classes */
void print(Tree *tree)
{
	int i;
	for (i = 0; i < tree->n; i++) {
		if(tree->node[i].parent == -1) {
			printf("%-2d", tree->node[i].data);
			print_root(tree, i);
			printf("\n");
		}
	}
}

int main()
{
	Tree tree;
	init(&tree, 8);
	int j = 0;
	int i;
	for (i = 0; i < (&tree)->n; i++) {
		(&tree)->node[i].data = j;
		(&tree)->node[i].parent = -1;
		j++;
	}
	char str[20];
	FILE *fp = fopen("/home/yufw/code/data_structure/ds10/test.txt", "r");
	while (fgets(str, sizeof(str), fp) != NULL) {
		int i = find(&tree, atoi(&str[0]));
		int j = find(&tree, atoi(&str[strlen(str)-2]));
		if (i != j)
			merge(&tree, i, j);
	}
	fclose(fp);
	print(&tree);
	return 0;
}
