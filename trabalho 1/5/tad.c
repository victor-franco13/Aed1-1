#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct no
{
    int info;
    struct no *prox;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista *lst)
{
    if (*lst == NULL)
        return 1; // Lista vazia
    else
        return 0; // lista nao vazia
}

int insere_final(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;

    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }
    else
    {
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }
    return 1;
}

int remove_inicio(Lista *lst, int *elem)
{
    if (lista_vazia(*lst) == 1)
        return 0;
    Lista aux = (*lst)->prox;
    *elem = aux->info;
    if (*lst == (*lst)->prox)
        *lst = NULL;
    else
        (*lst)->prox = aux->prox;
    free(aux);
    return 1;
}

int insere_inicio(Lista *lst, int elem)
{
    if (lst == NULL)
        return 0;
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    if ((*lst) == NULL)
    {
        *lst = N;
        N->prox = N;
    }
    else
    {
        Lista aux = *lst;
        while (aux->prox != (*lst))
        {
            aux = aux->prox;
        }
        aux->prox = N;
        N->prox = *lst;
        *lst = N;
    }
    return 1;
}

int tamanho(Lista *lst)
{
    if (lst == NULL || (*lst) == NULL)
        return 0;
    int cont = 0;
    Lista N = *lst;
    do
    {
        cont++;
        N = N->prox;
    } while (N != (*lst));
    return cont;
}

int insere_pos(Lista *lst, int index, int elem)
{
    if (index < 0 || lista_vazia(lst) || index >= lista_tam(lst))
        return 0;
    // Daqui pra frente existe a posição da lista que deseja-se colocar
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    N->prox = NULL;
    Lista aux = (*lst)->prox;
    while (index--)
        aux = aux->prox;
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}
// Remove em determinda posição
int remove_pos(Lista *lst, int index, int *elem)
{
    if (lista_vazia(lst))
        return 0;
    // Percorro até a posição pos
    while (index > 0)
    {
        *lst = (*lst)->prox;
        index--;
    }
    // Retorna o nome removido
    *elem = (*lst)->prox->info;
    Lista aux2 = (*lst)->prox;
    (*lst)->prox = aux2->prox;
    free(aux2);
    return 1;
}