#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void init_list(node list[])
{
    list[0].next = MAX_LENGTH - 1;
    list[MAX_LENGTH - 1].next = 0;
}

int list_length(node list[])
{
    int i = 0, j = 0;
    i = list[i].next;
    while (i != MAX_LENGTH - 1) {
	i = list[i].next;
	j++;
    }
    return j;
}

void list_insert(node list[], int i, float coef, int expn)
{
    if (i > list_length(list) + 1)
	exit(1);
    int m = 0, k = 0;
    for (k = 0; k < i - 1; k++)
	m = list[m].next;
    int j = list_length(list) + 1;
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
    while (j != MAX_LENGTH - 1 && k < i) {
	j = list[j].next;
	k++;
    }
    list[k - 1].next = list[k + 1].next;
}

void print_list(node list[])
{
    int i = 0;
    i = list[i].next;
    while (i != MAX_LENGTH - 1) {
	printf("%1.fx^%d ", list[i].coef, list[i].expn);
	i = list[i].next;
    }
    printf("\n");
}

void add(node list[], node list2[], node result[])
{
    int i = 0, j = 0, k = 1;
    i = list[i].next;
    j = list2[j].next;
    while (i != MAX_LENGTH - 1 && j != MAX_LENGTH - 1) {
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
    while (i != MAX_LENGTH - 1) {
	list_insert(result, k, list[i].coef, list[i].expn);
	i = list[i].next;
	k++;
    }
    while (j != MAX_LENGTH - 1) {
	list_insert(result, k, list[j].coef, list[j].expn);
	j = list[j].next;
	k++;
    }
}

void print2(node list[])
{
    int i = 1;
    for (i = 1; i <= 5; i++)
	printf("%1.fx^%d ", list[i].coef, list[i].expn);
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
	    int j;
	    node temp;
	    temp.expn = list[i].expn;
	    temp.coef = list[i].coef;
	    j = list[i].next;
	    list[i].expn = list[p].expn;
	    list[i].coef = list[p].coef;
	    list[i].next = p;
	    list[p].expn = temp.expn;
	    list[p].coef = temp.coef;
	    list[p].next = j;
	}
	p = q;
    }
}
