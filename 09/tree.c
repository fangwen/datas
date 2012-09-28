/* build a binary tree according to a given string */
#include <stdio.h>
#include <stdlib.h>

struct tnode {
	int data;
	struct tnode *left, *right;
};

void create_tree(struct tnode **node, char **ch)
{
    char temp = **ch;
    (*ch)++;
    if (temp == 'X')
        *node = NULL;
    else {
        *node = (struct tnode *) malloc(sizeof(struct tnode));
        (*node)->data = temp;
        create_tree(&((*node)->left), ch);
        create_tree(&((*node)->right), ch);
    }
}

void print_tree(struct tnode *node)
{
	if (node) {
		printf ("%-2c", node->data);
		print_tree(node->left);
		print_tree(node->right);
	}
}

int main()
{
	FILE *in = fopen("test", "r");
	char *ch = (char *) malloc(1024 * sizeof(char));
	fscanf(in, "%[^#]", ch);
	printf( "%s\n", ch);
	struct tnode *node;
	create_tree(&node, &ch);
	print_tree(node);
	printf("\n");
    return 0;
}
