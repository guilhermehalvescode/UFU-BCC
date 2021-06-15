/*
 * Aluno: Guilherme Alves Carvalho
 * Matrícula: 11921BCC016
 * */

public class CD extends ItemDeEstoque {
  private int nFaixas;


  public CD(String nome, float preco, int qtdEstoque, int estoqueMaximo, int nFaixas) throws IllegalArgumentException {
    super(nome, preco, qtdEstoque, estoqueMaximo);
    this.setnFaixas(nFaixas);
  }

  public int getnFaixas() {
    return nFaixas;
  }

  public void setnFaixas(int nFaixas) {
    if(nFaixas <= 0) throw new IllegalArgumentException("Número de faixas inválido");
    this.nFaixas = nFaixas;
  }

  @Override
  public String toString() {
    return super.toString() +
            " CD{" +
            "nFaixas=" + nFaixas +
            '}';
  }
}
