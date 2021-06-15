public class Cubo extends Quadrado implements Tridimensional {
  private float z;
  public Cubo(String nome, float x, float y, float z) throws MedidaInvalidaException, IllegalArgumentException {
    super(nome, x, y);
    this.setZ(z);
  }

  public float getZ() {
    return z;
  }

  public void setZ(float z) throws MedidaInvalidaException {
    if(z <= 0 || z != this.getAltura()) throw new MedidaInvalidaException("Valor inválido para a coordenada Z");
    this.z = z;
  }

  @Override
  public double obterArea() {
    return super.obterArea() * 6;
  }

  public double obterVolume() {
    return super.obterArea() * this.getZ();
  }

  @Override
  public String toString() {
    return "Cubo{" +
            "x=" + x +
            ", z=" + z +
            ", y=" + y +
            ", aresta=" + this.getAltura() +
            '}';
  }
}
