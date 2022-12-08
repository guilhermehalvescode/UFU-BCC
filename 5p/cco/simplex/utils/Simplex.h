#ifndef Simplex_H
#define Simplex_H

#include "./Equacao.h"
#include "./Inequacao.h"

using namespace std;

enum TipoOtimizacao
{
  MIN = 0,
  MAX = 1
};

class Simplex
{
public:
  Equacao *funcaoObjetivo;
  vector<Inequacao> inequacoes;
  TipoOtimizacao tipo;

  Simplex(Equacao *funcaoObjetivo, vector<Inequacao> inequacoes, TipoOtimizacao tipo)
  {
    this->funcaoObjetivo = funcaoObjetivo;
    this->inequacoes = inequacoes;
    this->tipo = tipo;
  }
};

#endif