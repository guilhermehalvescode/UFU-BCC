public class Losango extends Formas {
  private float d1;
  private float d2;

  public Losango(String nome, float x, float y, float d1, float d2) throws MedidaInvalidaException, IllegalArgumentException {
    super(nome, x, y);
    this.setD1(d1);
    this.setD2(d2);
  }

  public float getD1() {
    return d1;
  }

  private void setD1(float d1) throws MedidaInvalidaException {
    if(d1 <= 0) throw new MedidaInvalidaException("Valor inválido para a diagonal um");
    this.d1 = d1;
  }

  public float getD2() {
    return d2;
  }

  private void setD2(float d2) throws MedidaInvalidaException {
    if(d2 <= 0) throw new MedidaInvalidaException("Valor inválido para a diagonal dois");
    this.d2 = d2;
  }

  @Override
  public double obterArea() {
    return (d1 * d2) / 2;
  }

  @Override
  public String toString() {
    return "Losango{" +
            "x=" + x +
            ", y=" + y +
            ", d1=" + d1 +
            ", d2=" + d2 +
            '}';
  }
}
