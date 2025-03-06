#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

typedef struct ordered_list{
    int max;
    int n;
    int* items;
} t_ordered_list;

t_ordered_list* create_ordered_list(int max);

int size(t_ordered_list* olist);

int is_empty(t_ordered_list* olist);

int is_full(t_ordered_list* olist);

void destroy(t_ordered_list* olist);

void clear(t_ordered_list* olist);

int insert(t_ordered_list* olist, int value);

int search(t_ordered_list* olist, int value);

int remove_by_index(t_ordered_list* olist, int index);

int remove_by_value(t_ordered_list* olist, int value);

int remove_end(t_ordered_list* olist);

void print_ordered_list(t_ordered_list* olist);

t_ordered_list* merge(t_ordered_list* olist, t_ordered_list* other_olist);
#endif

int binary_search(int start_index, int end_index, t_ordered_list* olist, int value);

void swap(int* value, int* sec_value);