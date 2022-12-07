#include <bits/stdc++.h>
#include "../utils/Equacao.h"
#include "../utils/Inequacao.h"

using namespace std;

Inequacao lerInequacaoSemTermoIndependente()
{
  int n, coef;
  char tipoEntrada;
  SimbolosDesigualdade tipo;
  cout << "Digite a quantidade de variaveis da inequacao: ";
  cin >> n;

  cout << "Digite o tipo de inequacao (>, <, =): ";
  cin >> tipoEntrada;

  tipo = static_cast<SimbolosDesigualdade>(tipoEntrada);
  Inequacao ineq = Inequacao(n, tipo);

  for (int i = 0; i < n; i++)
  {
    cout << "Digite o coeficiente na variavel (" << i << "): ";
    cin >> coef;
    ineq.defineCoeficiente(coef, i);
  }

  return ineq;
}

Equacao lerEquacaoSemTermoIndependente()
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

Equacao lerEquacao()
{
  double coef;
  Equacao eq = lerEquacaoSemTermoIndependente();

  cout << "Digite o termo independente: ";
  cin >> coef;
  eq.defineTermoIndependente(coef);

  return eq;
}

Inequacao lerInequacao()
{
  double coef;
  Inequacao ineq = lerInequacaoSemTermoIndependente();

  cout << "Digite o termo independente: ";
  cin >> coef;
  ineq.defineTermoIndependente(coef);

  return ineq;
}

Equacao lerFuncaoObjetivo()
{
  cout << "/Função Objetivo/" << endl;
  return lerEquacaoSemTermoIndependente();
}

vector<Inequacao> lerRestricoes()
{
  int n, coef;
  cout << "Digite a quantidade de restricoes: ";
  cin >> n;

  vector<Inequacao> restricoes;

  for (int i = 0; i < n; i++)
  {
    cout << "/Restricao " << i << "/" << endl;
    restricoes.push_back(lerInequacao());
  }

  return restricoes;
}

void mostrarNormalizacao(Equacao funcaoObjetivo, vector<Inequacao> restricoes)
{
  cout << "/Funcao Objetivo/" << endl;
  cout << funcaoObjetivo.toString() << endl;

  cout << "/" << restricoes.size() << " Restricoes/" << endl;
  for (int i = 0; i < restricoes.size(); i++)
  {
    cout << restricoes[i].toString() << endl;
  }
}

void normalizaParaSimplex(Equacao funcaoObjetivo, vector<Inequacao> restricoes, bool ehMaximizacao)
{
  unsigned int qntVariaveis = 0;

  for (int i = 0; i < restricoes.size(); i++)
  {

    if (restricoes[i].tipo == SimbolosDesigualdade::Maior)
    {
      unsigned int indiceInicial = restricoes[i].coeficientes.size() + qntVariaveis;

      // variavel de excesso
      restricoes[i].defineCoeficiente(-1, indiceInicial);
      funcaoObjetivo.adicionaCoeficiente(-0);

      // variavel artificial
      cout << restricoes[i].coeficientes.size() << endl;
      cout << qntVariaveis << endl;
      restricoes[i].defineCoeficiente(1, indiceInicial + 1);
      funcaoObjetivo.adicionaCoeficiente(ehMaximizacao ? DBL_MIN : DBL_MAX);

      qntVariaveis += 2;
    }
    else if (restricoes[i].tipo == SimbolosDesigualdade::Menor)
    {
      // variavel de folga
      restricoes[i].defineCoeficiente(1, restricoes[i].coeficientes.size() + qntVariaveis);
      funcaoObjetivo.adicionaCoeficiente(0);
      qntVariaveis++;
    }
    else
    {
      // variavel artificial
      restricoes[i].defineCoeficiente(1, restricoes[i].coeficientes.size() + qntVariaveis);
      funcaoObjetivo.adicionaCoeficiente(ehMaximizacao ? DBL_MIN : DBL_MAX);
      qntVariaveis++;
    }

    // remove inequacao
    restricoes[i].tipo = SimbolosDesigualdade::Nenhum;
  }

  for (int i = 0; i < restricoes.size(); i++)
  {
    restricoes[i].coeficientes.resize(funcaoObjetivo.coeficientes.size());
  }

  mostrarNormalizacao(funcaoObjetivo, restricoes);
}

int main()
{
  Equacao funcaoObjetivo = lerFuncaoObjetivo();

  vector<Inequacao> restricoes = lerRestricoes();

  normalizaParaSimplex(funcaoObjetivo, restricoes, false);

  return 0;
}