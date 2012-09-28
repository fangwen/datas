#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(struct sqlist *l, int max_size)
{
    if (max_size == 0)
	max_size = MAX_LIST_SIZE;
    l->p = (int *) malloc(sizeof(int) * max_size);
    if (l->p == NULL)
	exit(EXIT_FAILURE);
    l->length = 0;
    l->list_size = max_size;
}

void destroy_list(struct sqlist *l)
{
    free(l->p);
    l->length = 0;
    l->list_size = 0;
}

int locate_element(struct sqlist *l, int e)
{
    int j;
    for (j = 0; j < l->length; j++) {
	if (l->p[j] == e)
	    return j;
    }
    if (j == l->length)
	return -1;		/* return -1 if not found */
};

int list_insert(struct sqlist *l, int pos, int e)
{				/* pos is the subscript of the inserted element */
    int j;
    if (pos < 0 || pos > (l->length))
	exit(EXIT_FAILURE);
    if (l->length >= l->list_size)
	exit(EXIT_FAILURE);
    for (j = l->length; j >= pos; --j)
	l->p[j + 1] = l->p[j];
    l->p[pos] = e;
    ++(l->length);
    return 0;
}

int list_delete(struct sqlist *l, int pos)
{
    int j;
    if ((pos < 0) || (pos >= l->length))
	exit(EXIT_FAILURE);
    for (j = pos; j < l->length; j++)


	l->p[j] = l->p[j + 1];
    l->length--;
    return 0;
}

int list_display(struct sqlist *l)
{
    int j;
    for (j = 0; j < l->length; j++)
	printf("%3d", l->p[j]);
    printf("\n");
    return 0;
};
