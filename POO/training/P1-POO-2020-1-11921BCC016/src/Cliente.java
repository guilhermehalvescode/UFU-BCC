/*
Aluno: Guilherme Alves Carvalho
Matrícula: 11921BCC016
 */

public class Cliente {
  private int id;
  private String nome;
  private static int incrementId;

  public Cliente (String nome) throws Exception {
    this.setId(this.incrementId++);
    this.setNome(nome);
  }

  public int getId() {
    return this.id;
  }

  public String getNome() {
    return this.nome;
  }

  private void setId(int id) {
    this.id = id;
  }

  private void setNome(String nome) throws Exception {
    if(nome == null || nome.isEmpty()) throw new Exception("Nome do Cliente não informado");
    this.nome = nome;
  }

  @Override
  public String toString() {
    return "Cliente{" +
            "id=" + this.getId() +
            ", nome='" + this.getNome() + '\'' +
            '}';
  }

  public static void main(String[] args) {
    try {
      Cliente eu = new Cliente("Guilherme Alves Carvalho");
      System.out.println(eu.toString());
      Cliente erro = new Cliente("");
      System.out.println(erro);
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}
//  RESULTADO DE EXECUÇÃO DA MAIN
/*
  Cliente{id=0, nome='Guilherme Alves Carvalho'}
  Nome do Cliente não informado
 */
