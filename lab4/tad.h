typedef struct ponto Ponto;

Ponto *gera_pto();
int set_pto(int x, int y, Ponto *pto);
int get_pto(Ponto *pto, int *x, int *y);
float distancia_pto(Ponto *pto1, Ponto *pto2);
void libera_pto(Ponto **pto)