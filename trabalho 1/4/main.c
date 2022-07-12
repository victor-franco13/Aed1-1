#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define tam 3

int main(int argc, char const *argv[]) {
  int option = 1,
        tmp = 0,
        tmp2 = 0,
        qnt_lista = 0;
  char letra;
  Lista lst[tam];
  int lst_ocupados[tam] = {0};
  while (1){
    printf("1: Criar lista lst\n");
    printf("2: Insere na lista\n");
    printf("3: Remove primeira ocorrencia\n");
    printf("4: Remove segundo a posicao\n");
    printf("5: Imprimir lista\n");
    printf("6: Limpar uma lista\n");
    printf("7: Tamanho e uma lista\n");
    printf("8: Ver se as listas sao iguais\n");
    printf("9: Exibir maior elemento de uma lista\n");
    printf("10: Intercalar duas listas em uma terceira\n");
    printf("11: Sair\n");
    scanf("%d", &option);
    switch (option) {
    case 1:
      if (qnt_lista < tam){
        int i;
        for (i = 0; i < tam; i++){
          if (lst_ocupados[i] == 0)
            break;
        }

        lst[i] = cria_lista();
        printf("Lista %d criada com sucesso\n", i);
        lst_ocupados[i]++;
        qnt_lista++;
      }
      else printf("Quantidade maximas de listas criadas tente outro comando\n");

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 2:

      printf("Em qual lista deseja inserir");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      printf("Insira a letra que deseja inserir na lista %d: ", tmp);
      setbuf(stdin, NULL);
      scanf("%c", &letra);

      if (insere_ord(&lst[tmp], letra)) printf("Sucesso");
      else printf("Erro");

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 3:
      printf("Em qual lista deseja remover");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      printf("Insira o numero que deseja remover: ");
      setbuf(stdin, NULL);
      scanf("%c", &letra);
      remove_ord(&lst[tmp], letra);

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 4:
      printf("Em qual lista deseja remover");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);

      printf("Insira a posicao que deseja remover: ");
      scanf("%d", &tmp2);
      if (remove_pos(&lst[tmp], tmp2, &letra))
        printf("%c foi removido\n", letra);
      else
        printf("Erro ao remover na posicao %d\n", tmp2);

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 5:
      printf("Qual lista deseja imprimir");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      size_t i = 0;
      while (obtem_valor_elem(&(lst[tmp]), i, &letra)){
        printf("%c ", letra);
        i++;
      }
      printf("\n");

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 6:
      printf("Qual lista deseja limpar");
      for (size_t i = 0; i < qnt_lista; i++)
      {
        if (lst_ocupados[i] == 1)
          printf(" %ld", i);
      }
      printf(": ");
      scanf("%d", &tmp);
      esvazia_lista(&lst[tmp]);
      lst_ocupados[tmp]--;

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 7:
      printf("Qual lista deseja ver o tamanho");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);

      printf(": ");
      scanf("%d", &tmp);
      printf("Tamanho da lista %d: %d", tmp, obtem_tamanho(&lst[tmp]));

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 8:
      printf("Quais lista vai comparar");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d %d", &tmp, &tmp2);
      if (listas_iguais(&lst[tmp], &lst[tmp2]))
        printf("Listas iguais\n");
      else
        printf("Listas diferentes\n");

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 9:
      printf("Qual lista deseja ver o tamanho");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      if (maior_elem(&lst[tmp], &letra))
        printf("Maior elemento %c\n", letra);
      else
        printf("Nao consegui achar o maior elemento\n");

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 10:
      printf("Quais lista serao intercaladas");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");

      scanf("%d %d", &tmp, &tmp2);
      int tmp3 = 3;
      printf("Qual lista recebera a lista resultante: ");
      scanf("%d", &tmp3);
      esvazia_lista(&lst[tmp3]);

      if (intercalar(&lst[tmp], &lst[tmp2], &lst[tmp3]))
        printf("Listas intercaladas com sucesso\n");
      else
        printf("Erro\n");

      break;
//----------------------------------------------------------------------------------------------------------------------
    case 11:
      exit(1);
      break;
//----------------------------------------------------------------------------------------------------------------------
    default:
      printf("Opcao invalida\n");
      break;
    }
  }
  return 0;
}
