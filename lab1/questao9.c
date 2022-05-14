#include <stdio.h>

int main(int argc, char const *argv[])
{
    char nome[50];
    printf("Digite seu nome:\n");
    fgets(nome, 49, stdin);

    for (size_t i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] >= 97 && nome[i] <= 122)
        {
            nome[i] -= 32;
        }
    }

    printf("%s", nome);

    return 0;
}
