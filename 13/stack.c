#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(stack *s, int maxsize)
{
    (s->base) = (int *)malloc(sizeof(int)*maxsize);
    if(s->base == NULL)
		exit(1);
    s->top = s->base;
    s->size = maxsize;
}

void push(stack *s, int e)
{
    if(s->top - s->base == s->size)
		exit(1);
    *(++s->top) = e;
}

int pop(stack *s)
{
    int e;
    if(s->top == s->base)
		exit(1);
    e = *(s->top--);
    return e;
}

int stack_length(stack *s)
{
    int length;
    length = s->top - s->base;
    return length;
}

int gettop(stack *s)
{
    return *s->top;
}

void print_stack(stack *s)
{
    while(stack_length(s) != 0)
    	printf("%c", pop(s));
    printf ("\n");
}
