#include <stdio.h>
#include <stdlib.h>

struct cordenadas
{
    int *x;
    int *y;
};

int main(int argc, char const *argv[])
{

    struct cordenadas *a;
    int n;

    printf("quantos valores serao lidos: ");
    scanf("%d", &n);

    a = (struct cordenadas *)malloc(n * sizeof(struct cordenadas));

    for (int i = 0; i < n; i++)
    {
        printf("valor de x: ");
        scanf("%d", &a[i].x);
        printf("valor de y: ");
        scanf("%d", &a[i].y);
    }

    for (int i = 0; i < n; i++)
    {
        printf("x: %d\n", a[i].x);
        printf("y: %d\n", a[i].y);
    }
    return 0;
}
