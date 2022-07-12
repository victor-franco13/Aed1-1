#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 10

typedef struct lista *Lista;

void libera(Lista list);

Lista cria();

int cheia(Lista list);

int insere_ordenada(Lista lista, int elem);

int remove_impares(Lista list);

int menor(Lista list);

Lista ordenaLista(Lista lista);

int tamanho(Lista list);

Lista concatenar(Lista l1, Lista l2);

int posicao(Lista list, int pos);
