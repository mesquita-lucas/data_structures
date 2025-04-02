#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "double_linked_list.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Criação de uma nova lista
    t_list* list = create_list();
    printf("Lista criada: \n");
    print(list);

    // Adicionando elementos
    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);
    printf("\nLista após append: \n");
    print(list);

    // Inserindo elemento em um índice específico
    insert(list, 1, 15);
    printf("\nLista após inserir 15 no índice 1: \n");
    print(list);

    // Verificando se um item existe
    int index = find(list, 20);
    printf("\nÍndice do item 20: %d\n", index);

    // Removendo item específico
    remove_item(list, 20);
    printf("Lista após remover o item 20: ");
    print(list);

    // Removendo item na posição específica
    remove_at(list, 1); // Remove o item na posição 1 (15)
    printf("\nLista após remover o item na posição 1: \n");
    print(list);

    // Limpando a lista
    
    clear(list, list->head);
    printf("\nLista após clear (deve estar vazia): \n");
    print(list);

    // Clonando a lista
    append(list, 50);
    append(list, 60);
    t_list* cloned_list = create_list();
    clone(list, cloned_list);
    printf("\nLista clonada: \n");
    print(cloned_list);

    // Destruindo as listas
    destroy(list);
    destroy(cloned_list);

    return 0;
}