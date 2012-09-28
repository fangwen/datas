#include <stdio.h>
#include "list.h"

main()
{
    int arr[7] = { 2, 3, 4, 5, 4, 2, 6 };
    struct sqlist list;
    init_list(&list, 80);
    int i;
    for (i = 0; i < 7; i++)
	list_insert(&list, 0, arr[i]);
    list_display(&list);
    for (i = 6; i > 0; i--)
	if ((locate_element(&list, (&list)->p[i]) < i))
	    list_delete(&list, i);
    list_display(&list);
    destroy_list(&list);
}
