#include <stdio.h>
#include <stdlib.h>

typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista lista);
int insere_elem(Lista *lista, int elem);
int remove_elem(Lista *lista, int elem);
int obtem_valor(Lista *lista, int *elem, size_t pos);
int tamanho_lista(Lista *lista);
float media(Lista *lista);
int remover_todos(Lista *lista, int elem);
int remove_maior(Lista *lista);
int esvaziar_lista(Lista *lista);
int multiplos_tres(Lista *lista, Lista *_multiplos);
int iguais(Lista *lista, Lista *lista2);
