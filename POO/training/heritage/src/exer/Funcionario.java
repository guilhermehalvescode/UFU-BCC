package exer;

public abstract class Funcionario {
  private String nome;
  private String RG;
  private float salBase;

  public Funcionario(String nome, String rg, float sal) throws Exception {
    this.setNome(nome);
    this.setRG(rg);
    this.setSalBase(sal);
  }

  public String getNome() {
    return nome;
  }

  private void setNome(String nome) throws Exception {
    if(nome == null || nome.isEmpty()) throw new Exception("Nome inválido para funcionário.");
    this.nome = nome;
  }

  public String getRG() {
    return RG;
  }

  private void setRG(String rg) throws Exception {
    if(rg == null || rg.isEmpty()) throw new Exception("Rg inválido para funcionário.");
    this.RG = rg;
  }

  public float getSalBase() {
    return salBase;
  }

  private void setSalBase(float salBase) throws Exception {
    if(salBase < 0) throw new Exception("Salário base inválido para funcionário.");
    this.salBase = salBase;
  }

  @Override
  public String toString() {
    return "Funcionario{" +
            "nome='" + nome + '\'' +
            ", RG='" + RG + '\'' +
            ", salBase=" + salBase +
            '}';
  }

  public abstract float getSalTotal() throws Exception;
}
