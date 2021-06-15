//Piramide Quadrangular
public class PiramideQuadrangular extends Quadrado implements Tridimensional {
  private float z;
  /*
  * Mesma convenção adotada no triangulo, o ponto na extremidade do quadrado e z representa a altura
  * */
  public PiramideQuadrangular(String nome, float x, float y, float z) throws IllegalArgumentException, MedidaInvalidaException {
    super(nome, x, y);
    this.setZ(z);
  }


  @Override
  public float getZ() {
    return z;
  }

  @Override
  public void setZ(float z) throws MedidaInvalidaException {
    if(z <= 0) throw new MedidaInvalidaException("Valor inválido para a coordenada Z");
    this.z = z;
  }

  @Override
  public double obterArea() {
    double ladoQuadrado = super.getAltura();
    double geratriz = Math.hypot(ladoQuadrado / 2, this.getZ());
    double areaLados = 2 * (ladoQuadrado * geratriz);
    return super.obterArea() + areaLados;
  }

  @Override
  public double obterVolume() {
    return (super.obterArea() * this.getZ()) / 3;
  }

  @Override
  public String toString() {
    return "PiramideQuadrangular{" +
            "x=" + x +
            ", y=" + y +
            ", z=" + z +
            '}';
  }
}
