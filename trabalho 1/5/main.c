#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tad.h"

int main()
{
    int op, elem, pos;
    Lista lst;
    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Inserir na lista\n");
            printf(" 2. Menor elemento da lista\n");
            printf(" 3. Tamanho da lista\n");
            printf(" 4. Excluir elemento da lista\n");
            printf(" 5. Excluir elementos impares\n");
            printf(" 6. Concatena lista\n");
            printf(" 7. inveter lista\n");
            printf(" 8. imprimir lista\n");
            printf(" 9. Sair\n");

            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 9))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while ((op < 1) || (op > 12));

        switch (op)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &elem);
            insere_final(&lst, elem);

            break;
        case 2:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &elem);
            insere_inicio(&lst, elem);

            break;
        case 3:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &elem);
            remove_inicio(&lst, elem);
            break;
        case 4:
            printf("Digite o valor a ser inserido e a posicao: ");
            scanf("%d", &elem);
            scanf("%d", &pos);
            insere_pos(&lst, pos, elem);
            break;
        case 5:
            printf("Digite o valor a ser inserido e a posicao: ");
            scanf("%d", &elem);
            scanf("%d", &pos);
            remove_pos(&lst, pos, elem);
        case 6:
            printf("e igual? %d", elem);
            break;
        case 7:
            imprime(lst);
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 9);

    return 0;
}
