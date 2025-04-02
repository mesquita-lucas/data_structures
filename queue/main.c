#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "queue.h"

int main(void){
    setlocale(LC_ALL, "Portuguese");
    
    t_queue* queue = create_queue(5);

    printf("Inserindo elementos na fila: 1, 2, 3, 4\n");
    in(queue, 1);
    in(queue, 2);
    in(queue, 3);
    in(queue, 4);
    
    printf("Fila atual: ");
    display(queue);
    printf("\n");
    
    printf("Removendo um elemento da fila: %d\n", out(queue));
    
    printf("Inserindo mais um elemento: 5\n");
    in(queue, 5);
    
    printf("Fila atual: ");
    display(queue);
    printf("\n");
    
    printf("Removendo mais dois elementos: %d, %d\n", out(queue), out(queue));
    
    printf("Fila atual: ");
    display(queue);
    printf("\n");
    
    printf("Inserindo mais dois elementos: 6, 7\n");
    in(queue, 6);
    in(queue, 7);
    
    printf("Fila atual: ");
    display(queue);
    printf("\n");
    
    printf("Tamanho da fila: %d\n", size(queue));
    
    printf("Limpando a fila...\n");
    clear(queue);
    
    printf("Fila atual: ");
    display(queue);
    printf("\n");
    
    return 0;
}