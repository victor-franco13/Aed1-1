/*
    De inicio planejava utilizar lista linear por pensar em um batalhao limitdo no entanto cheguei a conclusao que uma lista circular
    por ser mais facil percorrer com o pensamento de ser envolta da fogueira e pq ela atende um dos requisitos que é ir do inicio ao fim.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"
struct no
{
    char soldado[50];
    struct no *prox;
};

Lista cria_lista()
{
    return NULL;
};

int lista_vazia(Lista lst)
{
    return lst == NULL;
}

int lista_tam(Lista lst)
{
    if (lista_vazia(lst))
        return 0;
    int cont = 1;
    Lista aux = lst->prox;
    while (aux->prox != lst->prox)
    {
        aux = aux->prox;
        cont++;
    }
    return cont;
}
int insere_nome(Lista *lst, char *nome)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;

    strcpy(N->soldado, nome);
    if (lista_vazia(*lst))
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
int remove_pos(Lista *lst, int pos, char *nome)
{
    if (lista_vazia(*lst))
        return 0;
    while (pos > 0)
    {
        *lst = (*lst)->prox;
        pos--;
    }
    strcpy(nome, (*lst)->prox->soldado);
    Lista aux2 = (*lst)->prox;
    (*lst)->prox = aux2->prox;
    free(aux2);
    return 1;
}

int avanca_lista(Lista *lst, int pos)
{
    if (lista_vazia(*lst) || pos < 0)
        return 0;
    while (pos > 0)
    {
        *lst = (*lst)->prox;
        pos--;
    }
    return 1;
}
int avanca_lista_nome(Lista *lst, char *name)
{
    if (lista_vazia(*lst))
        return 0;
    Lista aux = *lst;
    if (strcmp((*lst)->prox->soldado, name))
    {
        aux = (*lst)->prox;
        while (aux->prox != (*lst)->prox && strcmp(aux->prox->soldado, name))
            aux = aux->prox;
        if (aux->prox == (*lst)->prox)
        {
            return 0;
        }
        *lst = aux;
    }
    return 1;
}
int obtem_valor_elem(Lista lst, int indice, char *elem)
{
    if (indice < 0 || lista_vazia(lst))
        return 0;
    Lista aux = lst->prox;
    while (indice > 0 && aux->prox != lst->prox)
    {
        aux = aux->prox;
        indice--;
    }
    if (!indice)
    {
        strcpy(elem, aux->soldado);
        return 1;
    }
    return 0;
}