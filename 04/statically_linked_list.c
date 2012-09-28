#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct node {
    float coef;
    int expn;
    int next;
} node;

void init_list(node list[])
{
    list[0].next = 0;
}

int list_length(node list[])
{
    int i = 0;
    int j = 0;
    i = list[i].next;
    while (i != 0) {
	i = list[i].next;
	j++;
    }
    return j;
}

void list_insert(node list[], int i, float coef, int expn)
{
    if (i > list_length(list) + 1)
	exit(1);
    int m = 0;
    int k = 0;
    int j = list_length(list) + 1;
    for (k = 0; k < i - 1; k++)
	m = list[m].next;
    list[j].coef = coef;
    list[j].expn = expn;
    list[j].next = list[m].next;
    list[m].next = j;
}

void list_delete(node list[], int i)
{
    int j = 0;
    j = list[j].next;
    int k = 1;
    while (j != 0 && k < i) {
	j = list[j].next;
	k++;
    }
    list[k - 1].next = list[k + 1].next;
}

void print_list(node list[])
{
    int i = 0;
    i = list[i].next;
    while (list[i].next != 0) {
	printf("%.1fx^%d+", list[i].coef, list[i].expn);
	i = list[i].next;
    }
    printf("%.1fx^%d", list[i].coef, list[i].expn);
    printf("\n");
}

void add(node list[], node list2[], node result[])
{
    int i = 0, j = 0, k = 1;
    i = list[i].next;
    j = list2[j].next;
    while (i != 0 && j != 0) {
	if (list[i].expn < list2[j].expn) {
	    list_insert(result, k, list[i].coef, list[i].expn);
	    i = list[i].next;
	    k++;
	} else if (list[i].expn > list2[j].expn) {
	    list_insert(result, k, list2[j].coef, list2[j].expn);
	    j = list2[j].next;
	    k++;
	} else {
	    list_insert(result, k, list[i].coef + list2[j].coef,
			list[i].expn);
	    i = list[i].next;
	    j = list2[j].next;
	    k++;
	}
    }
    while (i != 0) {
	list_insert(result, k, list[i].coef, list[i].expn);
	i = list[i].next;
	k++;
    }
    while (j != 0) {
	list_insert(result, k, list[j].coef, list[j].expn);
	j = list[j].next;
	k++;
    }
}

void print2(node list[])
{
    int i = 1;
    for (i = 1; i < 5; i++)
	printf("%.1fx^%d+", list[i].coef, list[i].expn);
    printf("%.1fx^%d", list[i].coef, list[i].expn);
    printf("\n");
}

void arrange(node list[])
{
    int p = list[0].next;
    int i;
    int j = list_length(list);
    for (i = 1; i <= j; i++) {
	while (p < i)
	    p = list[p].next;
	int q = list[p].next;
	if (p != i) {
	    node temp;
	    temp.expn = list[i].expn;
	    temp.coef = list[i].coef;
	    temp.next = list[i].next;
	    list[i].expn = list[p].expn;
	    list[i].coef = list[p].coef;
	    list[i].next = p;
	    list[p].expn = temp.expn;
	    list[p].coef = temp.coef;
	    list[p].next = temp.next;
	}
	p = q;
    }
}

int main()
{
    printf("hello, world\n");
    node list[MAX_LENGTH];
    node list2[MAX_LENGTH];
    node result[MAX_LENGTH];
    init_list(list);
    init_list(list2);
    init_list(result);
    int i;
    float coef;
    int expn;
    for (i = 1; i < 6; i++) {
	scanf("%f%d", &coef, &expn);
	list_insert(list, i, coef, expn);
    }
    list_insert(list2, 1, 2, 1);
    list_insert(list2, 2, 8, 2);
    list_insert(list2, 3, 4, 5);
    list_insert(list2, 3, 5, 4);
    list_insert(list2, 3, 7, 3);
    print_list(list);
    print_list(list2);
    add(list, list2, result);
    print_list(result);
    print2(list2);
    arrange(list2);
    print2(list2);
    return 0;
}
