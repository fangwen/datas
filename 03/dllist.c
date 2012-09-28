#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node, *list;

void init_list(list * l)
{
    *l = (node *) malloc(sizeof(node));
    if ((*l) == NULL)
	exit(1);
    (*l)->next = *l;
    (*l)->prev = *l;
}

void destroy_list(list * l)
{
    node *p, *q;
    p = (*l)->next;
    while (p != (*l)) {
	q = p->next;
	free(p);
	p = q;
    }
    free(*l);
    (*l) = NULL;
}

int get_element(list l, int pos)
{				/* pos is the number beyond head, counting from 1 */
    int j = 1;
    node *p = l->next;
    while (p != l && j < pos) {
	j++;
	p = p->next;
    }
    if (p == l || j > pos)
	exit(1);
    return p->data;
}

void list_insert(list * l, node * p, int i)
{				/* insert node s after p */
    node *s = (node *) malloc(sizeof(node));
    s->data = i;
    s->next = p->next;
    p->next = s;
    s->next->prev = s;
    s->prev = p;
}

void print_list(list * l)
{
    node *s = (node *) malloc(sizeof(node));
    s = (*l)->next;
    while (s != *l) {
	printf("%3d", s->data);
	s = s->next;
    }
    printf("\n");
}

void list_delete(list * l, int pos)
{
    node *p = *l;
    int i = 0;
    while (i < pos) {
	p = p->next;
	i++;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}


main()
{
    list l;
    printf("Initialize doubly linked list.\n");
    init_list(&l);
    printf("Insert two element, 7 and 8, then print the list.\n");
    list_insert(&l, l, 8);
    list_insert(&l, l, 7);
    print_list(&l);
    printf("We get the element in position 1 and print it out.\n");
    printf("%3d\n", get_element(l, 1));
    printf("We delete the first element and the list becomes:\n");
    list_delete(&l, 1);
    print_list(&l);
    printf("Finally we detroy the entire list.\n");
    destroy_list(&l);
    return 0;
}
