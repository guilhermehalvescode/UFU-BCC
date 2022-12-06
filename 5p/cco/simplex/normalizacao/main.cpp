#include <bits/stdc++.h>
#include "../utils/Polinomio.h"

using namespace std;

Polinomio lerPolinomio()
{
  int n, coef;
  cout << "Digite o grau da função: ";
  cin >> n;

  Polinomio pol = Polinomio(n);

  for (int i = 0; i <= n; i++)
  {
    cout << "Digite o coeficiente no grau (" << i << "): ";
    cin >> coef;
    pol.defineCoeficiente(coef, i);
  }

  return pol;
}

Polinomio lerFuncaoObjetivo()
{
  cout << "/Função Objetivo/" << endl;
  return lerPolinomio();
}

Polinomio *lerRestricoes()
{
  int n, coef;
  cout << "Digite a quantidade de restricoes: ";
  cin >> n;

  Polinomio *restricoes = (Polinomio *)malloc(sizeof(Polinomio) * n);

  if (!restricoes)
    return NULL;

  for (int i = 0; i < n; i++)
  {
    cout << "/Restricao " << i << "/";
    restricoes[i] = lerPolinomio();
  }

  return restricoes;
}

void mostrarNormalizacao(Polinomio funcObj, Polinomio *restricoes, int qntRestricoes)
{
  cout << "/Funcao Objetivo/" << endl;
  cout << funcObj.toString();

  cout << "/" << qntRestricoes << " Restricoes/" << endl;
  for (int i = 0; i < qntRestricoes; i++)
  {
    cout << restricoes->toString();
  }
}
int main()
{

  Polinomio funcObj = lerFuncaoObjetivo();

  Polinomio *restricoes = lerRestricoes();

  mostrarNormalizacao(funcObj, restricoes, qntRestricoes);
  return 0;
}