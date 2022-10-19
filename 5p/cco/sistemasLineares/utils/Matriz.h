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
};