package banco;

import banco.exceptions.*;

public class ListaContaBancaria {
  private ContaBancaria[] list = new ContaBancaria[10];
  private int cont = 0;

  public void incluir(ContaBancaria cli) throws OverflowException {
    if(cont > 9) throw new OverflowException("Máximo de registros de contas bancárias");
    list[cont++] = cli;
  }

  public void excluir(int numConta) throws UnderflowException, NotFoundException {
    if(cont < 1) throw new UnderflowException("Sem registros de contas bancárias");

    int posRemovido = findByNumConta(numConta);
    for(int i = cont - 1; i > posRemovido; i--) list[i - 1] = list[i];
    cont--;
  }

  public ContaBancaria obter(int numConta) throws NotFoundException {
    return list[findByNumConta(numConta)];
  }

  private int findByNumConta(int nmConta) throws NotFoundException {
    for(int i = 0 ; i < cont; i++) {
      if(list[i].getNum_conta() == nmConta)
        return i;
    }
    throw new NotFoundException("Conta com número: " + nmConta + " não encontrada");
  }

}
