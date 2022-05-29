#include <stdio.h>
#include <stdlib.h>

struct individuo
{
    int codigo_genetico[10]; // valores binarios aleatorios
    float aptidao_abs;       // pontencial de cada individuo (0.0 <= aptidao <= 10.0)
    float aptidao_relativa;  // deve ser calculada em tempo de execuC'C#o...
};

struct populacao
{
    struct individuo *pop; // um vetor de N individuos
    int tamanho;           // tamanho N da populaC'C#o (N = 100)
};

typedef struct populacao populacao;

int main()
{
    int n;
    double sorteio;
    int i = 0;
    float soma = 0;
    double resultado = 0;

    printf("digite a quantidade de individuos:\n");
    scanf("%d", &n);

    populacao popu;

    popu.tamanho = n;

    popu.pop =
        (struct individuo *)malloc(popu.tamanho * sizeof(struct individuo));

    for (i = 0; i < n; i++)
    {
        popu.pop[i].aptidao_abs = ((float)rand()) / ((float)RAND_MAX) * 10.0;
        soma += popu.pop[i].aptidao_abs;
    }

    for (i = 0; i < n; i++)
    {
        popu.pop[i].aptidao_relativa = popu.pop[i].aptidao_abs / soma;
    }

    sorteio = ((double)rand()) / ((double)RAND_MAX);

    for (i = 0; i < 100000; i++)
    {
        for (i = 0; i < n; i++)
        {
            if (popu.pop[i].aptidao_relativa < sorteio)
            {
                resultado += popu.pop[i].aptidao_relativa;
            }
        }
        printf("resultado eh: %lf\n", resultado);
    }

    // caso colocarmos o  print para o tamanho total de um float veremos um comportamento estranho
    // o valor nem sempre sera exato isso ocorre por motivos de arredondamento
    return 0;
}