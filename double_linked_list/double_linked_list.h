#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct node{
    int item;
    struct node* next;
    struct node* prev;
} t_node;

typedef struct list{
    int size;
    t_node* head;
    t_node* tail;
} t_list;

t_list* create_list();

int destroy(t_list*);

int append(t_list*, int);

int is_empty(t_list*);

int size(t_list*);

int insert(t_list*, int, int);

int find(t_list*, int);

int remove_item(t_list*, int);

int remove_at(t_list*, int);

void clear(t_list*, t_node*);

t_node* get_node_item(t_list*, int);

t_node* get_item_by_index(t_list*, int);

t_node* peek_front(t_list*);

t_node* peek_back(t_list*);

t_node* pop_front(t_list*);

t_node* pop_back(t_list*);

int reverse(t_list*);

int sort(t_list*);           

t_list* merge(t_list*, t_list*);

int clone(t_list*, t_list*);

void print(t_list*);

void swap(t_node*, t_node*);

#endif