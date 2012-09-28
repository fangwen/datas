#include <stdio.h>
#include "list.h"

main()
{
    int a[4] = { 2, 3, 4, 5 };
    int b[4] = { 3, 3, 4, 5 };
    struct sqlist lista;
    struct sqlist listb;
    init_list(&lista, 10);
    init_list(&listb, 10);
    int i;
    for (i = 0; i < 4; i++)
	list_insert(&lista, 0, a[i]);
    for (i = 0; i < 4; i++)
	list_insert(&listb, 0, b[i]);
    list_display(&lista);
    list_display(&listb);
    if ((&lista)->length > (&listb)->length)
	printf("lista is bigger than listb\n");
    else if ((&lista)->length < (&listb)->length)
	printf("listb is bigger than lista\n");
    else {
	for (i = 0; i < (&lista)->length; i++) {
	    if ((&lista)->p[i] > (&listb)->p[i]) {
		printf("lista is bigger than listb\n");
		break;
	    } else if ((&lista)->p[i] < (&listb)->p[i]) {
		printf("listb is bigger than lista\n");
		break;
	    } else if (i == (&lista)->length - 1)
		printf("lista is equal to listb\n");
	}
    }

}
