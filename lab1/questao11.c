#include <stdio.h>
#include <string.h>

struct agenda
{
    char nome[50];
    char email[50];
    char cidade[50];
    char estado[3];
    int cep;
    int ddd;
    int telefone;
    int dia;
    int mes;
    int ano;
    char observacao[50];
};

int main(int argc, char const *argv[])
{
    int aux = 100;
    struct agenda agenda[100];
    char first_name[50];
    int aux_mes = 0;
    int aux_dia = 0;
    int entrada = 0;

    printf("1 cadastrar:\n");
    printf("2 Procura o primeiro nome:\n");
    printf("3 Procura por mes de aniversario:\n");
    printf("4 Procura por dia de aniversario e mes:\n");
    printf("5 imprime nome telefone e email:\n");
    printf("6 imprime todos os dados:\n");
    printf("7 remove os dados:\n");
    printf("0 sair:\n");
    scanf("%d", &entrada);

    while (entrada != 0)
    {
        switch (entrada)
        {
        case 1:
            for (size_t i = 0; i < aux; i++)
            {
                printf("Digite o nome: ");
                scanf("%s", agenda[i].nome);
                printf("Digite o email: ");
                scanf("%s", agenda[i].email);
                printf("Digite a cidade: ");
                scanf("%s", agenda[i].cidade);
                printf("Digite o estado: ");
                scanf("%s", agenda[i].estado);
                printf("Digite o cep: ");
                scanf("%d", &agenda[i].cep);
                printf("Digite o ddd: ");
                scanf("%d", &agenda[i].ddd);
                printf("Digite o telefone: ");
                scanf("%d", &agenda[i].telefone);
                printf("Digite o dia: ");
                scanf("%d", &agenda[i].dia);
                printf("Digite o mes: ");
                scanf("%d", &agenda[i].mes);
                printf("Digite o ano: ");
                scanf("%d", &agenda[i].ano);
                printf("Digite a observacao: ");
                scanf("%s", agenda[i].observacao);
            }

            break;
        case 2:
            for (size_t i = 0; i < aux; i++)
            {
                if (agenda[i].nome == first_name)
                {
                    printf("Nome: %s\n", agenda[i].nome);
                    printf("Email: %s\n", agenda[i].email);
                    printf("Endereco: %s %s %d\n", agenda[i].cidade, agenda[i].estado, agenda[i].cep);
                    printf("Telefone: %d %d\n", agenda[i].ddd, agenda[i].telefone);
                    printf("Data aniversario: %d %d %d\n", agenda[i].dia, agenda[i].mes, agenda[i].ano);
                    printf("Observacao :%s\n", agenda[i].observacao);
                }
            }
            break;
        case 3:
            for (size_t i = 0; i < aux; i++)
            {
                if (agenda[i].mes == aux_mes)
                {
                    {
                        printf("Nome: %s\n", agenda[i].nome);
                    }
                }
            }
            break;
        case 4:
            for (size_t i = 0; i < aux; i++)
            {
                if (agenda[i].mes == aux_mes && agenda[i].dia == aux_dia)
                {
                    printf("Nome: %s\n", agenda[i].nome);
                    printf("Email: %s\n", agenda[i].email);
                    printf("Endereco: %s %s %d\n", agenda[i].cidade, agenda[i].estado, agenda[i].cep);
                    printf("Telefone: %d %d\n", agenda[i].ddd, agenda[i].telefone);
                    printf("Data aniversario: %d %d %d\n", agenda[i].dia, agenda[i].mes, agenda[i].ano);
                    printf("Observacao :%s\n", agenda[i].observacao);
                }
            }
            break;
        case 5:
            for (size_t i = 0; i < aux; i++)
            {
                printf("Nome: %s\n", agenda[i].nome);
                printf("Email: %s\n", agenda[i].email);
                printf("Telefone: %d %d\n", agenda[i].ddd, agenda[i].telefone);
            }
            break;
        case 6:
            for (size_t i = 0; i < aux; i++)
            {
                printf("Nome: %s\n", agenda[i].nome);
                printf("Email: %s\n", agenda[i].email);
                printf("Endereco: %s %s %d\n", agenda[i].cidade, agenda[i].estado, agenda[i].cep);
                printf("Telefone: %d %d\n", agenda[i].ddd, agenda[i].telefone);
                printf("Data aniversario: %d %d %d\n", agenda[i].dia, agenda[i].mes, agenda[i].ano);
                printf("Observacao :%s\n", agenda[i].observacao);
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
