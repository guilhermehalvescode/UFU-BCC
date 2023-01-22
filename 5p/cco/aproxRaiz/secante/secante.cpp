#include <bits/stdc++.h>

#include "../utils/Polinomio.h"
#include "../utils/Auxiliariliar.h"
using namespace std;

RespostaMetodoNumerico calculaPorMetodoSecante(Polinomio polinomio, double x0, double x1, double err);

int main()
{
  int n;

  cout << "Informe o grau do polinomio: ";
  cin >> n;

  Polinomio polinomio(n);
  double x0, x1, err, coef;

  for (unsigned int i = 0; i <= n; i++)
  {
    cout << "Informe o termo no grau " << i << ": ";

    cin >> coef;

    polinomio.defineCoeficiente(coef, i);
  }

  cout << "Informe o intervalo [x0, x1]: ";
  cin >> x0 >> x1;

  cout << "Informe a tolerancia: ";
  cin >> err;

  RespostaMetodoNumerico resposta = calculaPorMetodoSecante(polinomio, x0, x1, err);
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

RespostaMetodoNumerico calculaPorMetodoSecante(Polinomio polinomio, double x1, double x2, double err)
{
  double x = DBL_MAX, xAnterior = DBL_MIN, fx1, fx2;
  RespostaMetodoNumerico resposta = {x, 0, 1};

  fx1 = polinomio.calcula(x1);
  fx2 = polinomio.calcula(x2);

  x = Auxiliar::calculaXPF(x1, x2, fx1, fx2);

  while (Auxiliar::testeParada(polinomio, x, err, xAnterior))
  {

    x1 = x2;
    x2 = x;
    xAnterior = x;

    fx1 = polinomio.calcula(x1);
    fx2 = polinomio.calcula(x2);

    x = Auxiliar::calculaXPF(x1, x2, fx1, fx2);
    resposta.iteracoes++;
  }

  resposta.x = x;
  resposta.err = abs(polinomio.calcula(x));

  return resposta;
}