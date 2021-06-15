public class Triangulo extends Formas {
  private float base, altura;
  /*
  Triangulo com base no eixo x e altura ao longo do eixo y
  o ponto fica no topo do triangulo (convenção adotada)
  */
  public Triangulo(String nome, float x, float y) throws IllegalArgumentException, MedidaInvalidaException {
    super(nome, x, y);
    this.setBase(2 * x);
    this.setAltura(y);
  }


  public float getBase() {
    return base;
  }

  private void setBase(float base) {
    this.base = base;
  }

  public float getAltura() {
    return altura;
  }

  private void setAltura(float altura) {
    this.altura = altura;
  }

  @Override
  public double obterArea() {
    return (base * altura) / 2;
  }

  @Override
  public String toString() {
    return "Triangulo{" +
            "x=" + x +
            ", y=" + y +
            ", base=" + base +
            ", altura=" + altura +
            '}';
  }
}
