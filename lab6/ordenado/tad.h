typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int consulta_elem(Lista lst, int elem);
int print_lista(Lista lst);