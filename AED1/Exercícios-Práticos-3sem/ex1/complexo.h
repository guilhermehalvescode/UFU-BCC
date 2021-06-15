typedef struct num complex;

complex* cria_nro(double real, double imag);
void libera_nro(complex* *z);
complex* soma(complex *a, complex *b);
complex* sub(complex *a, complex *b);
complex* mult(complex *a, complex *b);
int get_complex(complex *a, double *real, double *imag);
