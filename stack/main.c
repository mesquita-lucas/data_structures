#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "stack.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Criando uma pilha com capacidade para 5 elementos
    t_stack *stack = create_stack(5);

    printf("Stack criada! Capacidade máxima: %d\n", stack->max);
    printf("Stack está vazia? %s\n", is_empty(stack) ? "Sim" : "Não");

    // Testando push()
    printf("\nEmpilhando elementos: 10, 20, 30, 40, 50\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    printf("Stack cheia? %s\n", is_full(stack) ? "Sim" : "Não");
    printf("Tamanho atual: %d\n", size(stack));
    printf("Elemento no topo: %d\n", top(stack));

    // Tentando empilhar mais um elemento (deve falhar)
    if (!push(stack, 60))
    {
        printf("Falha ao empilhar 60: Stack está cheia\n");
    }

    // Testando pop()
    printf("\nDesempilhando elementos...\n");
    while (!is_empty(stack))
    {
        printf("Elemento removido: %d\n", pop(stack));
    }

    printf("Stack está vazia? %s\n", is_empty(stack) ? "Sim" : "Não");

    // Tentando desempilhar de uma stack vazia
    if (pop(stack) == -1)
    {
        printf("Falha ao desempilhar: Stack está vazia\n");
    }

    // Testando clear()
    printf("\nEmpilhando 5 e 15...\n");
    push(stack, 5);
    push(stack, 15);
    printf("Tamanho antes de limpar: %d\n", size(stack));

    clear(stack);
    printf("Tamanho após limpar: %d\n", size(stack));

    // Testando destroy()
    destroy(stack);
    printf("\nStack destruída com sucesso!\n");

    return 0;
}