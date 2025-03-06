/*
1 - O valor de uma lista ordenada se dá na sua própria ordenação. Apesar da inserção e remoção ser O(N), podemos acessar seus 
elementos através do índice, portanto, em tempo constante. A busca binária também se torna possível, levando a buscas em O(log n)

2 - A estratégia que usei para aumentar o tamanho da memória foi utilizar um realloc, localizado direto na função de inserção.
Sempre que chega ao limite, adiciona mais 10.

*/

#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.h"

t_ordered_list *create_ordered_list(int max)
{
    t_ordered_list *olist;
    olist = (t_ordered_list *)malloc(sizeof(t_ordered_list));

    olist->max = max;
    olist->n = 0;
    olist->items = (int *)malloc(max * sizeof(int));

    return olist;
}

int size(t_ordered_list *olist)
{
    return olist->n;
}

int is_empty(t_ordered_list *olist)
{
    return olist == NULL || olist->n == 0;
}

int is_full(t_ordered_list *olist)
{
    return olist->n == olist->max;
}

void destroy(t_ordered_list *olist)
{
    free(olist->items);
    free(olist);
}

void clear(t_ordered_list *olist)
{
    olist->n = 0;
}

int insert(t_ordered_list *olist, int value)
{
    if (is_full(olist))
    {
        olist->max += 10;
        olist->items = realloc(olist->items, sizeof(int) * olist->max);
    }

    olist->items[olist->n] = value;

    int i = olist->n;
    while(i > 0 && olist->items[i-1] > value){
        swap(&olist->items[i], &olist->items[i-1]);
        i--;
    }

    olist->n++;

    return 1;
}

int search(t_ordered_list *olist, int value)
{
    if (is_empty(olist))
    {
        return -1;
    }
    return binary_search(0, olist->n, olist, value);
}

int remove_by_index(t_ordered_list *olist, int index)
{
    if (is_empty(olist))
    {
        return 0;
    }

    int i;
    for (i = index; i < olist->n - 1; i++)
    {
        olist->items[i] = olist->items[i + 1];
    }

    olist->n--;
    return 1;
}

int remove_by_value(t_ordered_list *olist, int value)
{
    if (is_empty(olist))
    {
        return 0;
    }

    int value_position = search(olist, value);

    if (value_position == -1){
        return 0;
    }

    return remove_by_index(olist, value_position);
}

int remove_end(t_ordered_list *olist)
{
    if (is_empty(olist))
    {
        return 0;
    }

    olist->n--;

    return 1;
}

void print_ordered_list(t_ordered_list *olist)
{
    if (is_empty(olist))
    {
        printf("[]");
        return;
    }

    printf("[");

    int i;
    for (i = 0; i < olist->n - 1; i++)
    {
        printf("%d, ", olist->items[i]);
    }

    printf("%d]\n", olist->items[i]);

}

t_ordered_list *merge(t_ordered_list *olist, t_ordered_list *other_olist)
{
    t_ordered_list *new_olist = create_ordered_list(olist->n + other_olist->n);

    int i = 0, j = 0, k = 0;

    while(i < olist->n && j < other_olist->n){
        if(olist->items[i] <= other_olist->items[j]){
            new_olist->items[k++] = olist->items[i++];
        } else {
            new_olist->items[k++] = other_olist->items[j++];
        }
    }

    while(i < olist->n){
        new_olist->items[k++] = olist->items[i++];
    }

    while(j < other_olist->n){
        new_olist->items[k++] = other_olist->items[j++];
    }

    new_olist->n = k;

    return new_olist;
}

int binary_search(int start_index, int end_index, t_ordered_list *olist, int value)
{
    if (end_index >= start_index)
    {
        int middle_index = (start_index + end_index) / 2;

        if (olist->items[middle_index] == value)
        {
            return middle_index;
        }

        if (olist->items[middle_index] > value)
        {
            return binary_search(start_index, middle_index - 1, olist, value);
        }

        if (olist->items[middle_index] < value)
        {
            return binary_search(middle_index + 1, end_index, olist, value);
        }
    }

    return -1;
}

void swap(int* value, int* sec_value){
    int aux = *value;
    *value = *sec_value;
    *sec_value = aux;
}