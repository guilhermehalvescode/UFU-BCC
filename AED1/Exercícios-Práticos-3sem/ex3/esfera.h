typedef struct reta esfera;

esfera* cria_esfera(double x1, double y1, double z1, double x2, double y2, double z2);
void libera_esfera(esfera* *reta);
double raio(esfera *reta);
double area(double raio);
double volume(double raio);
