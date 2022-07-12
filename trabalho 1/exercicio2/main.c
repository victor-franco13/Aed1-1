#include "lista.h"

void imprime(Lista list){
  printf("----------------------------------------\n");

  for (int i = 0; i < tamanho(list); i++)
    printf("[%d] = %d\n", i, posicao(list, i));

  printf("----------------------------------------\n");
}

int escolhe_lista(){
  int escolha = 0;

  printf("Selecione uma lista 1 ou 2?: ");
  scanf("%d", &escolha);

  return escolha - 1;
}

int main(){
  int opcao = 0,
      value = 0,
      escolha;

  Lista list[3];
  list[0] = cria(); list[1] = cria(); list[2] = cria();

  if (list[0] == NULL || list[1] == NULL || list[2] == NULL){ //caso ocorra algum erro na alocacao
    printf("Falha ao criar\n"); //o programa notifica
    exit(0);//e termina
  }

  while (opcao != 11) {
    printf("Escolha uma opcao:\n");
    printf("1. Inserir ordenado\n");
    printf("2. Remover impares\n");
    printf("3. Menor\n");
    printf("4. Ordenar lista\n");
    printf("5. Tamanho\n");
    printf("6. Concatenar\n");
    printf("7. Imprime lista\n");
    printf("8. Sair\n");
    printf("Opcao: ");
    setbuf(stdin, NULL);
    scanf("%d", &opcao);

    switch (opcao){
      case 1:
        escolha = escolhe_lista();

        printf("Digite o valor a ser inserido: ");
        scanf("%d", &value);
        insere_ordenada(list[escolha], value);

        break;
//-----------------------------------------------------------------------------------------------------------
      case 2:

        escolha = escolhe_lista();

        if (!remove_impares(list[escolha]))
          printf("Lista vazia!\n");
        else
          break;
//-----------------------------------------------------------------------------------------------------------
      case 3:

        escolha = escolhe_lista();

        if (tamanho(list[escolha])) {
          value = menor(list[escolha]);
          printf("Menor valor na lista: %d\n", value);
        }
        else
          printf("Lista vazia!\n");

      break;
//-----------------------------------------------------------------------------------------------------------
    case 4:

      escolha = escolhe_lista();
      imprime(ordenaLista(list[escolha]));
      break;
//-----------------------------------------------------------------------------------------------------------
    case 5:

      escolha = escolhe_lista();
      value = tamanho(list[escolha]);

      printf("Tamanho da lista: %d\n", value);
//-----------------------------------------------------------------------------------------------------------
    case 6:
      printf("Escolha qual lista sera a base\n");

      escolha = escolhe_lista();
      list[2] = concatenar(list[escolha], list[!escolha]);

      printf("Listas concatenadas:\n");
      imprime(list[2]);
      list[2] = NULL;

      break;
//-----------------------------------------------------------------------------------------------------------
      case 7:

      escolha = escolhe_lista();
      imprime(list[escolha]);
      break;
//-----------------------------------------------------------------------------------------------------------
    case 8:

      printf("Bye :)\n");
      return 0;

      break;
//-----------------------------------------------------------------------------------------------------------

    default:

      printf("Opcao invalida!\n");
      break;
    }
  };
}

