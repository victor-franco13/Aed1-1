#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int c = 0;
    int i = 0;
    int j = 0;

    printf("digite o inteiro:\n ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            c++;
            printf("%d ", c);
        }
        printf("\n");
    }

    return 0;
}
