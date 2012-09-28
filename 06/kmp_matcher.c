#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *kmp_table(char *p)
{
    int n = strlen(p);
    char table[n];
    int k = 0;
    int i;
    for(i = 0; i < n; i++) {
	while(k > 0 && p[k] != p[i])
	    k = table[k] - 1;
	if(p[k] == p[i])
	    k++;
	table[i] = k;
    }
    return table;
}

int main()
{
    char *p = "ababababca";
    char *table = kmp_table(p);
    printf ("%s\n", table);
    return 0;
    /* char s[1024*1024*1024]; */
    /* int c; */
    /* int i; */
    /* FILE *in; */
    /* in = fopen("/home/yufw/Downloads/E.coli.txt", "r"); */
    /* while((c = fgetc(in)) != EOF) { */
    /* 	s[i] = c; */
    /* 	i++; */
    /* } */
    /* s[i] = '\0'; */
    /* int j; */
    /* for(j = 0; j < i; j++) */
    /* 	printf ("%c", s[0]); */
    /* return 0; */
}
