public class Retangulo extends Formas {
  private float comprimento, altura;

  public Retangulo(String nome, float x, float y) throws MedidaInvalidaException, IllegalArgumentException {
    super(nome, x, y);
    this.setComprimento(x);
    this.setAltura(y);
  }

  public float getAltura() {
    return altura;
  }

  private void setAltura(float altura) {
    this.altura = altura;
  }

  public float getComprimento() {
    return comprimento;
  }

  private void setComprimento(float comprimento) {
    this.comprimento = comprimento;
  }

  @Override
  public double obterArea() {
    return comprimento * altura;
  }

  @Override
  public String toString() {
    return "Retangulo{" +
            "x=" + x +
            ", y=" + y +
            ", comprimento=" + comprimento +
            ", altura=" + altura +
            '}';
  }
}
