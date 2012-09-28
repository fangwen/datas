#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

void list_delete(node * h, int pos);

void init_list(node * h)
{
    h = (node *) malloc(sizeof(node));
    if (h == NULL)
	exit(1);
    h->next = h;
    h->prev = h;
}

void destroy_list(node * h)
{
    while (h->next != h) {
	list_delete(h, 1);
    }
    free(h);
}

void list_delete(node * h, int pos)
{
    node *p;
    p = h;
    int i = 0;
    while (i < pos) {
	p = p->next;
	i++;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

//int get_element(list l, int pos)
//{
//    int e;
//    int j = 1;
//    node *p = l->next;
//    while(p != l && j < pos) {
//        j++;
//      p = p->next;
//    }
//    if(p == l && j > pos)
//      printf("hello, world\n");
//    e = p->data;
//    return e;
//}
//
//void list_insert(list *l, node *p, int i)
//{
//    node *s = (node *)malloc(sizeof(node));
//    s->data = i;
//    s->next = p->next;
//    p->next = s;
//    s->next->prev = s;
//    s->prev = p;
//}
//void print_list(list *l)
//{
//    node *s = (node *)malloc(sizeof(node));
//    s = (*l)->next;
//    while(s != *l) {
//        printf("%3d", s->data); 
//        s = s->next;
//    }
//    printf("\n");
//}
//
//void delete_element(list *l, int pos)
//{
//    node *p = *l;
//    int i = 0;
//    while(i < pos) {
//        p = p->next;
//        i++;
//    }
//    p->prev->next=p->next;
//    p->next->prev=p->prev;
//    free(p);
//}


int main()
{
    printf("hello, world\n");
    node h;
    init_list(&h);
    //list_insert(&l, l, 8);
    //list_insert(&l, l, 7);
    //print_list(&l);
    //i = get_element(l, 1);
    //printf("%3d\n", i);
    //delete_element(&l, 1);
    //   print_list(&l);
    destroy_list(&h);
    return 0;
}
