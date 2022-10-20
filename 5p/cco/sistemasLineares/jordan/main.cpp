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

int acharLinhaNaoNula(Matriz mat, int linha, int coluna)
{
  for (int i = linha + 1; i < mat.linhas; i++)
  {
    if (mat.matriz[i][coluna] != 0)
    {
      return i;
    }
  }

  return -1;
}

void trocarLinhas(Matriz mat, int linha1, int linha2)
{
  for (int i = 0; i < mat.colunas; i++)
  {
    double aux = mat.matriz[linha1][i];
    mat.matriz[linha1][i] = mat.matriz[linha2][i];
    mat.matriz[linha2][i] = aux;
  }
}

void metodoJordan(Matriz mat)
{
  for (int j = 0; j < mat.colunas - 1; j++)
  {

    for (int i = 0; i < mat.linhas; i++)
    {
      if (i == j)
        continue;

      if (mat.matriz[j][j] == 0)
      {
        int linha = acharLinhaNaoNula(mat, j, j);

        if (linha != -1)
          trocarLinhas(mat, i, linha);
        else
          return;
      }

      double m = mat.matriz[i][j] / mat.matriz[j][j];

      for (int k = 0; k < mat.colunas; k++)
      {
        mat.matriz[i][k] -= m * mat.matriz[j][k];
      }
    }
  }
}

int calcularLinhasNulasCoeficiente(Matriz mat)
{
  int linhasNulas = 0;
  for (int i = 0; i < mat.linhas; i++)
  {
    int coeficiente = 0;
    for (int j = 0; j < mat.colunas; j++)
    {
      if (mat.matriz[i][j] != 0)
      {
        coeficiente = 1;
      }
    }

    if (coeficiente == 0)
    {
      linhasNulas++;
    }
  }
  return linhasNulas;
}

int calcularLinhasNulasTermosIndependentes(Matriz mat)
{
  int linhasNulas = 0;
  int colunaTermosIndependentes = mat.colunas - 1;

  for (int i = 0; i < mat.linhas; i++)
  {

    if (mat.matriz[i][colunaTermosIndependentes] == 0)
    {
      linhasNulas++;
    }
  }

  return linhasNulas;
}

void mostraRespostaJordan(Matriz mat)
{
  int numeroIncognitas = mat.linhas;
  int numeroLinhasNaoNulasCoeficientes = mat.linhas - calcularLinhasNulasCoeficiente(mat);
  int numeroLinhasNaoNulasTermosIndependentes = mat.linhas - calcularLinhasNulasTermosIndependentes(mat);

  if (numeroLinhasNaoNulasCoeficientes == numeroLinhasNaoNulasTermosIndependentes)
  {
    if (numeroLinhasNaoNulasCoeficientes == numeroIncognitas)
    {
      cout << "Sistema com solução unica: " << endl;
      for (int i = 0; i < mat.linhas; i++)
      {
        cout << "x" << i << ": " << mat.matriz[i][mat.colunas - 1] / mat.matriz[i][i] << endl;
      }
    }
    else if (numeroLinhasNaoNulasTermosIndependentes < numeroIncognitas)
    {
      cout << "Sistema com soluções multiplas e grau de liberdade: " << numeroIncognitas - numeroLinhasNaoNulasCoeficientes << endl;
    }
  }
  else
  {
    cout << "Sistema sem solução" << endl;
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