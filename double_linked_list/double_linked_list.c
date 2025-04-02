#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

t_list* create_list(){
    t_list* list = (t_list*)malloc(sizeof(t_list));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int destroy(t_list* list){
    t_node* elem = list->head;
    t_node* aux;

    while(elem != NULL){
        aux = elem;
        elem = elem->next;
        free(aux);
    }

    free(list);
    return 1;
}   

int append(t_list* list, int item){
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->item = item;
    node->next = NULL;
    node->prev = list->tail;

    if(is_empty(list)){
        list->head = node;
        list->tail = node;

        list->size++;
        return 1;
    }

    list->tail->next = node;
    list->tail = node;

    list->size++;

    return 1;
}

int is_empty(t_list* list){
    return list->size == 0;
}

int size(t_list* list){
    return list->size;
}

int insert(t_list* list, int index, int item){
    if(index >= list->size){
        return append(list, item);
    }

    t_node* aux = list->head;
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->item = item;
    node->next = NULL;

    for(int i = 0; i<index; i++){
        aux = aux->next;
    }

    node->prev = aux->prev;
    aux->prev->next = node;
    aux->prev = node;
    node->next = aux;

    list->size++;
    return 1;
}

int find(t_list* list, int item){
    if(is_empty(list)){
        return -1;
    }

    t_node* aux = list->head;
    for(int i = 0; i < list->size; i++){
        if(aux->item == item){
            return i;
        }

        aux = aux->next;
    }

    return -1;
}

int remove_item(t_list* list, int item){
    if(is_empty(list)) {
        return 0;
    }

    t_node* aux = list->head;

    if(item == list->head->item){
        list->head = list->head->next;
        
        free(aux);
        list->size--;
        return 1;
    }

    aux = aux->next;
    while(aux != NULL){
        if(aux->item == item){
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;

            free(aux);
            list->size--;
            return 1;
        }

        aux = aux->next;
    }

    return 1;
}

int remove_at(t_list* list, int index){
    if(is_empty(list) || index >= list->size || index < 0){
        return 0;
    }

    t_node* aux = list->head;

    if(index == 0){
        list->head->next = list->head;
    } else {
        for(int i = 0; i < index; i++){
            aux = aux->next;
        }
    
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;    
    }

    free(aux);
    list->size--;

    return 1;
}

void clear(t_list* list, t_node* head){
    if(list == NULL || is_empty(list)){
        return;
    }

    if(head == NULL){
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    clear(list, head->next);
    free(head);
}

t_node* get_node_item(t_list* list, int item){
    if(list == NULL || is_empty(list)){
        return NULL;
    }

    t_node* aux = list->head;

    while(aux != NULL){
        if(aux->item == item){
            return aux;
        }

        aux = aux->next;
    }

    return NULL;
}

t_node* get_item_by_index(t_list* list, int idx){
    if(list == NULL || is_empty(list)){
        return NULL;
    }

    if(idx < 0 || idx >= list->size){
        return NULL;
    }

    t_node* aux = list->head;

    for(int i = 0; i <= idx; i++){
        aux = aux->next;
    }

    return aux;
}

t_node* peek_front(t_list* list){
    if(list == NULL || is_empty(list)){
        return NULL;
    }

    return list->head;
}

t_node* peek_back(t_list* list){
    if(list == NULL || is_empty(list)){
        return NULL;
    }

    return list->tail;
}

t_node* pop_front(t_list* list){
    if(list == NULL || is_empty(list)){
        return NULL;
    }

    t_node* aux = list->head;

    list->head->next = list->head;
    list->head->prev = NULL;

    return aux;
}

t_node* pop_back(t_list* list){
    if(list == NULL || is_empty(list)){
        return NULL;
    }

    t_node* aux = list->head;

    list->head->next = list->head;
    list->head->prev = NULL;

    return aux;
}

int reverse(t_list* list){
    if(list == NULL || is_empty(list)){
        return -1;
    }

    if(list->size == 1) {
        return 0;
    }

    t_node* cur = list->head;
    t_node* aux = NULL;

    while(cur != NULL){
        t_node* aux = cur->next;
        cur->next = cur->prev;
        cur->prev = aux;
        
        cur = cur->prev;
    }

    aux = list->head;
    list->head = list->tail;
    list->tail = aux;

    return 0;
}

int sort(t_list* list){
    if(is_empty(list)){
        return 0;
    }

    t_node* aux;
    int number_of_swaps = 1;

    while(number_of_swaps != 0){
        number_of_swaps = 0;
        aux = list->head;

        while(aux->next != NULL){
            if(aux->item > aux->next->item){
                swap(aux, aux->next);
                number_of_swaps++;
            }

            aux = aux->next;
        }
    }

    return 1;
}

t_list* merge(t_list* list_a, t_list* list_b){
    if(is_empty(list_a)){
        return list_b;
    } 

    if(is_empty(list_b)){
        return list_a;
    }
    
    t_list* new_list = create_list();
    t_node* aux_for_list_a = list_a->head;
    t_node* aux_for_list_b = list_b->head;

    while(aux_for_list_a != NULL && aux_for_list_b != NULL){
        if(aux_for_list_a->item <= aux_for_list_b->item){
            append(new_list, aux_for_list_a->item);

            aux_for_list_a = aux_for_list_a->next;
        } else {
            append(new_list, aux_for_list_b->item);

            aux_for_list_b = aux_for_list_b->next;
        }
    }

    while(aux_for_list_a != NULL){
        append(new_list, aux_for_list_a->item);
        
        aux_for_list_a = aux_for_list_a->next;
    }

    while(aux_for_list_b != NULL){
        append(new_list, aux_for_list_b->item);
        
        aux_for_list_b = aux_for_list_b->next;
    }

    return new_list;
}

int clone(t_list* src, t_list* dest){
    if(is_empty(src)){
        return 0;
    }

    if(!is_empty(dest)){
        clear(dest, dest->head);
    }

    t_node* aux = src->head;
    while(aux != NULL){
        append(dest, aux->item);
        aux = aux->next;
    }

    return 1;
}

void print(t_list* list){
    if(is_empty(list)){
        printf("[]");
        return;
    }
    
    t_node* aux = list->head;
    printf("[");

    while(aux->next != NULL){
        printf("%d, ", aux->item);
        aux = aux->next;        
    }

    printf("%d]", aux->item);
}

void swap(t_node* nodeA, t_node* nodeB){
    int aux = nodeA->item;
    nodeA->item = nodeB->item;
    nodeB->item = nodeA->item;
}  