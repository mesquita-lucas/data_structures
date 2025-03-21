#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

typedef struct ordered_list{
    int max;
    int n;
    int* items;
} t_ordered_list;

t_ordered_list* create_ordered_list(int);

int size(t_ordered_list*);

int is_empty(t_ordered_list*);

int is_full(t_ordered_list*);

void destroy(t_ordered_list*);

void clear(t_ordered_list*);

int insert(t_ordered_list*, int);

int search(t_ordered_list*, int);

int remove_by_index(t_ordered_list*, int);

int remove_by_value(t_ordered_list*, int);

int remove_end(t_ordered_list*);

void print_ordered_list(t_ordered_list*);

t_ordered_list* merge(t_ordered_list*, t_ordered_list*);
#endif

int binary_search(int, int, t_ordered_list*, int);

void swap(int*, int*);