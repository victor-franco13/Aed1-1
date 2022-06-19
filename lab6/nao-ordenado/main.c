#include <stdio.h>
#include "tad.h"

int main(int argc, char const *argv[])
{
    int nums[] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
    Lista lst = cria_lista();
    printf("--------------------------------\n");

    print_lista(lst);

    for (int i = 0; i < 12; i++)
    {
        insere_elem(&lst, nums[i]);
    }
    printf("--------------------------------\n");
    print_lista(lst);
    remove_elem(&lst, 8);
    printf("--------------------------------\n");

    print_lista(lst);
    lst = cria_lista();
    printf("--------------------------------\n");

    print_lista(lst);
    return 0;
}
