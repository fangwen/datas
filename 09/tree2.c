/* build a binary tree according to
   preorder traversal and inorder traversal */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	int data;
	struct tnode *left, *right;
};

int find(char *ch, char c)
{
	char *k = strchr(ch, c);
	if (k == NULL)
		return -1;
	else
		return k - ch;
}

void create_tree(struct tnode **node, char pre[], char ino[], int ps, int is, int n)
{
	if (n == 0)
		*node = NULL;
	else {
		int k = find(ino, pre[ps]);
		if (k == -1)
			*node = NULL;
		else {
			*node = (struct tnode *) malloc(sizeof(struct tnode));
			(*node)->data = pre[ps];
			if(k == is)
				(*node)->left = NULL;
			else
				create_tree(&(*node)->left, pre, ino, ps+1, is, k-is);
			if(k == is+n-1)
				(*node)->right = NULL;
			else
				create_tree(&(*node)->right, pre, ino, ps+1+(k-is), k+1, n-(k-is)-1);
		}
	}
}

/* print tree in post order */
void print_tree(struct tnode *node)
{
	if (node) {
		print_tree(node->left);
		print_tree(node->right);
		printf ("%-2c", node->data);
	}
}

int main()
{
	char *pre = "abcdefg";
	char *ino = "cbdaegf";
	struct tnode *node;
	create_tree(&node, pre, ino, 0, 0, 7);
	print_tree(node);
	printf("\n");
	return 0;
}
