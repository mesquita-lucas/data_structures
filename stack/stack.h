#ifndef STACK_H
#define STACK_H

typedef struct stack{
    int* items;
    int max;
    int top;
} t_stack;

t_stack* create_stack(int);

int push(t_stack*, int);

int pop(t_stack*);

int top(t_stack*);

int size(t_stack*);

void clear(t_stack*);

void destroy(t_stack*);

int is_full(t_stack*);

int is_empty(t_stack*);

#endif