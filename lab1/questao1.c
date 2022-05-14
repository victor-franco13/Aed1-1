#include <stdio.h>

int main(int argc, char const *argv[])
{
    // exercicio 1
    int Jogador[3];
    float aux;
    float premio = 0;
    float premioTotal[3];

    for (size_t i = 0; i < 3; i++)
    {
        printf("bolao jogador %d:\n", i);
        scanf("%d", &Jogador[i]);
        aux += Jogador[i];
    };

    printf("digite o valor do premio:\n");
    scanf("%f", &premio);

    for (size_t i = 0; i < 3; i++)
    {
        premioTotal[i] = (Jogador[i] / aux) * premio;
        printf("Jogador %d recebera R$: %.1f \n", i, premioTotal[i]);
    }
    
    return 0;
}
