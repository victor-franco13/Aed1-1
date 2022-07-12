#include "lista.h"

int main()
{

    int sair = 0;
    int pos;
    int elem;
    Lista listas[3];
    listas[0] = criar_lista();
    listas[1] = criar_lista();
    listas[2] = criar_lista();
    while (sair != 1)
    {
        int opcao = 0;
        printf("1. Imprimir lista            2. Inserir elemento\n");
        printf("3. Remover elemento          4. Tamanho da lista\n");
        printf("5. Remover todos X elemento  6. Remover o maior elemento da lista\n");
        printf("7. Esvaziar lista            8. Inverter lista 1\n");
        printf("9. Inserir multiplos de 3    10. Media \n");
        printf("11. Iguais                   12.Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            int lista, ind, removidos;

//-----------------------------------------------------------------------------------------------------------
        case 1:
            printf("Imprimir lista 1||2||3: \n");
            scanf("%d", &lista);
            ind = lista - 1;

            if (lista_vazia(listas[ind]) == 1)
            {
                printf("A lista esta vazia!!");
            }
            else
            {
                printf("Lista %d:", lista);
                size_t pos = 0;
                while (obtem_valor(&listas[ind], &elem, pos) == 1)
                {
                    printf("[%d]", elem);
                    pos++;
                }
            }
            break;
//-----------------------------------------------------------------------------------------------------------
        case 2:
            printf("Deseja inserir na lista?: \n");
            scanf("%d", &lista);
            ind = lista - 1;
            printf("Digite o elemento: \n");
            scanf(" %d", &elem);
            if (insere_elem(&listas[ind], elem) == 0)
                printf("Falha para inserir\n");
            else
                printf("Sucesso\n");
            break;
//-----------------------------------------------------------------------------------------------------------
        case 3:
            printf("Deseja remover em qual lista? \n");
            scanf(" %d", &lista);
            ind = lista - 1;
            printf("Digite o elemento para remocao \n");
            scanf(" %d", &elem);
            if (remove_elem(&listas[ind], elem) == 0)
                printf("Falha na remocao\n");
            else
                printf("Sucesso\n");

            break;
//-----------------------------------------------------------------------------------------------------------
        case 4:
            printf("Qual lista quer saber o tamanho? \n");
            scanf(" %d", &lista);
            ind = lista - 1;
            int tam = tamanho_lista(&listas[ind]);
            if ((tam) == 0)
                printf("A lista esta vazia\n");
            else
                printf("A lista %d tem %d elementos.\n", lista, tam);
            break;
//-----------------------------------------------------------------------------------------------------------
        case 5:
            printf("Em qual lista deseja remover todos elementos X?\n");
            scanf(" %d", &lista);
            ind = lista - 1;
            printf("Qual elemento deseja remover: \n");
            scanf(" %d", &elem);
            removidos = remover_todos(&listas[ind], elem);
            if (removidos == 0)
                printf("Falha ao remover elemento\n");
            else
                printf("Foram removidos %d elementos\n", removidos);
            break;
//-----------------------------------------------------------------------------------------------------------
        case 6:
            printf("De qual lista o maior elemento deve ser removido? \n");
            scanf(" %d", &lista);
            ind = lista - 1;
            if (remove_maior(&listas[ind]) == 0)
                printf("Erro: Nao foi possivel encontrar o maior elemento\n");
            else
                printf("O maior elemento foi removido\n");
            break;
//-----------------------------------------------------------------------------------------------------------
        case 7:
            printf("Deseja limpar qual lista?\n");
            scanf(" %d", &lista);
            ind = lista - 1;
            if (esvaziar_lista(&listas[ind]) == 0)
                printf("Erro! A lista pode ja estar limpa\n");
            else
                printf("Lista limpa\n");
            break;
//-----------------------------------------------------------------------------------------------------------
        case 8:
            if (inverter_lista(&listas[0], &listas[1]) == 0)
                printf("Falha ao inverter lista\n");
            else
                printf("Sucesso da inversao da lista\n");
            break;
//-----------------------------------------------------------------------------------------------------------
        case 9:
            if (multiplos_tres(&listas[0], &listas[1]) == 0)
                printf("Falha na operacao\n");
            else
                printf("Os multiplos de 3 da lista 1 foram armazenados na lista 2\n");
            break;
//-----------------------------------------------------------------------------------------------------------
        case 10:
            printf("Media de qual lista? \n");
             scanf(" %d", &lista);
            ind = lista - 1;
            if ((tamanho_lista(&listas[ind])) == 0)
                printf("A lista esta vazia.\n");
            else
                printf("A lista %d tem media %.2f\n", lista, media(&listas[ind]));
            break;
//-----------------------------------------------------------------------------------------------------------
        case 11:
            if (iguais(&listas[0], &listas[2]) == 0)
                printf("As listas nao sao iguais\n");
            else
                printf("As listas sao iguais\n");
            break;
//-----------------------------------------------------------------------------------------------------------
        case 12:
            sair = 1;
            break;
//-----------------------------------------------------------------------------------------------------------
        default:
            printf("ERRO");
            break;
        }
    };

    return 0;
}
