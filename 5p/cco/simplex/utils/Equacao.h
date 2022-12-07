#ifndef Equacao_H
#define Equacao_H

#include <bits/stdc++.h>

using namespace std;

class Equacao
{
public:
  vector<double> coeficientes;

  Equacao(unsigned int quantidadeVariaveis)
  {
    this->coeficientes = vector<double>(quantidadeVariaveis);
  }

  void defineCoeficiente(double valor, unsigned int indiceVariavel)
  {
    this->coeficientes[indiceVariavel] = valor;
  }

  string toString()
  {
    string to;

    for (int i = 0; i < this->coeficientes.size(); i++)
    {
      if (this->coeficientes[i] == 0)
        continue;
      if (this->coeficientes[i] < 0)
        to.append("(");
      to.append(to_string(this->coeficientes[i]));
      to.append("x_");
      to.append(to_string(i));
      if (this->coeficientes[i] < 0)
        to.append(")");
      if (i < this->coeficientes.size() - 1)
        to.append(" + ");
    }

    return to;
  }
};

#endif