#ifndef Aux_H
#define Aux_H

#include "Polinomio.h"
#include <math.h>

class Aux
{
public:
  static bool testeParada(Polinomio polinomio, double valor, double err, double valorAnterior)
  {
    return abs(polinomio.calcula(valor)) > err && abs((valorAnterior - valor) / valorAnterior) > err;
  }

  static double calculaXPF(double a, double b, double fa, double fb)
  {
    return (a * fb - b * fa) / (fb - fa);
  }

private:
  Aux() {}
};

#endif