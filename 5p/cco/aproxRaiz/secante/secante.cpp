#include <bits/stdc++.h>
#include "../utils/aux.h"
using namespace std;

RespostaMetodoNumerico calculaPorMetodoSecante(double *polinomio, int grau, double aInical, double bInicial, double err);

int main()
{
  int n;

  cout << "Informe o grau do polinomio: ";
  cin >> n;

  double polinomio[n + 1], x0, x1, err;

  for (int i = 0; i <= n; i++)
  {
    cout << "Informe o termo no grau " << i << ": ";
    cin >> polinomio[i];
  }

  cout << "Informe o intervalo [x0, x1]: ";
  cin >> x0 >> x1;

  cout << "Informe a tolerancia: ";
  cin >> err;

  RespostaMetodoNumerico resposta = calculaPorMetodoSecante(polinomio, n, x0, x1, err);
  if (resposta.x == DBL_MAX)
  {
    cout << "Raiz não encontrada no intervalo!" << endl;
  }
  else
  {
    printf("Raiz (%.4f, %.4f) encontrada no intervalo com %d iteracoes\n", resposta.x, resposta.err, resposta.iteracoes);
  }

  return 1;
}

RespostaMetodoNumerico calculaPorMetodoSecante(double *polinomio, int grau, double aInical, double bInicial, double err)
{
  double a = aInical, b = bInicial, x = DBL_MAX, xAnterior = DBL_MIN, fa, fb;
  unsigned int iteracoes = 1;
  RespostaMetodoNumerico resposta = {DBL_MAX, 0, 0};

  if (!existeRaizNoIntervalo(polinomio, grau, a, b))
    return resposta;

  fa = calculaPolinomio(polinomio, grau, a);
  fb = calculaPolinomio(polinomio, grau, b);

  x = calculaXPF(a, b, fa, fb);

  while (testeParada(polinomio, grau, x, err, xAnterior))
  {
    if (existeRaizNoIntervalo(polinomio, grau, a, x))
    {
      b = x;
      fa = calculaPolinomio(polinomio, grau, a) / 2.0;
      fb = calculaPolinomio(polinomio, grau, b);
    }
    else
    {
      a = x;
      fa = calculaPolinomio(polinomio, grau, a);
      fb = calculaPolinomio(polinomio, grau, b) / 2.0;
    }

    xAnterior = x;
    x = calculaXPF(a, b, fa, fb);
    iteracoes++;
  }

  resposta = {x, abs(calculaPolinomio(polinomio, grau, x)), iteracoes};

  return resposta;
}