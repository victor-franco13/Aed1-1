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

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1; // Lista vazia
    else
        return 0; // lista nao vazia
}

int insere_ord(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    N->info = elem;
    if (lista_vazia(*lst) || elem <= (*lst)->info)
    {
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    Lista aux = *lst;
    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ord(Lista *lst, int elem)
{
    if (lista_vazia(lst) == 1 || elem < (*lst)->info)
        return 0; // falha
    Lista aux = *lst;
    if (elem == (*lst)->info)
    {
        *lst = aux->prox;
        free(aux);
        return 1;
    }
    while (aux->prox != NULL && aux->prox->info > elem)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int tamanho(Lista *lst)
{
    if (lst == NULL)
        return 0;
    int cont = 0;
    Lista aux = *lst;
    while (aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

float media(Lista *lst)
{
    if (lista_vazia(lst) == 1)
        return 0; // falha
    int t = tamanho(lst);
    int sum = 0;
    Lista aux = *lst;
    while (aux->prox != NULL)
    {
        sum += aux->info;
        aux = aux->prox;
    }

    float media;

    media = sum / t;

    return media;
}

int comparar(Lista lista1, Lista lista2)
{
    Lista atual1 = lista1;
    Lista atual2 = lista2;

    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1->info != atual2->info)
        {
            return 0; // false
        }

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    return atual1 == NULL && atual2 == NULL;
}

Lista inversao(Lista lst)
{

    Lista nova = cria_lista();
    Lista p;

    for (p = lst; p; p = p->prox)
        nova = insere_ord(nova, p->info);
    return nova;
}

Lista impar(Lista lst)
{
    if (lista_vazia(lst) == 1)
        return 0; // falha
    Lista aux = cria_lista();
    Lista p;
    for (p = lst; p; p = p->prox)
    {
        if (p->info % 2 != 0)
        {
            aux = remove_ord(aux, p->info);
        }
    }
    return aux;
}

int escolhe_lst(void)
{
    int escolha = 0;

    while (escolha < 1 || escolha > 2)
    {
        printf("Em qual lista deseja fazer essa operacao(1 ou 2)? ");
        scanf("%d", &escolha);
    }

    return escolha - 1;
}
