#include <stdio.h>

int fat(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return n;
    n = n * fat(n - 1);
}

int main(int argc, char const *argv[])
{
    int inicial = 10;
    int final = 15;

    for (size_t i = inicial; i <= final; i++)
    {
        printf("%d!: %d\n", i, fat(i));
    }
    // deu errado pq o valor é maior que o suportado por int
    return 0;
}
