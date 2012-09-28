#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    char *base;
    char *top;
    int size;
}stack;

void init_stack(stack *s, int maxsize)
{
    (s->base) = (char *)malloc(sizeof(char)*maxsize);
    if(s->base == NULL)
	exit(1);
    s->top = s->base;
    s->size = maxsize;
}

void push(stack *s, char e)
{
    if(s->top - s->base == s->size)
	exit(1);
    *(++s->top) = e;
}

int pop(stack *s)
{
    char e;
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

char gettop(stack *s)
{
    return *s->top;
}

void print_stack(stack *s)
{
    while(stack_length(s) != 0)
    	printf("%c", pop(s));
    printf ("\n");
}

int priority(char ch)
{
    switch(ch) {
    case '+':
	return 1;
    case '-':
	return 1;
    case '*':
	return 2;
    case '/':
	return 2;
    case '#':
	return 0;
    }
}

void transform(stack *suffix, char exp[])
{
    stack s;
    init_stack(&s, 100);
    push(&s, '#');
    while(*exp != '#') {
	if(*exp != '+' && *exp != '-' && *exp != '*' && *exp != '/') {
	    push(suffix, *exp);
	}else if(stack_length(&s) != 0 && priority(*exp) > priority(gettop(&s))){
	    push(&s, *exp);
	}else {
	    while(stack_length(&s) != 1 && priority(*exp) <= priority(gettop(&s))) {
		push(suffix, pop(&s));
	    }
	    push(&s, *exp);
	    }
	exp++;
    }
    while(stack_length(&s) != 0)
	push(suffix, pop(&s));
}
int calculate(char ch1, char ch2, char ch3)
{
    int i = ch1 - 48;
    int j = ch2 - 48;
    switch(ch3) {
    case '+':
	return i + j;
    case '-':
	return i - j;
    case '*':
	return i * j;
    case '/':
	return i / j;
    }
}

int suffix_cal(char exp[])
{
    stack temp;
    stack s;
    stack s2;
    init_stack(&temp, 100);
    init_stack(&s, 100);
    init_stack(&s2, 100);
    while(*exp != '\0') {
	push(&temp, *exp);
	exp++;
    }
    while(stack_length(&temp) != 0)
	push(&s, pop(&temp));
    while(stack_length(&s) != 0) {
	push(&s2, pop(&s));
	if(gettop(&s2) == '+' ||gettop(&s2) == '-'||gettop(&s2)=='*'||gettop(&s2) == '/') {
	    char ch3 = pop(&s2);
	    char ch2 = pop(&s2);
	    char ch1 = pop(&s2);
	    int r = calculate(ch1, ch2, ch3);
	    char ch = r + 48;
	    push(&s2, ch);
	}
    }
    return gettop(&s2) - 48;
}


int main()
{
    printf("hello, world\n");
    stack suffix;
    init_stack(&suffix, 100);
    char exp[] = "1+3*2-4/2*3#";
    char exp2[] = "132*+42/3*-";
    printf("%s\n", exp);
    transform(&suffix, exp);
    print_stack(&suffix);
    printf("hello, world\n");
    int i = calculate('2', '4', '*');
    printf("%d\n", i);
    int r = suffix_cal(exp2);
    printf("%d\n", r);
    return 0;
}
