#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int n = 5;
    int valor[5];
    int media = 0;
    float desvio = 0;
    float soma = 0;
    float div = 0;

    for (size_t i = 0; i < n; i++)
    {
        printf("Digite um valor %d:\n", i);
        scanf("%d", &valor[i]);
        soma += valor[i];
    }

    media = soma / n;

    soma = 0;

    for (size_t i = 0; i < n; i++)
    {
        soma += pow(valor[i] - media, 2) * 1 / (n - 1);
    }

    desvio = sqrt(soma);

    printf("A media dos valores digitados eh: %d\n e o desvio-pradao eh: %f\n", media, desvio);

    return 0;
}
