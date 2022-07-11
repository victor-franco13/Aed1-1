#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tad.h"
#include <Windows.h>

int main()
{
    int op, elem, pos, *pt;
    Lista lst;
    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Inserir na lista final\n");
            printf(" 2. Inserir na lista inicio\n");
            printf(" 3. Remove final\n");
            printf(" 4. Insere posicao\n");
            printf(" 5. Remove posicao\n");
            printf(" 6. Sair\n");

            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 6))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while ((op < 1) || (op > 6));

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
            pt = elem;
            remove_inicio(&lst, pt);
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
            pt = elem;
            remove_pos(&lst, pos, pt);
        default:
            printf("Opcao invalida!\n");
            break;
        }
        system("PAUSE");
    } while (op != 6);

    return 0;
}
