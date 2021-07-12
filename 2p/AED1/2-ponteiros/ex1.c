#include <stdio.h>
int main(int argc, char const *argv[])
{
  double *p, *q, *r, A[5] = {1, 2, 3, 4, 5};
  p = A; // p = 1234600
  q = p + 1; // q = 1234608
  r = q + 2; // r = 1234624
  printf("&A[0] = %lu; *r = %lf;\n", &A[0], *r); // SAÍDA: &A[0] = 1234600; *r = 4.000000;
  printf("p = %lu; *(A+1) = %lf\n", p, *(A + 1)); // SAÍDA: p = 1234600; *(A+1) = 2.000000
  r = p + 4; // r = 1234632
  p = q; // p = 1234608
  printf("p+1 = %lu; *(r-2) = %lf\n", p + 1, *(r - 2)); // SAÍDA: p+1 = 1234616; *(r-2) = 3.000000
  printf("&A[4] = %lu; *r = %lf\n", &A[4], *r); // SAÍDA: &A[4] = 1234632; *r = 5.000000
  return 0;
}

//Considere que uma variável do tipo double ocupa 8 bytes e que o 
//endereço inicial de a é 1234600.
