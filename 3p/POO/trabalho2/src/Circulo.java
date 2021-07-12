public class Circulo extends Formas {
  double raio;
  public Circulo(String nome, float x, float y) throws MedidaInvalidaException, IllegalArgumentException {
    super(nome, x, y);
    this.setRaio(Math.hypot(x, y));
  }

  public double getRaio() {
    return raio;
  }

  protected void setRaio(double raio) {
    this.raio = raio;
  }

  @Override
  public double obterArea() {
    return (double) Math.PI * raio * raio;
  }

  @Override
  public String toString() {
    return "Circulo{" +
            "raio=" + raio +
            ", x=" + x +
            ", y=" + y +
            '}';
  }
}
