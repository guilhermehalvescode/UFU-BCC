#ifndef Inequacao_H
#define Inequacao_H

#include "./Equacao.h"

enum SimbolosDesigualdade
{
  Menor = '<',
  Maior = '>',
  Nenhum = '='
};

class Inequacao : public Equacao
{
public:
  SimbolosDesigualdade tipo;

  Inequacao(unsigned int quantidadeVariaveis, SimbolosDesigualdade tipo) : Equacao(quantidadeVariaveis)
  {
    this->tipo = tipo;
  }

  string eqSimbolo()
  {
    string simbolo = " ";
    if (this->tipo != SimbolosDesigualdade::Nenhum)
      simbolo.push_back((char)this->tipo);
    simbolo.append("= ");
    return simbolo;
  }
};

#endif