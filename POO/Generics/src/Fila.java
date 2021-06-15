import java.util.Vector;

public class Fila<Type> {
  private Vector<Type> queue = new Vector<Type>();
  private int size = 0;

  public void porNaFila(Type item) throws IllegalArgumentException {
    if(item == null) throw new IllegalArgumentException("Item inválido");
    queue.insertElementAt(item, 0);
    size++;
  }

  public Type retirarDaFila() throws Exception {
    if(size <= 0) throw new Exception("Fila Vazia!");
    Type val = queue.get(size - 1);
    queue.remove(--size);
    return val;
  }

  public int tamanhoDaFila() {
    return size;
  }

  public static void main(String[] args) {
    Cliente jef = new Cliente("Jefferson");
    Cliente and = new Cliente("Anderson");
    Cliente joao = new Cliente("João");
    Produto joia = new Produto("Joia carbonizada", 100.45f);
    Produto medalha = new Produto("Medalha de ouro", 560.65f);
    Produto porcelana = new Produto("Porcelana Blindex", 700.45f);

    Fila<Cliente> clientes = new Fila<Cliente>();
    clientes.porNaFila(jef);
    System.out.println("Tamanho da fila de clientes: " + clientes.tamanhoDaFila());
    clientes.porNaFila(and);
    System.out.println("Tamanho da fila de clientes: " + clientes.tamanhoDaFila());
    clientes.porNaFila(joao);
    System.out.println("Tamanho da fila de clientes: " + clientes.tamanhoDaFila());


    Fila<Produto> produtos = new Fila<Produto>();
    produtos.porNaFila(joia);
    System.out.println("Tamanho da fila de produtos: " + produtos.tamanhoDaFila());
    produtos.porNaFila(medalha);
    System.out.println("Tamanho da fila de produtos: " + produtos.tamanhoDaFila());
    produtos.porNaFila(porcelana);
    System.out.println("Tamanho da fila de produtos: " + produtos.tamanhoDaFila());

    System.out.println("\nFila de clientes: ");
    int tam = clientes.tamanhoDaFila();
    for(int i = 0; i <= tam; i++) {
      try {
        System.out.println("\nTamanho atual da fila: " + clientes.tamanhoDaFila());
        Cliente cli = clientes.retirarDaFila();
        System.out.println("Cliente " + (i + 1) + ": " + cli);
        System.out.println("Tamanho da fila após remoção: " + clientes.tamanhoDaFila());
      } catch (Exception e) {
        System.out.println("Erro: " + e.getMessage());
      }
    }
    System.out.println("\nFila de produtos: ");
    tam = produtos.tamanhoDaFila();
    for(int i = 0; i <= tam; i++) {
      try {
        System.out.println("\nTamanho atual da fila: " + produtos.tamanhoDaFila());
        Produto prod = produtos.retirarDaFila();
        System.out.println("Produto " + (i + 1) + ": " + prod);
        System.out.println("Tamanho da fila após remoção: " + produtos.tamanhoDaFila());

      } catch (Exception e) {
        System.out.println("Erro: " + e.getMessage());
      }
    }
  }
}
