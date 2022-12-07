#ifndef Equacao_H
#define Equacao_H

#include <bits/stdc++.h>

using namespace std;

class Equacao
{
public:
  vector<double> coeficientes;
  double termoIndependente = DBL_MIN;

  Equacao(unsigned int quantidadeVariaveis)
  {
    this->coeficientes = vector<double>(quantidadeVariaveis);
  }

  void defineCoeficiente(double valor, unsigned int indiceVariavel)
  {
    if (indiceVariavel >= this->coeficientes.size())
      this->coeficientes.resize(indiceVariavel + 1, 0.0);
    cout << "defini: " << indiceVariavel << " " << valor << endl;
    this->coeficientes[indiceVariavel] = valor;
  }

  void adicionaCoeficiente(double valor)
  {
    this->defineCoeficiente(valor, this->coeficientes.size());
  }

  void defineTermoIndependente(double termoIndependente)
  {
    this->termoIndependente = termoIndependente;
  }

  string toString()
  {
    string to;

    for (int i = 0; i < this->coeficientes.size(); i++)
    {
      if (this->coeficientes[i] < 0)
        to.append("(");
      if (this->coeficientes[i] == DBL_MIN)
        to.append("-M");
      else if (this->coeficientes[i] == DBL_MAX)
        to.append("M");
      else
        to.append(to_string(this->coeficientes[i]));

      to.append("x_");
      to.append(to_string(i));
      if (this->coeficientes[i] < 0)
        to.append(")");
      if (i < this->coeficientes.size() - 1)
        to.append(" + ");
    }
    to.append(this->eqSimbolo());
    to.append(this->termoIndependente == DBL_MIN ? "z" : to_string(this->termoIndependente));
    return to;
  }

  virtual string eqSimbolo()
  {
    return " = ";
  }
};

#endif