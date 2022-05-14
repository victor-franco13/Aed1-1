#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // exercicio 3

    int bin[4];
    float aux = 0;

    for (int i = 0; i < 4; i++)
    {
        printf("digite o %d bit: ", i);
        scanf("%d", &bin[i]);
    };
    printf("o numero eh: ");
    for (int i = 0; i < 4; i++)
    {
        aux += pow(2.0,i) * bin[i];
        // printf("%f ", pow(2.0,i) * bin[i]);
    }
        printf("%.0f", aux);
    
    return 0;
}
