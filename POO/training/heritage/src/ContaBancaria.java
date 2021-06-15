public class ContaBancaria {
  private String cliente;
  private int num_conta;
  private float saldo;
  private static int incId;

//  public ContaBancaria(String nome) throws Exception {
//    this.setCliente(nome);
//    this.setNum_conta(this.incId++);
//    this.setSaldo(0);
//  }

  public String getCliente() {
    return this.cliente;
  }

  public void setCliente(String cliente) throws Exception {
    if(cliente == null || cliente.isEmpty()) throw new Exception("Nome inválido para cliente.");
    this.cliente = cliente;
  }

  public int getNum_conta() {
    return this.num_conta;
  }

  public void setNum_conta(int num_conta) throws Exception {
    if(num_conta < 0) throw new Exception("Num conta inválido para cliente.");
    this.num_conta = num_conta;
  }

  public float getSaldo() {
    return this.saldo;
  }

  public void setSaldo(float saldo) throws Exception {
    if(saldo < 0) throw new Exception("Saldo inválido para cliente.");
    this.saldo = saldo;
  }

  public float sacar(float valor) throws Exception {
    if(valor <= 0) throw new Exception("Valor inválido para saque.");
    this.setSaldo(this.getSaldo() - valor);
    return valor;
  }

  public void depositar(float valor) throws Exception {
    if(valor <= 0) throw new Exception("Valor inválido para saque.");
    this.setSaldo(this.getSaldo() + valor);
  }
}
