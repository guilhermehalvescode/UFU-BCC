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

int main()
{
  Pontos pontos = lerPontos();

  Matriz matrizAmpliada = montarMatrizAmpliada(pontos);

  metodoJordan(matrizAmpliada);

  matrizAmpliada.toString();

  return 0;
}