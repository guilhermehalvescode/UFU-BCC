package exer;

public class Vendedor extends Funcionario {
  private float totalVendas = 0;
  final float comissao = 0.05f;
  public Vendedor(String nome, String rg, float sal) throws Exception {
    super(nome, rg, sal);
  }

  public float getTotalVendas() {
    return this.totalVendas;
  }

  public void setTotalVendas(float totalVendas) throws Exception {
    if(totalVendas < 0) throw new Exception("Valor de vendas inválido");
    this.totalVendas = totalVendas;
  }

  public void acumTotalVendas(float valorVenda) throws Exception {
    if(valorVenda < 0) throw new Exception("Valor de venda inválido");
    this.setTotalVendas(this.getTotalVendas() + valorVenda);
  }

  public float getComissao() {
    return comissao;
  }

  public float getSalTotal() throws Exception {
    float valorComiss = this.getTotalVendas() * this.getComissao();
    this.setTotalVendas(0);
    return this.getSalBase() + valorComiss;
  }

  @Override
  public String toString() {
    return  super.toString() +
            " {" +
            "totalVendas=" + totalVendas +
            ", comissao=" + comissao +
            '}';
  }
}
