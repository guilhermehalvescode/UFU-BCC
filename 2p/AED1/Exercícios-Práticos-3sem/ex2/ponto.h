typedef struct ponto Ponto;

struct ponto *Cria_pto(double x, double y, double z);
void Libera_pto(struct ponto **p);
double Distancia_pto(struct ponto *p1, struct ponto *p2);
