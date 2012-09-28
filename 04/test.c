#include <stdio.h>
#include "list.h"

int main()
{
    printf("hello, world\n");
    node list[MAX_LENGTH];
    node list2[MAX_LENGTH];
    node result[MAX_LENGTH];
    init_list(result);
    init_list(list);
    init_list(list2);
    list_insert(list, 1, 9, 1);
    list_insert(list, 2, 8, 2);
    list_insert(list, 3, 7, 4);
    list_insert(list, 3, 7, 3);
    list_insert(list, 3, 8, 5);
    list_insert(list2, 1, 2, 1);
    list_insert(list2, 2, 8, 2);
    list_insert(list2, 3, 4, 3);
    print_list(list);
    print_list(list2);
    add(list, list2, result);
    print_list(result);
    print2(list);
    arrange(list);
    print2(list);
    return 0;
}
