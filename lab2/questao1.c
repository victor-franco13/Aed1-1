#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 40; // cria uma variável do tipo inteiro, chamada a, e inicializa
                // com valor 40;
    int *p;     // cria uma variável do tipo ponteiro para inteiro, chamada p, e o
                // conteúdo inicial é lixo;
    p = &a;     // faz p receber o endereço de a. Dizemos que p aponta para a

    printf("%d\n", a); // imprime o valor de a, que é 40;

    printf("%d\n", *p); // imprime o valor de a, que é 40;

    scanf("%d", p); // lê um valor inteiro do teclado e atribui a a;
    printf("%d\n", a);

    return 0;
}
