#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 60766

typedef struct {
	int x, y;
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
void print_root(Tree *tree, int j, FILE *out)
{
	int temp[MAX_TREE_SIZE];
	int k = 0;
	int i;
	for (i = 0; i < tree->n; i++) {
		if(tree->node[i].parent == j)
			temp[k++] = i;
	}
	for (i = 0; i < k; i++) {
		print_root(tree, temp[i], out);
		fprintf(out, "%-4d\t%-4d\n", tree->node[temp[i]].x, tree->node[temp[i]].y);
	}
}

/* print all the equivalence classes */
void print(Tree *tree)
{
	int i;
    int j = 0;
    char *number[] = {"file1", "file2", "file3", "file4", "file5", "file6", "file7", "file8", "file9", "file10", "file11", "file12"};
    for (i = 0; i < tree->n; i++) {
		if(tree->node[i].parent == -1) {
            FILE *out = fopen(number[j++], "w");
			fprintf(out, "%-4d\t%-4d\n", tree->node[i].x, tree->node[i].y);
			print_root(tree, i, out);
			fprintf(out, "\n");
        }
	}
}

int main()
{
	Tree tree;
    FILE *fp = fopen("/home/yufw/code/data_structure/ds10/bp.txt", "r");
	init(&tree, MAX_TREE_SIZE);
    int tempx, tempy;
	int i;
    for (i = 0; i < (&tree)->n; i++) {
        fscanf(fp, "%d %d", &tempx, &tempy);
        (&tree)->node[i].x = tempx;
        (&tree)->node[i].y = tempy;
        (&tree)->node[i].parent = -1;
    }
    for (i = 0; i < (&tree)->n; i++) {
        int j;
        for (j = 0; j < (&tree)->n; j++) {
            if ((-1 <= (&tree)->node[i].x - (&tree)->node[j].x <= 1) &&
                (-1 <= (&tree)->node[i].y - (&tree)->node[j].y <= 1)) {
                int p = find(&tree, i);
                int q = find(&tree, j);
                if(p != q)
                    merge(&tree, j, p);
            }
        }
    }
	fclose(fp);
	print(&tree);
	return 0;
}
