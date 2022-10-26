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

bool condicaoParada(Matriz resultadoAnterior, Matriz resultado, double err)
{
  double distanciaEntreDuasIteracoes = resultado.subtrai(resultadoAnterior).maximoAbsoluto();
  double maximoAbsolutoResultado = resultado.maximoAbsoluto();

  if (distanciaEntreDuasIteracoes == 0 && maximoAbsolutoResultado == 0)
    return true;

  if (distanciaEntreDuasIteracoes != 0 && maximoAbsolutoResultado == 0)
    return false;

  return distanciaEntreDuasIteracoes / resultado.maximoAbsoluto() < err;
}

RetornoMetodo gaussJacobi(Matriz coeficientes, Matriz termosIndependentes, Matriz resultado, double err)
{
  unsigned int tentativas = 0;
  Matriz resultadoAnterior(resultado.linhas, resultado.colunas);

  do
  {
    resultadoAnterior.copiar(resultado);
    resultado = coeficientes.multiplica(resultado).soma(termosIndependentes);
    tentativas++;
  } while (!condicaoParada(resultadoAnterior, resultado, err));

  return {resultado, tentativas};
}

RetornoMetodo gaussSeidel(Matriz coeficientes, Matriz termosIndependentes, Matriz resultado, double err)
{
  unsigned int tentativas = 0;
  Matriz resultadoAnterior(resultado.linhas, resultado.colunas);

  do
  {
    resultadoAnterior.copiar(resultado);
    for (int i = 0; i < coeficientes.linhas; i++)
    {
      for (int j = 0; j < resultado.colunas; j++)
      {

        double acum = 0;
        for (int k = 0; k < resultado.linhas; k++)
        {
          acum += coeficientes.matriz[i][k] * resultado.matriz[k][j];
        }
        resultado.matriz[i][0] = acum + termosIndependentes.matriz[i][0];
      }
    }

    tentativas++;
  } while (!condicaoParada(resultadoAnterior, resultado, err));

  return {resultadoAnterior, tentativas};
}

bool convergePorSassenfeld(Matriz coeficientes)
{
  Matriz razoes(coeficientes.linhas, 1);

  for (int i = 0; i < razoes.linhas; i++)
  {
    razoes.matriz[i][0] = 1;
  }

  for (int i = 0; i < coeficientes.linhas; i++)
  {
    double soma = 0;
    for (int j = 0; j < coeficientes.colunas; j++)
    {
      if (i != j)
        soma += abs(coeficientes.matriz[i][j]) * razoes.matriz[j][0];
    }

    razoes.matriz[i][0] = soma / abs(coeficientes.matriz[i][i]);
  }

  return razoes.maximoAbsoluto() < 1;
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

  if (!convergePorSassenfeld(coeficientes))
  {
    cout << "Não converge por Sassenfeld, logo nao pode usar Gauss-Seidel" << endl;
    return 1;
  }

  normalizaMatrizesParaMetodo(coeficientes, termosIndependentes);
  RetornoMetodo retorno = gaussSeidel(coeficientes, termosIndependentes, tentativaInicial, err);

  cout << "- Resposta com " << retorno.tentativas << " iteracoes -" << endl;
  mostraResposta(retorno.resultado);

  return 0;
}