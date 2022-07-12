

#include "lista.h"

struct lista{
    int lista[max];
    int fim;
};

void libera(Lista list) {  free(list); } //libera a memoria alocada para a lista

Lista cria(){
    Lista resultado = (Lista)malloc(sizeof(struct lista)); //inicializa a lista

    if (!resultado) return NULL;

    resultado->fim = 0;

    return resultado;
}

int cheia(Lista list){ return list->fim == max; }

int insere_ordenada(Lista lista, int elem){//como eh uma lista ordenada, todo insere precisa ser ordenado.
    if (lista == NULL || cheia(lista) == 1) return 0;
    int i = 0, k;

    while (i < lista->fim && lista->lista[i] < elem)
        i++;

    for (k = lista->fim - 1; k >= i; k--)
        lista->lista[k + 1] = lista->lista[k];

    lista->lista[i] = elem;
    lista->fim++;
    return 1;
}

int remove_impares(Lista list){
    if (list->fim == 0) //caso a lista esteja vazia, nao ha como remover
        return 0;

    for (int i = list->fim - 1; i > 0; i--){ //passa por toda a lista
        if ( list->lista[i] & 1 ){   //se o numero for impar, remove (bitwise operation)
            for (int j = i; j < list->fim; j++){ //Remove fazendo shift
                if (j + 1 != max)   list->lista[j] = list->lista[j + 1];
            }
            list->fim--; // diminui o tamanho da lista
        }
    }
    return 1;
}

int menor(Lista list){
    int menor = list->lista[0];
    for (int i = 0; i < list->fim; i++){ //percorre a lista em busca do menor numero
        if (list->lista[i] < menor)
            menor = list->lista[i];
    }
    return menor;
}

Lista concatenar(Lista l1, Lista l2){
    Lista resultado = cria();

    if (resultado == NULL)
        return NULL;

    for (int i = 0; i < l1->fim; i++){
        resultado->lista[i] = l1->lista[i];
        resultado->fim++;
    }

    for (int i = 0; i < l2->fim && (!cheia(resultado)); i++){
        resultado->lista[resultado->fim] = l2->lista[i];
        resultado->fim++;
    }

    return resultado;
}

int tamanho(Lista list){ return list->fim; }


Lista ordenaLista(Lista lista){
    Lista resultado = (Lista)malloc(sizeof(struct lista));

    for (int i = 0; i < lista->fim; i++)
        insere_ordenada(resultado, lista->lista[i]);

    return resultado;
}
 int posicao(Lista list, int pos)
{
  if (pos < 0 || pos >= max){
    return 0;
  }
  if(pos >= list->fim){
    return 1;
  }

  return list->lista[pos];
}
