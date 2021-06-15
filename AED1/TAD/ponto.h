typedef struct ponto Ponto;

struct ponto *Cria_pto(double x, double y);
void Libera_pto(struct ponto **p);
double Distancia_pto(struct ponto *p1, struct ponto *p2);