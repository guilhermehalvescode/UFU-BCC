#ifndef Polinomio_H
#define Polinomio_H

class RespostaMetodoNumerico
{
public:
  double x;
  double err;
  unsigned int iteracoes;
};

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

  bool existeRaizNoIntervalo(double a, double b)
  {

    return this->calcula(a) * this->calcula(b) < 0;
  }
};

#endif