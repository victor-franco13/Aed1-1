#include <stdio.h>

int main(int argc, char const *argv[])
{
    char nome[] = "Jose Augusto";
    char *p;
    p = nome;
    for (size_t i = 0; i < sizeof(nome); i++)
    {
        printf("%c", *(p + i));
    }

    return 0;
}
