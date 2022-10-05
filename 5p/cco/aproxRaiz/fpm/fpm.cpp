#include <bits/stdc++.h>

using namespace std;

class FpmDTO
{
public:
  double x;
  double err;
  unsigned int iteracoes;
};

double calculaPolinomio(double *polinomio, int grau, double valor);
FpmDTO calculaPFM(double *polinomio, int grau, double aInical, double bInicial, double err);

int main()
{
  int n;

  cout << "Informe o grau do polinomio: ";
  cin >> n;

  double polinomio[n + 1], a, b, err;

  for (int i = 0; i <= n; i++)
  {
    cout << "Informe o termo no grau " << i << ": ";
    cin >> polinomio[i];
  }

  cout << "Informe o intervalo [a,b]: ";
  cin >> a >> b;

  cout << "Informe a tolerancia: ";
  cin >> err;

  FpmDTO resposta = calculaPFM(polinomio, n, a, b, err);
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

double calculaPolinomio(double *polinomio, int grau, double valor)
{
  double resultado = 0;
  for (int i = 0; i <= grau; i++)
  {
    resultado += polinomio[i] * pow(valor, i);
  }

  return resultado;
}

bool existeRaizNoIntervalo(double *polinomio, int grau, double a, double b)
{
  return calculaPolinomio(polinomio, grau, a) * calculaPolinomio(polinomio, grau, b) < 0;
}

bool testeParada(double *polinomio, int grau, double valor, double err, double valorAnterior)
{
  return abs(calculaPolinomio(polinomio, grau, valor)) > err && abs((valorAnterior - valor) / valorAnterior) > err;
}

double calculaXPFM(double a, double b, double fa, double fb)
{
  return (a * fb - b * fa) / (fb - fa);
}

FpmDTO calculaPFM(double *polinomio, int grau, double aInical, double bInicial, double err)
{
  double a = aInical, b = bInicial, x = DBL_MAX, xAnterior = DBL_MIN, fa, fb;
  unsigned int iteracoes = 1;
  FpmDTO resposta = {DBL_MAX, 0, 0};

  if (!existeRaizNoIntervalo(polinomio, grau, a, b))
    return resposta;

  fa = calculaPolinomio(polinomio, grau, a);
  fb = calculaPolinomio(polinomio, grau, b);

  x = calculaXPFM(a, b, fa, fb);

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
    x = calculaXPFM(a, b, fa, fb);
    iteracoes++;
  }

  resposta = {x, abs(calculaPolinomio(polinomio, grau, x)), iteracoes};

  return resposta;
}