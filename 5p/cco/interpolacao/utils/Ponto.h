#ifndef PONTO_H
#define PONTO_H

class Ponto
{
public:
  double x;
  double fx;
};

class Pontos
{
public:
  Ponto *lista;
  int quantidade;

  Pontos(int quantidade)
  {
    this->lista = (Ponto *)malloc(sizeof(Ponto) * quantidade);
    this->quantidade = quantidade;
  }

  ~Pontos()
  {
    free(this->lista);
  }
};

#endif