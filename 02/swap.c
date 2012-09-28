#include <stdio.h>
#include "list.h"

main()
{
    int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
    struct sqlist lista;
    init_list(&lista, 10);
    int i;
    for (i = 0; i < 7; i++)
	list_insert(&lista, 0, a[i]);
    list_display(&lista);
    int temp;
    for (i = 0; i < 2; i++) {
	temp = (&lista)->p[i];
	(&lista)->p[i] = (&lista)->p[3 - i];
	(&lista)->p[3 - i] = temp;
    }
    for (i = 4; i < 5; i++) {
	temp = (&lista)->p[i];
	(&lista)->p[i] = (&lista)->p[10 - i];
	(&lista)->p[10 - i] = temp;
    }
    for (i = 0; i < 3; i++) {
	temp = (&lista)->p[i];
	(&lista)->p[i] = (&lista)->p[6 - i];
	(&lista)->p[6 - i] = temp;
    }
    list_display(&lista);
}
