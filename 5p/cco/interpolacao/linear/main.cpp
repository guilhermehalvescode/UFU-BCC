#include <bits/stdc++.h>
#include "../utils/Ponto.h"
#include "../utils/Matriz.h"

using namespace std;

Pontos lerPontos()
{
  int quantidadePontos;
  cout << "Informe a quantidade de pontos: ";
  cin >> quantidadePontos;

  Pontos pontos = Pontos(quantidadePontos);

  for (int i = 0; i < pontos.quantidade; i++)
  {
    cout << "Informe (x, f(x)): ";
    cin >> pontos.lista[i].x >> pontos.lista[i].fx;
  }

  return pontos;
}

Matriz montarMatrizAmpliada(Pontos pontos)
{

  Matriz matriz(pontos.quantidade, pontos.quantidade + 1);

  for (int i = 0; i < matriz.linhas; i++)
  {
    for (int j = 0; j < matriz.colunas; j++)
    {
      if (j == matriz.colunas - 1)
      {
        matriz.matriz[i][j] = pontos.lista[i].fx;
      }
      else
      {
        matriz.matriz[i][j] = pow(pontos.lista[i].x, j);
      }
    }
  }

  return matriz;
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

Matriz montaCoeficientesMetodoJordan(Matriz mat)
{
  int numeroIncognitas = mat.linhas;
  int numeroLinhasNaoNulasCoeficientes = mat.linhas - calcularLinhasNulasCoeficiente(mat);
  int numeroLinhasNaoNulasTermosIndependentes = mat.linhas - calcularLinhasNulasTermosIndependentes(mat);

  Matriz coeficientes = Matriz(mat.linhas, 1);

  if (numeroLinhasNaoNulasCoeficientes == numeroLinhasNaoNulasTermosIndependentes)
  {
    if (numeroLinhasNaoNulasCoeficientes == numeroIncognitas)
    {
      for (int i = 0; i < mat.linhas; i++)
      {
        coeficientes.matriz[i][0] = mat.matriz[i][mat.colunas - 1] / mat.matriz[i][i];
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

  return coeficientes;
}

int main()
{
  Pontos pontos = lerPontos();

  Matriz matrizAmpliada = montarMatrizAmpliada(pontos);

  metodoJordan(matrizAmpliada);

  Matriz coeficientes = montaCoeficientesMetodoJordan(matrizAmpliada);

  cout << "Polinomio que interpola esses pontos: " << endl;

  for (int i = 0; i < coeficientes.linhas; i++)
  {
    if (i != 0)
      printf(" + ");

    printf("(%.6lf)", coeficientes.matriz[i][0]);

    if (i != 0)
      printf("x^%d", i);
  }

  printf("\n");

  return 0;
}