typedef struct no *Lista;
Lista cria_lista();
int insere_elem(Lista lst, int elem);
int remove_elem(Lista *lst, int elem);
int consulta_elem(Lista lst, int elem);
int print_lista(Lista lst);