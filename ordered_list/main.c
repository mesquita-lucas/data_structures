#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ordered_list.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("=== Testando a Ordered List ===\n");

    // Criando a lista ordenada
    t_ordered_list *olist = create_ordered_list(5);
    if (!olist) {
        printf("Erro ao criar a lista!\n");
        return 1;
    }

    printf("Lista criada! Tamanho máximo: %d\n", olist->max);

    // Testando inserções
    printf("Inserindo elementos...\n");
    insert(olist, 10);
    insert(olist, 5);
    insert(olist, 8);
    insert(olist, 1);
    insert(olist, 3);
    print_ordered_list(olist);

    // Testando busca binária
    printf("Buscando elementos...\n");
    printf("Posição do número 8: %d\n", search(olist, 8));
    printf("Posição do número 2 (não existente): %d\n", search(olist, 2));

    // Testando remoções
    printf("Removendo elementos...\n");
    remove_by_index(olist, 2);  // Removendo elemento no meio
    print_ordered_list(olist);

    remove_by_value(olist, 1);  // Removendo o primeiro
    print_ordered_list(olist);

    remove_end(olist);  // Removendo o último
    print_ordered_list(olist);

    // Testando fusão de listas
    t_ordered_list *olist2 = create_ordered_list(5);
    insert(olist2, 2);
    insert(olist2, 6);
    insert(olist2, 12);
    printf("Outra lista ordenada: ");
    print_ordered_list(olist2);

    t_ordered_list *merged_list = merge(olist, olist2);
    printf("Lista mesclada: ");
    print_ordered_list(merged_list);

    // Testando limpeza e destruição
    clear(olist);
    printf("Lista limpa: \n");
    print_ordered_list(olist);

    destroy(olist);
    destroy(olist2);
    destroy(merged_list);
    
    printf("\nFinalizando testes...\n");

    return 0;
}