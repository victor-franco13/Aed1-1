#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *a;
    int n = 5;
    int i = 0;

    a = (int *)malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &a[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    free(a);
    a = NULL;

    return 0;
}
