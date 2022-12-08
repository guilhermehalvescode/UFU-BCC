#include "../utils/Equacao.h"
#include "../utils/Inequacao.h"
#include "../utils/Simplex.h"

using namespace std;

Inequacao lerInequacaoSemTermoIndependente()
{
  int n;
  double coef;
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
  int n;
  double coef;
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

void mostrarNormalizacao(Simplex sp)
{
  vector<Inequacao> restricoes = sp.inequacoes;

  cout << "/Funcao Objetivo/" << (sp.tipo == TipoOtimizacao::MAX ? "MAX" : "MIN") << endl;
  cout << (*sp.funcaoObjetivo).toString() << endl;

  cout << "/" << restricoes.size() << " Restricoes/" << endl;
  for (int i = 0; i < restricoes.size(); i++)
  {
    cout << restricoes[i].toString() << endl;
  }
}

Simplex normalizaParaSimplex(Simplex sp)
{
  vector<Inequacao> restricoes = sp.inequacoes;
  TipoOtimizacao tipo = sp.tipo;

  unsigned int qntVariaveis = 0;

  for (int i = 0; i < restricoes.size(); i++)
  {

    if (restricoes[i].tipo == SimbolosDesigualdade::Maior)
    {
      unsigned int indiceInicial = restricoes[i].coeficientes.size() + qntVariaveis;

      // variavel de excesso
      restricoes[i].defineCoeficiente(-1, indiceInicial);
      (*sp.funcaoObjetivo).adicionaCoeficiente(-0);

      // variavel artificial
      restricoes[i].defineCoeficiente(1, indiceInicial + 1);
      (*sp.funcaoObjetivo).adicionaCoeficiente(tipo == TipoOtimizacao::MAX ? DBL_MIN : DBL_MAX);

      qntVariaveis += 2;
    }
    else if (restricoes[i].tipo == SimbolosDesigualdade::Menor)
    {
      // variavel de folga
      restricoes[i].defineCoeficiente(1, restricoes[i].coeficientes.size() + qntVariaveis);
      (*sp.funcaoObjetivo).adicionaCoeficiente(0);
      qntVariaveis++;
    }
    else
    {
      // variavel artificial
      restricoes[i].defineCoeficiente(1, restricoes[i].coeficientes.size() + qntVariaveis);
      (*sp.funcaoObjetivo).adicionaCoeficiente(tipo == TipoOtimizacao::MAX ? DBL_MIN : DBL_MAX);
      qntVariaveis++;
    }

    // remove inequacao
    restricoes[i].tipo = SimbolosDesigualdade::Nenhum;
  }

  for (int i = 0; i < restricoes.size(); i++)
  {
    restricoes[i].coeficientes.resize((*sp.funcaoObjetivo).coeficientes.size());
  }

  return Simplex(sp.funcaoObjetivo, restricoes, tipo);
}

TipoOtimizacao lerTipoOtimizacao()
{
  TipoOtimizacao tipo;
  int tipoLido;
  cout << "Digite o tipo de otimizacao (MIN = 0, MAX = 1): ";
  cin >> tipoLido;

  return static_cast<TipoOtimizacao>(tipoLido);
}

int main()
{
  Equacao funcaoObjetivo = lerFuncaoObjetivo();

  vector<Inequacao> restricoes = lerRestricoes();

  TipoOtimizacao tipo = lerTipoOtimizacao();

  Simplex sp = Simplex(&funcaoObjetivo, restricoes, tipo);

  sp = normalizaParaSimplex(sp);

  mostrarNormalizacao(sp);
  return 0;
}