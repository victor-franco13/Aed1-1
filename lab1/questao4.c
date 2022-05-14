#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float imc, massa, altura = 0;
    printf("digite a massa: ");
    scanf("%f", &massa);
    printf("digite a altura: ");
    scanf("%f", &altura);

    imc = massa / pow(altura, 2);

    if (imc < 18.5)
    {
        printf("magreza");
    }
    else if (18.5 <= imc && imc < 25)
    {
        printf("Saudavel");
    }
    else if (25 <= imc && imc < 30)
    {
        printf("sobrepeso");
    }
    else if (30 <= imc && imc < 35)
    {
        printf("obesidade grau 1");
    }
    else if (35 <= imc && imc < 40)
    {
        printf("obesidade grau 2");
    }
    else if (imc >= 40)
    {
        printf("obesidade grau 3");
    }

    return 0;
}
