#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct no
{
    int info;
    struct list_rec *prox;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *lst, int elem)
{
    Lista novo;
    novo = (Lista)malloc(sizeof(struct no));
    if (novo == NULL)
        return 0;
    novo->info = elem;
    novo->prox = *lst;
    *lst = novo;
    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if (lista_vazia(*lst) == 1)
        return 0;
    Lista aux = *lst;
    if (aux->info == elem)
    {
        *lst = aux->prox;
        free(aux);
        return 1;
    }
}

int consulta_elem(Lista lst, int elem)
{
    if (lista_vazia(lst) == 1)
        return 0;
    Lista aux = lst;
    while (aux != NULL)
    {
        if (aux->info == elem)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

int print_lista(Lista lst)
{
    if (lista_vazia(lst) == 1)
        return 0;
    Lista aux = lst;
    while (aux != NULL)
    {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
    return 1;
}