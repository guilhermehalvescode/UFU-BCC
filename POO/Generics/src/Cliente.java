public class Cliente {
  private String nome;

  public Cliente(String nome) throws IllegalArgumentException {
    this.setNome(nome);
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) throws IllegalArgumentException {
    if(nome == null) throw new IllegalArgumentException("Nome inválido!");
    this.nome = nome;
  }

  @Override
  public String toString() {
    return "Cliente{" +
            "nome='" + nome + '\'' +
            '}';
  }
}
