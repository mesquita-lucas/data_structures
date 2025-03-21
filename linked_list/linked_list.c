#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

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

// if the given index is beyond the scope of the list, appends the item to the end of the list
int insert(t_list* list, int item, int index){
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->item = item;
    node->next = NULL;

    if(index >= list->size-1){
        append(list, item);
        return 1;
    }
    
    t_node* aux = list->head;

    if(index == 0){
        list->head = node;
        node->next = aux;
        list->size++;

        return 1;
    }

    int i = 0;
    while(i < index-1){
        aux = aux->next;
        i++;
    }

    node->next = aux->next;
    aux->next = node;
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
    if(is_empty(list)){
        return 0;
    }

    t_node* aux = list->head;

    if(aux->item == item){
        list->head = aux->next;
        list->size--;
        free(aux);
        return 1;
    }



    while(aux->next != NULL){
        if(aux->next->item == item){

            if(aux->next->item == list->tail->item){
                list->tail = aux;
                list->tail->next = NULL;
                free(aux->next);
                list->size--;
                return 1;
            }

            aux->next = aux->next->next;
            free(aux->next);
            list->size--;
            return 1;
        }

        aux = aux->next;
    }

    return 0;
}

int remove_at(t_list* list, int index){
    if(is_empty(list) || index < 0 || index >= list->size){
        return 0;
    }
    
    t_node* aux = list->head;
    t_node* to_remove;

    if(index == 0){
        to_remove = list->head;
        list->head = list->head->next;

        if(list->size == 1){
            list->tail = NULL;
        }
        
        free(to_remove);
        list->size--;
        return 1;
    }

    for(int i = 0; i < index - 1; i++){
        aux = aux->next;
    }
    
    to_remove = aux->next;

    if(to_remove == list->tail){
        list->tail = aux;
        aux->next = NULL;
    } else {
        aux->next = to_remove->next;
    }
    
    free(to_remove);
    list->size--;
    return 1;
}

int clear(t_list* list){
    if(list == NULL || is_empty(list)){
        return 1;
    }    

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return 1;
}

t_node* get_node_item(t_list* list, int item){
    if(is_empty(list)){
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

t_node* get_item_by_index(t_list* list, int index){
    if(is_empty(list)){
        return NULL;
    }

    if(index >= list->size || index < 0){
        return NULL;
    }

    t_node* aux = list->head;

    for(int i = 0; i < index; i++){
        aux = aux->next;
    }

    return aux;
}

t_node* peek_back(t_list* list){
    return list->tail;
}

t_node* peek_front(t_list* list){
    return list->head;
}

t_node* pop_back(t_list* list){
    t_node* node = get_node_item(list, list->tail->item);
    
    remove_item(list, list->tail->item);

    return node;
}

t_node* pop_front(t_list* list){
    t_node* node = get_node_item(list, list->head->item);

    remove_item(list, list->head->item);

    return node;
}

int reverse(t_list* list){
    if(is_empty(list)){
        return 0;
    }
    
    t_node** node_array = (t_node**)malloc(list->size * sizeof(t_node*));
    t_node* aux = list->head;

    int i = 0;
    while(aux != NULL){
        node_array[i] = aux;
        aux = aux->next;
        i++;
    }

    int start_pointer = 0, end_pointer = list->size - 1;

    while(start_pointer < end_pointer){
        swap(node_array[start_pointer++], node_array[end_pointer--]);
    }

    free(node_array);
    return 1;
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

// assumes both are sorted
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
        clear(dest);
    }

    t_node* aux = src->head;
    while(aux != NULL){
        append(dest, aux->item);
        aux = aux->next;
    }

    return 1;
}

void swap(t_node* node_a, t_node* node_b){
    int aux = node_a->item;
    node_a->item = node_b->item;
    node_b->item = aux;
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