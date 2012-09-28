#include <stdio.h>
#include "list.h"

main()
{
    int a[3] = { 2, 4, 5 };
    int b[3] = { 2, 4, 5 };
    struct sqlist lista, listb;
    init_list(&lista, 10);
    init_list(&listb, 10);
    int i;
    for (i = 0; i < 3; i++)
	list_insert(&lista, 0, a[i]);
    for (i = 0; i < 3; i++)
	list_insert(&listb, 0, b[i]);
    list_display(&lista);
    list_display(&listb);
    if ((&lista)->length != (&listb)->length)
	printf("Not equal\n");
    else {
	for (i = 0; i < 3; i++) {
	    if (locate_element(&listb, (&lista)->p[i]) != i) {
		printf("Not equal\n");
		break;
	    } else if (i == 2)
		printf("Equal\n");
	}
    }
    destroy_list(&lista);
    destroy_list(&listb);

}
