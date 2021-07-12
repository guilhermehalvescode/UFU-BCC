/*
* Aluno: Guilherme Alves Carvalho
* Matrícula: 11921BCC016
* */


public class ItemDeEstoque {
  private int id;
  private String nome;
  private float preco;
  private int qtdEstoque;
  private int estoqueMaximo;
  private static int autoId;

  public ItemDeEstoque(String nome, float preco, int qtdEstoque, int estoqueMaximo) throws IllegalArgumentException {
    this.setId(this.autoId++);
    this.setNome(nome);
    this.setPreco(preco);
    this.setQtdEstoque(qtdEstoque);
    this.setEstoqueMaximo(estoqueMaximo);
  }

  public int getId() {
    return id;
  }

  private void setId(int id) throws IllegalArgumentException {
    if(id < 0) throw new IllegalArgumentException("Id inválido");
    this.id = id;
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) throws IllegalArgumentException {
    if(nome == null || nome.isEmpty()) throw new IllegalArgumentException("Nome inválido");
    this.nome = nome;
  }

  public float getPreco() {
    return preco;
  }

  public void setPreco(float preco) {
    if(preco <= 0) throw new IllegalArgumentException("Preço inválido");
    this.preco = preco;
  }

  public int getQtdEstoque() {
    return qtdEstoque;
  }

  public void setQtdEstoque(int qtdEstoque) {
    if(qtdEstoque < 0) throw new IllegalArgumentException("Quantidade de estoque inválido");
    this.qtdEstoque = qtdEstoque;
  }

  public int getEstoqueMaximo() {
    return estoqueMaximo;
  }

  public void setEstoqueMaximo(int estoqueMaximo) {
    if(estoqueMaximo <= 0) throw new IllegalArgumentException("Estoque máximo inválido");
    this.estoqueMaximo = estoqueMaximo;
  }

  public void baixarEstoque(int quantidade) throws EstoqueBaixoException, IllegalArgumentException {
    if(quantidade <= 0) throw new IllegalArgumentException("Quantidade informada inválida");
    int qntEstoque = this.getQtdEstoque();
    if(quantidade > qntEstoque) throw new EstoqueBaixoException("Quantidade " + qntEstoque + " em estoque insuficiente para atender demanda de " + quantidade);
    this.setQtdEstoque(qntEstoque - quantidade);
  }

  public void elevarEstoque(int quantidade) throws EstoqueElevadoException, IllegalArgumentException {
    if(quantidade <= 0) throw new IllegalArgumentException("Quantidade informada inválida");
    int qntEstoqueMax = this.getEstoqueMaximo();
    int qntNova = this.getQtdEstoque() + quantidade;
    if(qntNova > qntEstoqueMax) throw new EstoqueElevadoException();
    this.setQtdEstoque(qntNova);
  }

  @Override
  public String toString() {
    return "ItemDeEstoque{" +
            "id=" + id +
            ", nome='" + nome + '\'' +
            ", preco=" + preco +
            ", qtdEstoque=" + qtdEstoque +
            ", estoqueMaximo=" + estoqueMaximo +
            '}';
  }
}
