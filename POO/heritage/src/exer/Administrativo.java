package exer;

public class Administrativo extends Funcionario {
  private float totalHoras = 0;
  public Administrativo(String nome, String rg, float sal) throws Exception {
    super(nome, rg, sal);
  }

  public float getTotalHoras() {
    return this.totalHoras;
  }

  public void setTotalHoras(float totalHoras) throws Exception {
    if(totalHoras < 0) throw new Exception("Valor de horas inválido");
    this.totalHoras = totalHoras;
  }

  public void acumTotalHoras(float horas) throws Exception {
    if(horas < 0) throw new Exception("Valor de horas inválido");
    this.setTotalHoras(this.getTotalHoras() + horas);
  }

  public float getSalTotal() throws Exception {
    float valorExtra = (this.getTotalHoras() * this.getSalBase())/100.0f;
    this.setTotalHoras(0);
    return this.getSalBase() + valorExtra;
  }

  @Override
  public String toString() {
    return  super.toString() +
            " {" +
            "totalHoras=" + totalHoras +
            '}';
  }
}
