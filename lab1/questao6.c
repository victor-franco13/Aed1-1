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
    int inicial = 1;
    int final = 10;

    for (size_t i = inicial; i <= final; i++)
    {
        printf("%d!: %d\n", i, fat(i));
    }
    
    return 0;
}
