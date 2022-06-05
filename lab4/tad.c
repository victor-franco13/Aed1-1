#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad.h"

struct ponto
{
    int x;
    int y;
};

Ponto *gera_pto()
{
    Ponto *p;
    p = (Ponto *)malloc(sizeof(Ponto));
    return p;
}

int set_pto(int x, int y, Ponto *pto)
{

    if (pto == NULL)
    {
        return 0;
    }

    pto->x = x;
    pto->y = y;
    return 1;
}

int get_pto(Ponto *pto, int *x, int *y)
{

    if (pto == NULL)
    {
        return 0;
    }

    *x = pto->x;
    *y = pto->y;

    return 1;
}

float distancia_pto(Ponto *pto1, Ponto *pto2)
{

    float resultado;

    if (pto1 == NULL || pto2 == NULL)
    {
        return 0;
    }

    resultado = sqrt(pow((pto2->x - pto1->x), 2) + pow((pto2->y - pto1->y), 2));
    return resultado;
}

void libera_pto(Ponto **pto)
{
    free(*pto);
    *pto = NULL;
}