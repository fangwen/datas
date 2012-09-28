#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void init_list(struct node **list)
{
    *list = (struct node *) malloc(sizeof(struct node));
    if ((*list) == NULL)
	exit(1);
    (*list)->next = *list;
    (*list)->prev = *list;
}

void destroy_list(struct node **list)
{
    struct node *p;
    struct node *q;
    p = (*list)->next;
    while (p != *list) {
	q = p->next;
	free(p);
	p = q;
    }
    free(*list);
    (*list) = NULL;
}

int get_element(struct node **list, int pos)
{
    int j = 1;
    struct node *p = (*list)->next;
    while (p != *list && j < pos) {
	j++;
	p = p->next;
    }
    if (p == *list || j > pos)
	exit(1);
    return p->data;
}

void list_insert(struct node **list, struct node *p, int i)
{
    struct node *s = (struct node *) malloc(sizeof(struct node));
    s->data = i;
    s->next = p->next;
    p->next = s;
    s->next->prev = s;
    s->prev = p;
}

void list_delete(struct node **list, int pos)
{
    struct node *p = *list;
    int i = 0;
    while (i < pos) {
	p = p->next;
	i++;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

void print_list(struct node **list)
{
    struct node *s = (struct node *) malloc(sizeof(struct node));
    s = (*list)->next;
    while (s != *list) {
	printf("%3d", s->data);
	s = s->next;
    }
    printf("\n");
}

int main()
{
    printf("hello, world\n");
    struct node *list;
    init_list(&list);
    list_insert(&list, list, 3);
    list_insert(&list, list, 4);
    list_insert(&list, list, 5);
    print_list(&list);
    list_delete(&list, 1);
    print_list(&list);
    printf("%3d\n", get_element(&list, 1));
    destroy_list(&list);
    return 0;
}
