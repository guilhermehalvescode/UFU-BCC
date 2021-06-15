public class Quadrado extends Retangulo {
  public Quadrado(String nome, float x, float y) throws MedidaInvalidaException, IllegalArgumentException {
    super(nome, x, y);
    if(x != y) throw new MedidaInvalidaException("X e Y devem ser iguais para inicializar uma quadrado");
  }

  @Override
  public String toString() {
    return "Quadrado{" +
            "x=" + x +
            ", y=" + y +
            ", lado=" + this.getComprimento() +
            '}';
  }
}
