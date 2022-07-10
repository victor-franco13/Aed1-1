#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

#define MAX 10 // tamanho maximo

struct lista
{
    int no[MAX];
    int Fim;
};

Lista cria_lista()
{
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));
    if (lst != NULL)
        lst->Fim = 0;
    return lst;
}

int lista_vazia(Lista lst)
{
    if (lst->Fim == 0)
        return 1; // Lista vazia
    else
        return 0; // Lista nao vazia
}

int lista_cheia(Lista lst)
{
    if (lst->Fim == MAX)
        return 1; // Lista cheia
    else
        return 0; // Lista nao cheia
}

int insere_elem(Lista lst, int elem)
{
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;

    lst->no[lst->Fim] = elem; // insere elemento
    lst->Fim++;
    return 1;
}

int remove_elem(Lista lst, int elem)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;
    int i, Aux = 0;
    // Percorrimento ate achar o elem ou o final da lista
    while (Aux < lst->Fim && lst->no[Aux] != elem)
        Aux++;
    if (Aux == lst->Fim) // final de lista
        return 0;        // falha
    // deslocamento a esquerda do sucessor até o final da lista
    for (i = Aux + 1; i < lst->Fim; i++)
        lst->no[i - 1] = lst->no[i];

    lst->Fim--; // decremento do campo fim
    return 1;   // sucesso
}