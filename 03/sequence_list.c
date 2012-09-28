#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 10
#define INCREASEMENT 10

struct sqlist {
    int *p;
    int length;
    int list_size;
};

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
    if (l->p != NULL)
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
}

int list_insert(struct sqlist *l, int pos, int e)
{				/* pos is the subscript of the inserted element */
    int j;
    if (pos < 0)
	exit(EXIT_FAILURE);
    if (l->length == l->list_size) {
	int *q = (int *) realloc(l->p,
				 (l->list_size +
				  INCREASEMENT) * sizeof(int));
	if (q == NULL)
	    exit(EXIT_FAILURE);
	l->p = q;
	l->list_size = l->list_size + INCREASEMENT;
    }
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

int print_list(struct sqlist *l)
{
    int j;
    for (j = 0; j < l->length; j++)
	printf("%3d", l->p[j]);
    printf("\n");
    return 0;
}

main()
{
    struct sqlist list;
    printf("Initialize sequence list.\n");
    init_list(&list, 10);
    printf("Insert ten elements and then print the list.\n");
    int i;
    for (i = 0; i < 10; i++)
	list_insert(&list, i, i);
    print_list(&list);
    printf("Insert ten more elements.\n");
    for (i = 10; i < 20; i++)
	list_insert(&list, i, i);
    print_list(&list);
    printf("Locate element '3'.\n");
    printf("%3d\n", locate_element(&list, 3));
    printf("Delete trailing 5 elements.\n");
    for (i = 19; i > 14; i--)
	list_delete(&list, i);
    print_list(&list);
    printf("Finally we destroy the entire list.\n");
    destroy_list(&list);
    return 0;
}
