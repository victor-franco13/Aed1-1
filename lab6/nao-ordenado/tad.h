typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int elem);
int remove_elem(Lista *lst, int elem);
int consulta_elem(Lista lst, int elem);
int print_lista(Lista lst);
