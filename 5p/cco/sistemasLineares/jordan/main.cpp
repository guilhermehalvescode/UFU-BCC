#include <bits/stdc++.h>

#include "../utils/Matriz.h"

using namespace std;

Matriz lerMatrizAmpliada()
{
  int linhas, colunas;
  cout << "Informe a quantidade de linhas: ";
  cin >> linhas;

  cout << "Informe a quantidade de colunas: ";
  cin >> colunas;

  Matriz mat(linhas, colunas);

  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      cout << "Informe o elemento em (" << i << ", " << j << "): ";
      cin >> mat.matriz[i][j];
    }
  }

  return mat;
}

void metodoJordan(Matriz mat)
{
  for (int j = 0; j < mat.colunas - 1; j++)
  {

    for (int i = 0; i < mat.linhas; i++)
    {
      if (i == j)
        continue;

      double m = mat.matriz[i][j] / mat.matriz[j][j];

      for (int k = 0; k < mat.colunas; k++)
      {
        mat.matriz[i][k] -= m * mat.matriz[j][k];
      }
    }
  }
}

void mostraRespostaJordan(Matriz mat)
{
  for (int i = 0; i < mat.linhas; i++)
  {
    cout << "x" << i << ": " << mat.matriz[i][mat.colunas - 1] / mat.matriz[i][i] << endl;
  }
}

int main()
{

  Matriz mat = lerMatrizAmpliada();

  metodoJordan(mat);

  cout << "\nMatriz: " << endl;

  mat.toString();

  cout << "Resposta: " << endl;

  mostraRespostaJordan(mat);

  return 0;
}