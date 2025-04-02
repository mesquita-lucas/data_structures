#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

t_queue* create_queue(int max){
    t_queue* queue = (t_queue*)malloc(sizeof(t_queue));
    
    queue->items = (int*)malloc(max * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->max = max;
    
    return queue;
}

void in(t_queue* queue, int item){
    if(is_full(queue)){
        return;
    }

    if(is_empty(queue)){
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->max;
    queue->items[queue->rear] = item;
}

int out(t_queue* queue){
    if(is_empty(queue)){
        return -1;
    }
    
    int item = queue->items[queue->front];

    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->max;
    }

    return item;
}

int is_empty(t_queue* queue){
    return queue->front == -1;
}

int is_full(t_queue* queue){
    return (queue->rear + 1) % queue->max == queue->front;
}

void clear(t_queue* queue){
    queue->front = -1;
    queue->rear = -1;
}

int size(t_queue* queue){
    if (is_empty(queue)) {
        return 0;
    }

    if (queue->rear >= queue->front) {
        return queue->rear - queue->front + 1;
    } else { // deu a volta
        return queue->max - queue->front + queue->rear + 1;
    }
}

void display(t_queue* queue){
    if(is_empty(queue)){
        printf("[]");
        return;
    }

    int i = queue->front;
    while(1){
        printf("%d ", queue->items[i]);

        if(i == queue->rear){
            break;
        }

        i = (i + 1) % queue->max;
    }
}