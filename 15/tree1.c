#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree_node {
	char *word;
	struct tree_node *lchild;
	struct tree_node *rchild;
};

struct tree_node *tree_insert(struct tree_node *p, char *word)
{
	if (p == NULL) {
		p = (struct tree_node *)malloc(sizeof(struct tree_node));
		p->word = word;
		p->lchild = NULL;
		p->rchild = NULL;
	} else if (strcmp(p->word, word) < 0) {
		p->rchild = tree_insert(p->rchild, word);
	} else if (strcmp(p->word, word) > 0) {
		p->lchild = tree_insert(p->lchild, word);
	}

	return p;
}

int bin_tree_search(struct tree_node *p, char *word)
{
	if (p == NULL)
		return -1;
	else if (strcmp(p->word, word) < 0)
		bin_tree_search(p->rchild, word);
	else if (strcmp(p->word, word) > 0)
		bin_tree_search(p->lchild, word);
	else
		return 0;
}

int main()
{
	int i;
	char **words = (char **)malloc(sizeof(char *) * 100000);

	if (words == NULL) {
		printf("error!\n");
		exit(1);
	}

	for (i = 0; i < 100000; i++) {
		words[i] = (char *)malloc(sizeof(char) * 20);
		if (words[i] == NULL) {
			printf("error!\n");
			exit(1);
		}
	}

	for (i = 0; i < 79339; i++)
		scanf("%s", words[i]);

	struct tree_node *root;
	root = NULL;

	for (i = 0; i < 79339; i++)
		tree_insert(root, words[i]);

	if (root == NULL)
		printf ("root is NULL\n");

	/* for (i = 0; i < 79339; i++) */
	/* 	printf("%d\n", bin_tree_search(root, words[i])); */

	return 0;
}
