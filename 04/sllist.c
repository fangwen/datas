#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct node {
    int data;
    int next;
} node;

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

void list_insert(node list[], int i, int data)
{
    if (i > list_length(list) + 1)
	exit(1);
    int j = list_length(list) + 1;
    list[j].data = data;
    list[j].next = list[i - 1].next;
    list[i - 1].next = j;
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
	printf("%3d", list[i].data);
	i = list[i].next;
    }
    printf("\n");
}

int main()
{
    printf("hello, world\n");
    node list[MAX_LENGTH];
    init_list(list);
    list_insert(list, 1, 9);
    list_insert(list, 2, 8);
    list_insert(list, 3, 7);
    print_list(list);
    list_delete(list, 2);
    list_delete(list, 1);
    print_list(list);
    int i = list_length(list);
    printf("%3d\n", i);
    return 0;
}
