#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tad.h"
#include <Windows.h>

int main()
{
    int op, elem, es;
    float felem;
    Lista lst[3];
    lst[0] = cria_lista();
    lst[1] = cria_lista();
    lst[2] = cria_lista();

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
            es = escolhe_lst();
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &elem);
            insere_elem(&lst[es], elem);

            break;
        case 2:
            es = escolhe_lst();

            if (tamanho(lst[es]))
            {
                elem = menor(lst[es]);

                printf("Menor valor na lista: %d\n", elem);
            }
            else
                printf("Lista vazia!\n");

            break;
        case 3:
            es = escolhe_lst();
            elem = tamanho(&lst[es]);

            printf("Tamanho da lista: %d\n", elem);

            break;
        case 4:
            es = escolhe_lst();
            printf("Digite o valor a ser removido: ");
            scanf("%d", &elem);
            remove_elem(&lst[es], elem);
            break;
        case 5:
            es = escolhe_lst();
            felem = media(&lst[es]);
            printf("media da lista: %f\n", felem);
            break;
        case 6:
            elem = comparar(lst[1], lst[2]);
            printf("e igual? %d", elem);
            break;
        case 7:
            es = escolhe_lst();
            lst[3] = inversao(lst[es]);
            imprime(lst[es]);
            break;
        case 8:
            es = escolhe_lst();

            imprime(lst[es]);
            break;
        case 9:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        system("PAUSE");
    } while (op != 9);

    return 0;
}
