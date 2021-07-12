public class Pessoa {
  private int id;
  private String nome;
  private static int incrementId;

  public Pessoa(String nome) throws Exception {
    this.setId(this.incrementId++);
    this.setNome(nome);
  }

  public int getId() {
    return this.id;
  }

  public void setId(int id) throws Exception {
    if(id < 0) throw new Exception("Id informado para pessoa inválido!");
    this.id = id;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) throws Exception {
    if(nome.isEmpty()) throw new Exception("Nome informado para pessoa inválido!");
    this.nome = nome;
  }

  @Override
  public String toString() {
    return "Pessoa{" +
            "id=" + id +
            ", nome='" + nome + '\'' +
            '}';
  }
}
