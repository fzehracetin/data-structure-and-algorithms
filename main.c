#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int top;
    int Stack[MAX];
}stack;

void initStack(stack *s){
    s->top = 0;
}

int isFull (stack *s) {
    if (s->top == MAX) 
        return 1;
    else
        return 0;
}

int isEmpty (stack *s) {
    if (s->top == 0) 
        return 1;
    else
        return 0;
}

int pop (stack *s, int *x) {
    if (isEmpty(s))
        return 0;
    else {
        *x = s->Stack[--s->top];
        return 1;
    }
}

int push (stack *s, int x) {
    if (isFull(s)) 
        return 0;
    else {
        s->Stack[s->top++] = x;
        return 1;
    }
}

int peek (stack *s, int *x) {
    if (isEmpty(s))
        return 0;
    else {
        int peaky = s->top - 1;
        *x = s->Stack[peaky];
        return 1;
    }
}

void printStack(stack *s) {
    if (isEmpty(s))
        return;
    else {
        int i = s->top-1;
        while( i >= 0) {
            printf("%d ", s->Stack[i]);
            i--;
        } printf("\n");
    }
}

int main(int argc, char **argv)
{
    stack s;
    int x;
    initStack(&s);
    push(&s, 5);
    push(&s, 7);
    push(&s, 15);
    printStack(&s);
    pop(&s, &x);
    printf("poped value = %d \n", x);
    printStack(&s);
    peek(&s, &x);
    printf("peeked value = %d\n", x);
    printStack(&s);
	return 0;
}
