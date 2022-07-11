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

void imprime(Lista lst)
{
    if (lst == NULL)
        return;
    for (int i = 0; i < lst->Fim; i++)
    {
        printf("%d\n", lst->no[i]);
    }
}

int tamanho(Lista lst)
{
    return lst->Fim;
}

int menor(Lista lst)
{
    if (lst == NULL || lista_vazia(lst))
        return 0; // falha
    int menor = lst->no[0];
    for (int i; i < lst->Fim; i++)
    {
        if (lst->no[i] < menor)
        {
            menor = lst->no[i];
        }
    }
    return menor;
}

int remove_impar(Lista lst)
{
    if (lst == NULL || lista_vazia(lst))
        return 0; // falha
    for (int i = 0; i < lst->Fim; i++)
    {
        if (lst->no[i] % 2 != 0) // pega o elemento impar
        {
            lst->no[i] = NULL; // remove o elemento impar
        }
    }
    return 1;
}

Lista ordena(Lista lst)
{
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0; // falha

    Lista lst_aux = cria_lista();

    for (int i = 0; i < lst->Fim; i++)
    {
        if (lista_vazia(lst) == 1 || lst->no[i] >= lst_aux->no[lst_aux->Fim - 1])
        {
            lst_aux->no[lst_aux->Fim] = lst->no[i];
        }
        else
        {
            int j, aux = 0;
            while (lst->no[i] >= lst_aux->no[aux])
                aux++;
            for (int j = lst_aux->Fim; i > aux; i--)
                lst_aux->no[j] = lst->no[j - 1];
            lst_aux->no[aux] = lst->no[i];
        }
        lst_aux->Fim++;
    }
    return lst_aux;
}

Lista concatena(Lista lst_a, Lista lst_b)
{
    if (lst_a == NULL || lista_cheia(lst_a) == 1 || lst_b == NULL || lista_cheia(lst_b) == 1)
        return 0; // falha

    Lista lst_aux;
    lst_aux = cria_lista();

    for (int i = 0; i < lst_a->Fim; i++)
    {
        insere_elem(lst_aux, lst_a->no[i]);
    }

    for (int i = 0; i < lst_b->Fim; i++)
    {
        insere_elem(lst_aux, lst_b->no[i]);
    }

    return lst_aux;
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
