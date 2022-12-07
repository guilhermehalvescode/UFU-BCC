#include <bits/stdc++.h>
#include "../utils/Equacao.h"

using namespace std;

Equacao lerEquacao()
{
  int n, coef;
  cout << "Digite a quantidade de variaveis da equacao: ";
  cin >> n;

  Equacao eq = Equacao(n);

  for (int i = 0; i < n; i++)
  {
    cout << "Digite o coeficiente na variavel (" << i << "): ";
    cin >> coef;
    eq.defineCoeficiente(coef, i);
  }

  return eq;
}

Equacao lerFuncaoObjetivo()
{
  cout << "/Função Objetivo/" << endl;
  return lerEquacao();
}

vector<Equacao> lerRestricoes()
{
  int n, coef;
  cout << "Digite a quantidade de restricoes: ";
  cin >> n;

  vector<Equacao> restricoes;

  for (int i = 0; i < n; i++)
  {
    cout << "/Restricao " << i << "/" << endl;
    restricoes.push_back(lerEquacao());
  }

  return restricoes;
}

void mostrarNormalizacao(Equacao funcObj, vector<Equacao> restricoes)
{
  cout << "/Funcao Objetivo/" << endl;
  cout << funcObj.toString() << endl;

  cout << "/" << restricoes.size() << " Restricoes/" << endl;
  for (int i = 0; i < restricoes.size(); i++)
  {
    cout << restricoes[i].toString() << endl;
  }
}

int main()
{
  Equacao funcObj = lerFuncaoObjetivo();

  vector<Equacao> restricoes = lerRestricoes();

  mostrarNormalizacao(funcObj, restricoes);
  return 0;
}