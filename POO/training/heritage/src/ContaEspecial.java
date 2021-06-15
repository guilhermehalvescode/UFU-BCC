public class ContaEspecial extends ContaBancaria {
  private float limite;


  public float getLimite() {
    return this.limite;
  }

  public void setLimite(float limite) {
    this.limite = limite;
  }

  @Override
  public float sacar(float valor) throws Exception {
    if(valor > this.getSaldo() + this.getLimite())
      throw new Exception("Valor inválido para saque.");
    this.setSaldo(this.getSaldo() - valor);
    return this.getSaldo() - valor;
  }
}
