#include <bits/stdc++.h>

#include "../utils/Matriz.h"
#include "../utils/RetornoMetodo.h"

using namespace std;

Matriz lerMatriz()
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

void normalizaMatrizesParaMetodo(Matriz coeficientes, Matriz termosIndependentes)
{
  for (int i = 0; i < coeficientes.linhas; i++)
  {
    double pivoDaLinhaI = coeficientes.matriz[i][i];

    for (int j = 0; j < coeficientes.colunas; j++)
    {
      if (i != j)
      {
        coeficientes.matriz[i][j] /= -pivoDaLinhaI;
      }
    }

    termosIndependentes.matriz[i][0] /= pivoDaLinhaI;

    coeficientes.matriz[i][i] = 0;
  }
}

bool condicaoParada(Matriz tentativa, double err)
{
  return tentativa.maximoAbsoluto() < err;
}

RetornoMetodo gaussJacobi(Matriz coeficientes, Matriz termosIndependentes, Matriz tentativaInicial, double err)
{
  unsigned int tentativas = 0;
  do
  {
    tentativaInicial = coeficientes.multiplica(tentativaInicial).soma(termosIndependentes);
    tentativas++;
  } while (!condicaoParada(tentativaInicial, err));

  return {tentativaInicial, tentativas};
}

RetornoMetodo gaussSeidel(Matriz coeficientes, Matriz termosIndependentes, Matriz tentativaInicial, double err)
{
  unsigned int tentativas = 0;
  do
  {
    for (int i = 0; i < coeficientes.linhas; i++)
    {
      for (int j = 0; j < tentativaInicial.colunas; j++)
      {

        double acum = 0;
        for (int k = 0; k < tentativaInicial.linhas; k++)
        {
          acum += coeficientes.matriz[i][k] * tentativaInicial.matriz[k][j];
        }
        tentativaInicial.matriz[i][0] = acum + termosIndependentes.matriz[i][0];
      }
    }

    tentativas++;
  } while (!condicaoParada(tentativaInicial, err));

  return {tentativaInicial, tentativas};
}

void mostraResposta(Matriz resposta)
{
  for (int i = 0; i < resposta.linhas; i++)
  {
    cout << "x" << i << ": " << resposta.matriz[i][0] << endl;
  }
}

int main()
{
  double err;
  cout << "- Matriz de coeficientes - " << endl;
  Matriz coeficientes = lerMatriz();

  cout << "- Matriz de termos independentes - " << endl;
  cout << "Numero de linhas precisa ser igual ao numero de linhas da matriz anterior" << endl;

  Matriz termosIndependentes = lerMatriz();

  cout << "- Tentativa inicial - " << endl;
  cout << "Numero de linhas precisa ser igual ao numero de linhas das duas matrizes anteriores" << endl;
  Matriz tentativaInicial = lerMatriz();

  cout << "- Erro aceitavel: ";
  cin >> err;

  normalizaMatrizesParaMetodo(coeficientes, termosIndependentes);
  RetornoMetodo retorno = gaussSeidel(coeficientes, termosIndependentes, tentativaInicial, err);

  cout << "- Resposta -" << endl;
  mostraResposta(retorno.resultado);

  return 0;
}