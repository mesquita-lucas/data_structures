// implementação assume que todos os valores são positivos

#include <stdlib.h>
#include "stack.h"

t_stack* create_stack(int max){
    t_stack* stack = (t_stack*)malloc(sizeof(t_stack));

    stack->max = max;
    stack->top = -1;
    stack->items = (int*)malloc(max * sizeof(int));

    return stack;
}

int push(t_stack* stack, int item){
    if(is_full(stack)){
        return 0;
    }

    stack->top++;

    stack->items[stack->top] = item;

    return 1;
}

int pop(t_stack* stack){
    if(is_empty(stack)){
        return -1;
    }

    return stack->items[stack->top--];
}

int top(t_stack* stack){
    return stack->items[stack->top];
}

int size(t_stack* stack){
    return stack->top + 1;
}

void clear(t_stack* stack){
    stack->top = -1;
}

void destroy(t_stack* stack){
    free(stack->items);
    free(stack);
}

int is_full(t_stack* stack){
    return stack->top + 1 == stack->max;
}

int is_empty(t_stack* stack){
    return stack->top == -1;
}