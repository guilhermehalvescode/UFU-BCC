#ifndef Polinomio_H
#define Polinomio_H

#include <stdlib.h>
#include <math.h>

class Polinomio
{
public:
  double *coeficientes;
  unsigned int grau;

  Polinomio(unsigned int grau)
  {
    this->coeficientes = (double *)malloc(sizeof(double) * (grau + 1));
    this->grau = grau;
  }

  void defineCoeficiente(double valor, unsigned int grau)
  {
    this->coeficientes[grau] = valor;
  }

  double calcula(double valor)
  {
    double resultado = 0;
    for (int i = 0; i <= this->grau; i++)
    {
      resultado += this->coeficientes[i] * pow(valor, i);
    }

    return resultado;
  }

  string toString()
  {
    string to;

    for (int i = 0; i < this->grau; i++)
    {
      to.append("(");
      to.append(to_string(this->coeficientes[i]));
      to.append("x^");
      to.append(to_string(i));
      to.append(")");
      if (i != 0 && i != this->grau - 1)
        to.append(" + ");
    }

    return to;
  }
};

#endif