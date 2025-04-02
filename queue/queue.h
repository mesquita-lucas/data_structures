typedef struct queue{
    int* items;
    int front;
    int rear;
    int max;
}t_queue;

t_queue* create_queue(int);

void in(t_queue*, int);

int out(t_queue*);

int is_empty(t_queue*);

int is_full(t_queue*);

void clear(t_queue*);

int size(t_queue*);

void display(t_queue*);