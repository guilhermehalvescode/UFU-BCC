/*
 * Aluno: Guilherme Alves Carvalho
 * Matrícula: 11921BCC016
 * */
public class DVDs extends ItemDeEstoque {
  private float duracao;

  public DVDs(String nome, float preco, int qtdEstoque, int estoqueMaximo, float duracao) throws IllegalArgumentException {
    super(nome, preco, qtdEstoque, estoqueMaximo);
    this.setDuracao(duracao);
  }

  public float getDuracao() {
    return duracao;
  }

  public void setDuracao(float duracao) {
    if(duracao <= 0) throw new IllegalArgumentException("Duração inválida");
    this.duracao = duracao;
  }

  @Override
  public String toString() {
    return super.toString() +
            " DVDs{" +
            "duracao=" + duracao +
            '}';
  }
}
