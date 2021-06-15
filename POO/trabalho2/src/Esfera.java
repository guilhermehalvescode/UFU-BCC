public class Esfera extends Circulo implements Tridimensional {
  private float z;

  public Esfera(String nome, float x, float y, float z) throws MedidaInvalidaException, IllegalArgumentException {
    super(nome, x, y);
    this.setZ(z);
    this.setRaio(x, y, z);
  }

  public float getZ() {
    return z;
  }

  public void setZ(float z) throws MedidaInvalidaException {
    if(z <= 0) throw new MedidaInvalidaException("Valor inválido para a coordenada Z");
    this.z = z;
  }


  private void setRaio(float x, float y, float z) {
    super.setRaio(Math.hypot(Math.hypot(x, y), z));
  }

  @Override
  public double obterArea() {
    return super.obterArea() * 4;
  }
  public double obterVolume() {
    return (this.obterArea() * this.getRaio()) / 3;
  }

  @Override
  public String toString() {
    return "Esfera{" +
            "raio=" + raio +
            ", z=" + z +
            ", x=" + x +
            ", y=" + y +
            '}';
  }
}
