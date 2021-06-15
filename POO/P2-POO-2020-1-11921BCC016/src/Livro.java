/*
 * Aluno: Guilherme Alves Carvalho
 * Matrícula: 11921BCC016
 * */

public class Livro extends ItemDeEstoque{
  private String autor;

  public Livro(String nome, float preco, int qtdEstoque, int estoqueMaximo, String autor) throws IllegalArgumentException {
    super(nome, preco, qtdEstoque, estoqueMaximo);
    this.setAutor(autor);
  }

  public String getAutor() {
    return autor;
  }

  public void setAutor(String autor) {
    if(autor == null || autor.isEmpty()) throw new IllegalArgumentException("Nome do autor inválido");
    this.autor = autor;
  }

  @Override
  public String toString() {
    return super.toString() +
            " Livro{" +
            "autor='" + autor + '\'' +
            '}';
  }
}
