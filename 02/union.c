#include <stdio.h>
#include "list.h"

main()
{
    int a[5] = { 2, 3, 4, 5, 6 };
    int b[3] = { 3, 7, 2 };
    struct sqlist lista;
    struct sqlist listb;
    init_list(&lista, 80);
    init_list(&listb, 0);
    int i;
    for (i = 0; i < 5; i++)
	list_insert(&listb, 0, a[i]);
    for (i = 0; i < 3; i++)
	list_insert(&lista, 0, b[i]);
    list_display(&lista);
    list_display(&listb);
    for (i = 0; i < (&listb)->length; i++)
	if (locate_element(&lista, (&listb)->p[i]) == -1)
	    list_insert(&lista, 0, (&listb)->p[i]);
    list_display(&lista);
    destroy_list(&listb);
}
