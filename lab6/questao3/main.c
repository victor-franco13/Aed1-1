#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main(int argc, char const *argv[])
{
    int o;
    Lista lst = cria_lista();
    while (o != 5)
    {
        printf("\n\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Consultar\n");
        printf("4 - Imprimir\n");
        printf("5 - Sair\n");
        printf("\n");

        scanf("%d", &o);

        switch (o)
        {
        case 1:
            int volume;
            float preco;
            char nome[20];
            printf("Nome: ");
            scanf("%s", nome);
            printf("Preco: ");
            scanf("%f", &preco);
            printf("Volume: ");
            scanf("%d", &volume);
            insere_elem(&lst, nome, preco, volume);
            break;
        case 2:
            char nome[20];
            printf("Nome: ");
            scanf("%s", nome);
            remove_elem(&lst, nome);
            break;
        case 3:
            char nome[20];
            printf("Nome: ");
            scanf("%s", nome);
            consulta_elem(lst, nome);
            break;
        case 4:
            print_lista(lst);
            break;
        }
    }

    return 0;
}
