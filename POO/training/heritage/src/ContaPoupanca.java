public class ContaPoupanca extends ContaBancaria {
  private int diaRendimento;
//  public ContaPoupanca(String nome) throws Exception {
//    super(nome);
//  }


  public int getDiaRendimento() {
    return this.diaRendimento;
  }

  public void setDiaRendimento(int diaRendimento) {
    this.diaRendimento = diaRendimento;
  }

  public void calcularNovoSaldo(float tx) throws Exception {
    if(tx < 0 || tx > 1) throw new Exception("Taxa inválida.");
    this.setSaldo(this.getSaldo() * (1.0f + tx));
  }
}
