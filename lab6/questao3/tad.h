typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, char nome[], float preco, int volume);
int remove_elem(Lista *lst, char nome[]);
int consulta_elem(Lista lst, char nome[]);
int print_lista(Lista lst);