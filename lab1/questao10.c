#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0, j = 0;
    int mat[6][6];

    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; i < 6; j++)
        {
            printf("%d", mat[i][j]);
        }
    }

    return 0;
}
