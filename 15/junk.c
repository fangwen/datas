#include<stdio.h>

int main()
{
	int a[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int *p1[3]={a[0],a[1],a[2]};
	int **p2=p1;
	p1++;
	p2++;
	return 0;
}
