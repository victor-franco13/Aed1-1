#include <stdio.h>

float mult(float x, float y)
{
    return x * y;
}

int main(int argc, char const *argv[])
{
    float x, y;
    printf("valor de x: ");
    scanf("%f", &x);
    printf("valor de y: ");
    scanf("%f", &y);
    printf("area: %f\n", mult(x, y));

    return 0;
}
