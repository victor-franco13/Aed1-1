#include "lista.h"

struct no
{
    int info;
    Lista prox;
    Lista ant;
};

Lista criar_lista()//cria a lista
{
    return NULL;
}

int lista_vazia(Lista lista)
{
    if (lista == NULL)//verifica se a lista ta vazia
        return 1;
    return 0;
}

int insere_elem(Lista *lista, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;

    N->info = elem;
    if ((*lista) == NULL)
    {
        N->prox = NULL;
        N->ant = NULL;
        *lista = N;
        return 1;
    }
    else
    {
        Lista ante, atual = *lista;
        while (atual != NULL && atual->info < elem)
        {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *lista)
        {
            N->ant = NULL;
            (*lista)->ant = N;
            N->prox = (*lista);
            *lista = N;
        }
        else
        {
            N->prox = ante->prox;
            N->ant = ante;
            ante->prox = N;
            if (atual != NULL)
                atual->ant = N;
        }
        return 1;
    }

    if (lista_vazia(*lista) == 0)
        (*lista)->ant = N;

    (*lista) = N;

    return 1;
}

int remove_elem(Lista *lista, int elem)
{
    if (lista_vazia(*lista) == 1)
        return 0;
    Lista aux = (*lista);

    while (aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if (aux->info != elem)
        return 0;

    if (aux->prox != NULL)
        aux->prox->ant = aux->ant;

    if (aux->ant != NULL)
        aux->ant->prox = aux->prox;

    if (aux == (*lista))
        (*lista) = aux->prox;

    free(aux);
    return 1;
}


int obtem_valor(Lista *lista, int *elem, size_t pos)
{
    if (pos < 0 || lista_vazia(*lista) == 1)
        return 0;
    size_t i = 0;
    Lista aux = (*lista);

    while (i < pos && aux->prox != NULL)
    {
        aux = aux->prox;
        i++;
    }

    if (i != pos)
        return 0;

    *elem = aux->info;
    return 1;
}

int tamanho_lista(Lista *lista)
{
    int tam = 0;
    if (lista_vazia(*lista) == 1)
        return tam;
    Lista aux = (*lista);
    tam = 1;
    while ((aux)->prox != NULL)
    {
        (aux) = (aux)->prox;
        tam++;
    }
    return tam;
}

float media(Lista *lista)
{
    int total = 0, tam = 0;
    if (lista_vazia(*lista) == 1)
        return total;
    Lista aux = (*lista);
    tam = 1;
    while ((aux)->prox != NULL)
    {
        total += aux->info;
        (aux) = (aux)->prox;
        tam++;
    }
    return (total / tam);
}

int remover_todos(Lista *lista, int elem)
{
    if (lista_vazia(*lista))
        return 0;

    int removido = 0;

    while (remove_elem(&(*lista), elem) == 1)
        removido++;

    return removido;
}

int remove_maior(Lista *lista)
{
    if (lista_vazia(*lista) == 1)
        return 0;
    Lista aux = (*lista);
    int maior;

    while (aux->prox != NULL)
    {
        if (aux->ant == NULL)
            maior = aux->info;
        else if (aux->info > maior)
            maior = aux->info;
        aux = aux->prox;
    }

    remove_elem(&(*lista), maior);

    return 1;
}

int esvaziar_lista(Lista *lista)
{
    if (lista_vazia(*lista) == 1)
        return 0;

    while ((*lista)->prox != NULL)
    {
        Lista aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
    free(*lista);
    *lista = NULL;
    return 1;
}

int inverter_lista(Lista *lista, Lista *_inverso)
{
    if (lista_vazia(*lista) == 1)
        return 0;

    Lista aux = (*lista);
    while (aux != NULL)
    {
        if (insere_elem(&(*_inverso), aux->info) == 0)
            return 0;
        aux = aux->prox;
    }
    return 1;
}


int multiplos_tres(Lista *lista, Lista *_multiplos)
{
    if (lista_vazia(*lista) == 1)
        return 0;
    if (lista_vazia(*_multiplos) == 0)
    {
        if (esvaziar_lista(&(*_multiplos)) == 0)
            return 0;
    }

    Lista aux = (*lista);
    while (aux != NULL)
    {
        if (aux->info % 3 == 0)
        {
            if (insere_elem(&(*_multiplos), aux->info) == 0)
                return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

int iguais(Lista *lista, Lista *lista2)
{
    if (lista_vazia(*lista) == 1)
        return 0;
    if (lista_vazia(*lista2) == 1)
        return 0;

    Lista aux = (*lista);
    Lista aux2 = (*lista2);

    while((aux)->prox != NULL){
        if(aux->info != aux2->info)
            return 0;
    }

    return 1;
}
