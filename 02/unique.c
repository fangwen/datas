#include <stdio.h>
#include "list.h"

main()
{
    int arr[7] = { 2, 3, 4, 5, 4, 2, 6 };
    struct sqlist lista;
    struct sqlist listb;
    init_list(&lista, 80);
    init_list(&listb, 0);
    int i;
    for (i = 0; i < 7; i++)
	list_insert(&listb, 0, arr[i]);
    list_display(&listb);
    for (i = 0; i < (&listb)->length; i++)
	if (locate_element(&listb, (&listb)->p[i]) == i)
	    list_insert(&lista, 0, (&listb)->p[i]);
    list_display(&lista);
}
