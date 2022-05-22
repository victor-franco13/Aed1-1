#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (size_t i = 10; i >= 0; --i)
    {
        printf("%d\n", *(a + i));
    }

    return 0;
}
