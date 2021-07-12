public class Produto {
  private String nome;
  private float valor;
  public Produto(String nome, float val) throws IllegalArgumentException {
    this.setNome(nome);
    this.setValor(val);
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) throws IllegalArgumentException {
    if(nome == null) throw new IllegalArgumentException("Nome inválido!");
    this.nome = nome;
  }

  public float getValor() {
    return valor;
  }

  public void setValor(float valor) throws IllegalArgumentException {
    if(valor <= 0) throw new IllegalArgumentException("Valor inválido para valor de produto!");
    this.valor = valor;
  }

  @Override
  public String toString() {
    return "Produto{" +
            "nome='" + nome + '\'' +
            ", valor=" + valor +
            '}';
  }
}
