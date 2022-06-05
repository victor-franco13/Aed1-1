#include <stdio.h>
#include "tad.h"

int main()
{
    Ponto *p1, *p2;
    int x, y;
    float resultado = 0;
    p1 = gera_pto();
    p2 = gera_pto();

    if (p1 == NULL || p2 == NULL)
    {
        printf("Nao foi possivel criar os pontos\n");
        return -1;
    }

    printf("digite os pontos x e y:\n");
    scanf("%d", &x);
    scanf("%d", &y);

    if (set_pto(x, y, p1) == 0)
    {
        printf("Nao foi possivel inserir os pontos\n");
        return -1;
    }

    printf("digite os pontos x e y:\n");
    scanf("%d", &x);
    scanf("%d", &y);

    if (set_pto(x, y, p2) == 0)
    {
        printf("Nao foi possivel inserir os pontos\n");
        return -1;
    }

    resultado = distancia_pto(p1, p2);

    printf("a distancia eh:%f\n", resultado);

    libera_pto(&p1);
    libera_pto(&p2);

    return 0;
}