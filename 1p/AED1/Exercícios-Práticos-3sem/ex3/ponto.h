typedef struct ponto Ponto;

Ponto* Cria_pto(double x, double y, double z);
void Libera_pto(Ponto **p);
double Distancia_pto(Ponto *p1, Ponto *p2);
