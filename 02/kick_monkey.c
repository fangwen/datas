#include <stdio.h>
#include "list.h"

main()
{
    struct sqlist list;
    init_list(&list, 20);
    int i;
    for (i = 19; i >= 0; i--)
	list_insert(&list, 0, i);
    list_display(&list);
    int j = (&list)->length;
    while (j != 0) {
	for (i = j - 1; i >= 0; i--) {
	    if (i % 3 == 0) {
		printf("%3d", (&list)->p[i]);
		list_delete(&list, i);
	    }
	}
	j = (&list)->length;
	printf("\n");
    }
    destroy_list(&list);
}
