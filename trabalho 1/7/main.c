#include "tad.h"

void sorteia_inicio(Lista *lst)
{
    if (lista_vazia(*lst))
    {
        printf("\nNao é possível sortear de uma lista vazia!");
        return;
    }
    char nome[50];
    int pos, tam = lista_tam(*lst);
    srand(time(NULL));
    printf("\nSoldados mortos...");
    while (tam > 1)
    {
        pos = rand() % tam;
        printf("\nNumero sorteado(%d)", pos);
        remove_pos(lst, pos, nome);
        printf("\nSoldado %s morreu", nome);
        tam--;
    }
    if (obtem_valor_elem(*lst, 0, nome))
        printf("\nSoldado %s foi o unico sobrevivente!", nome);
    else
        printf("\nErro ao obter nome!");
}

void sorteia_aleatorio(Lista *lst)
{
    if (lista_vazia(*lst))
    {
        printf("\nNao é possível sortear de uma lista vazia!");
        return;
    }
    char nome[50];
    int pos, tam = lista_tam(*lst);
    srand(time(NULL));
    pos = rand() % tam;
    printf("\nO numero sorteado para inicio foi %d", pos);
    if (!avanca_lista(lst, pos))
    {
        printf("Erro ao avancar a lista");
        return;
    }
    if (obtem_valor_elem(*lst, 0, nome))
        printf("\nSoldado %s foi sorteado!", nome);
    else
    {
        printf("\nErro ao obter nome!");
        return;
    }
    printf("\nSoldados mortos...");
    while (tam > 1)
    {
        pos = rand() % tam;
        printf("\nNumero sorteado(%d)", pos);
        remove_pos(lst, pos, nome);
        printf("\nSoldado %s morreu", nome);
        tam--;
    }
    if (obtem_valor_elem(*lst, 0, nome))
        printf("\nSoldado %s foi o unico sobrevivente!", nome);
    else
        printf("\nErro ao obter nome!");
}

void sorteia_nome(Lista *lst, char *nome)
{
    if (lista_vazia(*lst))
    {
        printf("\nNao é possível sortear de uma lista vazia!");
        return;
    }
    if (!avanca_lista_nome(lst, nome))
    {
        printf("\nNao foi possivel sortear a partir do soldado %s!", nome);
        return;
    }
    int pos, tam = lista_tam(*lst);
    srand(time(NULL));
    printf("\nSoldados mortos...");
    while (tam > 1)
    {
        pos = rand() % tam;
        printf("\nNumero sorteado(%d)", pos);
        remove_pos(lst, pos, nome);
        printf("\nSoldado %s morreu", nome);
        tam--;
    }
    if (obtem_valor_elem(*lst, 0, nome))
        printf("\nSoldado %s foi o unico sobrevivente!", nome);
    else
        printf("\nErro ao obter nome!");
}

int main()
{
    int i, qnt, escolha, sortedNum;
    Lista soldados;
    char **nomes, name[50];
    soldados = cria_lista();
    do
    {
        printf("Informe a quantidade de soldados: ");
        scanf("%d", &qnt);
    } while (qnt < 1);
    for (i = 0; i < qnt; i++)
    {
        printf("Digite o nome do %do soldado: ", i + 1);
        setbuf(stdin, NULL);
        scanf("%[^\n]", name);
        if (!insere_nome(&soldados, name))
        {
            printf("\nErro na alocacao!!");
            exit(1);
        }
    }
    printf("\n-Problema de Josephus-\n");
    printf("(1) Iniciar contagem a partir do inicio\n");
    printf("(2) Iniciar contagem a partir de uma posicao sorteada aleatoriamente\n");
    printf("(3) Iniciar contagem a partir do nome de um soldado \nDigite a sua escolha: ");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        sorteia_inicio(&soldados);
        break;
    case 2:
        sorteia_aleatorio(&soldados);
        break;
    case 3:
        printf("Digite o nome do soldado que deve iniciar: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", name);
        sorteia_nome(&soldados, name);
        break;
    default:
        printf("Saindo do programa...");
    }
    return 0;
}