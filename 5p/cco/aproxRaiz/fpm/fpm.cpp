#include <bits/stdc++.h>
#include "../utils/Polinomio.h"
#include "../utils/Aux.h"

using namespace std;

RespostaMetodoNumerico calculaPFM(Polinomio polinomio, double aInical, double bInicial, double err);

int main()
{
  int n;

  cout << "Informe o grau do polinomio: ";
  cin >> n;

  Polinomio polinomio(n);
  double a, b, err, coef;

  for (unsigned int i = 0; i <= n; i++)
  {
    cout << "Informe o termo no grau " << i << ": ";

    cin >> coef;

    polinomio.defineCoeficiente(coef, i);
  }

  cout << "Informe o intervalo [a,b]: ";
  cin >> a >> b;

  cout << "Informe a tolerancia: ";
  cin >> err;

  RespostaMetodoNumerico resposta = calculaPFM(polinomio, a, b, err);
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

RespostaMetodoNumerico calculaPFM(Polinomio polinomio, double aInical, double bInicial, double err)
{
  double a = aInical, b = bInicial, x = DBL_MAX, xAnterior = DBL_MIN, fa, fb;
  unsigned int iteracoes = 1;
  RespostaMetodoNumerico resposta = {DBL_MAX, 0, 0};

  if (!polinomio.existeRaizNoIntervalo(a, b))
    return resposta;

  fa = polinomio.calcula(a);
  fb = polinomio.calcula(b);

  x = Aux::calculaXPF(a, b, fa, fb);

  while (Aux::testeParada(polinomio, x, err, xAnterior))
  {
    if (polinomio.existeRaizNoIntervalo(a, x))
    {
      b = x;
      fa = polinomio.calcula(a) / 2.0;
      fb = polinomio.calcula(b);
    }
    else
    {
      a = x;
      fa = polinomio.calcula(a);
      fb = polinomio.calcula(b) / 2.0;
    }

    xAnterior = x;
    x = Aux::calculaXPF(a, b, fa, fb);
    iteracoes++;
  }

  resposta = {x, abs(polinomio.calcula(x)), iteracoes};

  return resposta;
}