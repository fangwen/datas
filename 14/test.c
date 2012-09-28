#include <stdio.h>

int main()
{
    int array[10][10][10];
    array[9][9][9] = 1;
    printf("%d\n", array[9][9][9]);
    return 0;
}
