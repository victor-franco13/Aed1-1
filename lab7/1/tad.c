#include "tad.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *prox;
};

Lista cria_lista()
{
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));
    if (cab != NULL)
    {
        cab->prox = NULL;
        cab->info = 0;
    }
    return cab;
}

int lista_vazia(Lista lst)
{
    if (lst->prox == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    N->prox = lst->prox;
    lst->prox = N;
    lst->info++;
    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if (lista_vazia(lst) == 1)
        return 0;
    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;
    if (aux->prox == NULL)
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    (*lst)->info--;
    return 1;
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