public interface Tridimensional extends Bidimensional {

  public float getZ();

  public void setZ(float z) throws MedidaInvalidaException;

  double obterVolume();
}
