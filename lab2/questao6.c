#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *a;
    int n;
    int c = 0;
    int d = 0;

    printf("quantos valores serao lidos: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &a[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            c++;
        }
        else
        {
            d++;
        }
    }

    printf("Sao pares:%d dos %d inteiros lidos\n", c, n);
    printf("Sao impares:%d dos %d inteiros lidos\n", d, n);

    return 0;
}
