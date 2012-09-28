#ifndef _STACK_H
#define _STACK_H

typedef struct stack {
    int *base;
    int *top;
    int size;
}stack;

void init_stack(stack *s, int maxsize);
void push(stack *s, int e);
int pop(stack *s);
int stack_length(stack *s);
int gettop(stack *s);
void print_stack(stack *s);

#endif
