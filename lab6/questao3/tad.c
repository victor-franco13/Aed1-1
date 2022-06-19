#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct bebida
{
    char nome[20];
    float preco;
    int volume;
};

struct no
{
    struct bebida info;
    struct no *prox;
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

int insere_elem(Lista *lst, char nome[], float preco, int volume)
{
    Lista novo;
    novo = (Lista)malloc(sizeof(struct no));
    if (novo == NULL)
        return 0;
    strcpy(novo->info.nome, nome);
    novo->info.preco = preco;
    novo->info.volume = volume;
    novo->prox = *lst;
    *lst = novo;
    return 1;
}

int remove_elem(Lista *lst, char nome[])
{
    if (lista_vazia(*lst) == 1)
        return 0;
    Lista aux = *lst;
    if (strcpy(aux->info.nome, nome) == 0)
    {
        *lst = aux->prox;
        free(aux);
        return 1;
    }
}

int consulta_elem(Lista lst, char nome[])
{
    if (lista_vazia(lst) == 1)
        return 0;
    Lista aux = lst;
    while (aux != NULL)
    {
        if (strcpy(aux->info.nome, nome) == 0)
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