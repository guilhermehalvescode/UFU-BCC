#ifndef QuadroSimplex_H
#define QuadroSimplex_H

using namespace std;

class QuadroSimplex
{
public:
  vector<string> variaveis;
  vector<string> variaveisSolucao;

  // temp
  vector<double> valoresSolucaoInicial;

  vector<Equacao> coeficientesRestricoes;
  vector<Equacao> ultimaLinha;

  QuadroSimplex(Simplex s)
  {
    this->geraVariaveis(s.funcaoObjetivo->coeficientes);

    this->geraVariaviesSolucao(s.funcaoObjetivo->coeficientes, s.inequacoes.size());
    this->geraCoeficientesRestricoes(s.inequacoes, s.funcaoObjetivo->coeficientes.size());

    this->geraUltimaLinha(s.funcaoObjetivo->coeficientes, s.tipo);
  }

  void geraVariaveis(vector<double> coeficientes)
  {
    for (size_t i = 0; i < coeficientes.size(); i++)
    {
      string input = "";
      input.push_back('x');
      input.push_back((char)i + '0');
      this->variaveis.push_back(input);
    }
  }

  void geraVariaviesSolucao(vector<double> coeficientes, int size)
  {
    for (size_t i = coeficientes.size() - size; i < coeficientes.size(); i++)
    {
      string input = "";
      input.push_back('x');
      input.push_back((char)i + '0');
      this->variaveisSolucao.push_back(input);
      this->valoresSolucaoInicial.push_back(coeficientes[i]);
    }
  }

  void geraCoeficientesRestricoes(vector<Inequacao> ineqs, int size)
  {
    for (size_t i = 0; i < ineqs.size(); i++)
    {
      Equacao eq(size);

      for (size_t j = 0; j < ineqs[i].coeficientes.size(); j++)
        eq.defineCoeficiente(ineqs[i].coeficientes[j], j);

      eq.termoIndependente = ineqs[i].termoIndependente;
      this->coeficientesRestricoes.push_back(eq);
    }
  }

  void geraUltimaLinha(vector<double> coeficientes, TipoOtimizacao tipo)
  {
    Equacao eq(coeficientes.size());
    for (size_t i = 0; i < coeficientes.size(); i++)
    {
      double resultado = 0;
      bool ehMax = (tipo == TipoOtimizacao::MAX);
      resultado = (ehMax ? -coeficientes[i] : coeficientes[i]);

      for (size_t j = 0; j < this->valoresSolucaoInicial.size(); j++)
      {
        if (ehMax)
          resultado += this->valoresSolucaoInicial[j] * this->coeficientesRestricoes[j].coeficientes[i];
        else
          resultado -= this->valoresSolucaoInicial[j] * this->coeficientesRestricoes[j].coeficientes[i];
      }
      eq.defineCoeficiente(resultado, i);
    }

    double resTI = 0;
    for (size_t j = 0; j < this->valoresSolucaoInicial.size(); j++)
    {
      resTI -= this->valoresSolucaoInicial[j] * this->coeficientesRestricoes[j].termoIndependente;
    }

    eq.termoIndependente = resTI;

    this->ultimaLinha.push_back(eq);
  }

  void executa()
  {
    int jTrabalho = this->ultimaLinha[0].achaColunaTermoMaisNegativo();

    while (jTrabalho != -1 && this->ultimaLinha[0].coeficientes[jTrabalho] < 0)
    {
      cout << "Coluna de trabalho: " << jTrabalho << endl;
      int iTrabalho = this->achaLinhaMenorQuociente(jTrabalho);

      if (iTrabalho == -1)
      {
        cout << "Problema não tem solução" << endl;
        return;
      }

      this->trocaVariaveis(iTrabalho, jTrabalho);

      this->atualizaQuadro(iTrabalho, jTrabalho);

      jTrabalho = this->ultimaLinha[0].achaColunaTermoMaisNegativo();
    }
  }

  void trocaVariaveis(int i, int j)
  {
    swap(this->variaveisSolucao[i], this->variaveis[j]);
  }

  void atualizaQuadro(int iPivo, int jPivo)
  {
    double pivo = this->coeficientesRestricoes[iPivo].coeficientes[jPivo];
    this->coeficientesRestricoes[iPivo].dividePor(pivo);

    for (size_t linha = 0; linha < this->coeficientesRestricoes.size(); linha++)
    {
      if (linha != iPivo)
      {
        double termoLinha = this->coeficientesRestricoes[linha].coeficientes[jPivo];

        for (size_t l = 0; l < this->coeficientesRestricoes[linha].coeficientes.size(); l++)
        {
          this->coeficientesRestricoes[linha].coeficientes[l] -= this->coeficientesRestricoes[iPivo].coeficientes[l] * termoLinha;
        }
        this->coeficientesRestricoes[linha].termoIndependente -= this->coeficientesRestricoes[iPivo].termoIndependente * termoLinha;
      }

      double termoLinha = this->ultimaLinha[0].coeficientes[jPivo];
      for (size_t l = 0; l < this->ultimaLinha[0].coeficientes.size(); l++)
      {
        this->ultimaLinha[0].coeficientes[l] -= this->coeficientesRestricoes[iPivo].coeficientes[l] * termoLinha;
      }

      this->ultimaLinha[0].termoIndependente -= this->coeficientesRestricoes[iPivo].termoIndependente * termoLinha;
    }
  }
  int achaLinhaMenorQuociente(int j)
  {
    int iTrabalho = -1;
    double menorQuociente = 0;

    for (size_t i = 0; i < this->coeficientesRestricoes.size(); i++)
    {
      if (this->coeficientesRestricoes[i].coeficientes[j] > 0)
      {
        double quociente = this->coeficientesRestricoes[i].termoIndependente / this->coeficientesRestricoes[i].coeficientes[j];
        if (iTrabalho == -1 || quociente < menorQuociente)
        {
          menorQuociente = quociente;
          iTrabalho = i;
        }
      }
    }

    return iTrabalho;
  }

  void toString()
  {
    cout << "Variaveis: " << endl;
    for (auto item : variaveis)
    {
      cout << item << " ";
    }
    cout << endl;

    cout << "Variaveis solução: " << endl;
    for (auto item : variaveisSolucao)
    {
      cout << item << " ";
    }
    cout << endl;

    cout << "Restrições e ultima linha do quadro simplex: " << endl;
    for (auto item : coeficientesRestricoes)
    {
      cout << item.toString() << endl;
    }
    for (auto item : ultimaLinha)
    {
      cout << item.toString() << endl;
    }
  }
};

#endif