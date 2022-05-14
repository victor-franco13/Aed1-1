#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // exercicio 2

    int x, y = 0;
    int ox,oy = 0;
    float distancia = 0;

    printf("Entre com a coordenada x:\n");
    scanf("%d", &x);
    printf("Entre com a coordenada xy:\n");
    scanf("%d", &y);

    distancia = sqrt(pow((ox - x),2) + pow((oy - y),2));

    printf("A distancia e: %.2f\n", distancia);


    return 0;
}
