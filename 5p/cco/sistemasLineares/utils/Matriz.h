#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdlib.h>

using namespace std;

class Matriz
{
public:
  double **matriz;
  int linhas;
  int colunas;

  Matriz(int linhas, int colunas)
  {
    this->matriz = (double **)malloc(linhas * sizeof(double *));

    for (int i = 0; i < linhas; i++)
    {
      this->matriz[i] = (double *)malloc(colunas * sizeof(double));
    }

    this->linhas = linhas;
    this->colunas = colunas;
  }

  void toString()
  {
    for (int i = 0; i < this->linhas; i++)
    {
      for (int j = 0; j < this->colunas; j++)
      {
        cout << this->matriz[i][j] << " ";
      }
      cout << endl;
    }
  }

  Matriz multiplica(Matriz outra)
  {
    Matriz resultado(this->linhas, outra.colunas);

    for (int i = 0; i < this->linhas; i++)
    {
      for (int j = 0; j < outra.colunas; j++)
      {

        double acum = 0;
        for (int k = 0; k < outra.linhas; k++)
        {
          acum += this->matriz[i][k] * outra.matriz[k][j];
        }
        resultado.matriz[i][j] = acum;
      }
    }
    return resultado;
  }

  Matriz soma(Matriz outra)
  {
    Matriz resultado(this->linhas, this->colunas);

    for (int i = 0; i < this->linhas; i++)
    {
      for (int j = 0; j < outra.colunas; j++)
      {
        resultado.matriz[i][j] = this->matriz[i][j] + outra.matriz[i][j];
      }
    }

    return resultado;
  }

  double maximoAbsoluto()
  {
    double max = abs(this->matriz[0][0]);

    for (int i = 0; i < this->linhas; i++)
    {
      for (int j = 1; j < this->colunas; j++)
      {
        if (abs(this->matriz[i][j]) > max)
          max = abs(this->matriz[i][j]);
      }
    }

    return max;
  }
};

#endif