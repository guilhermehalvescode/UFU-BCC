public abstract class Formas implements Bidimensional {
  private String nome;
  float x, y;
  public Formas(String nome, float x, float y) throws IllegalArgumentException, MedidaInvalidaException {
    this.setX(x);
    this.setY(y);
    this.setNome(nome);
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) throws IllegalArgumentException {
    if(nome == null || nome.isEmpty()) throw new IllegalArgumentException("Valor inválido para o nome");
    this.nome = nome;
  }

  public float getX() {
    return x;
  }

  public void setX(float x) throws MedidaInvalidaException {
    if(x <= 0) throw new MedidaInvalidaException("Valor inválido para a coordenada X");
    this.x = x;
  }

  public float getY() {
    return y;
  }

  public void setY(float y) throws MedidaInvalidaException {
    if(y <= 0) throw new MedidaInvalidaException("Valor inválido para a coordenada Y");
    this.y = y;
  }
}
