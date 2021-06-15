/*
Aluno: Guilherme Alves Carvalho
Matrícula: 11921BCC016
 */

import java.util.ArrayList;

public class Caderneta {
  private int id;
  private Cliente cliente;
  private ArrayList<Item> itens = new ArrayList<>();
  private static int incrementId;

  public Caderneta(Cliente cli) throws Exception {
    this.setId(this.incrementId++);
    this.setCliente(cli);
  }

  public Cliente getCliente() {
    return this.cliente;
  }

  private void setCliente(Cliente cliente) throws Exception {
    if(cliente == null) throw new Exception("Cliente inválido");
    this.cliente = cliente;
  }

  public int getId() {
    return this.id;
  }

  private void setId(int id) throws Exception {
    if(id < 0) throw new Exception("Id para cliente inválido");
    this.id = id;
  }

  public void adicione(char tipo, String historico, float valor) throws Exception {
    Item newItem = new Item(tipo, historico, valor);
    itens.add(newItem);
  }

  public ArrayList<Item> listar() {
    return this.itens;
  }

  public float calculaSaldo() {
    float saldo = 0;
    for(int i = 0; i < itens.size(); i++) {
      Item temp = itens.get(i);
      char tipo = temp.getTipo();
      float valor = temp.getValor();
      saldo += (tipo == 'C') ? valor : (-valor);
    }
    return saldo;
  }

  public static void main(String[] args) {
    try {
      Cliente eu = new Cliente("Guilherme Alves Carvalho");
      Caderneta cader = new Caderneta(eu);
      System.out.println("Caderneta: \nid: " + cader.getId() + "\nCliente: " + cader.getCliente() + "\n");
      cader.adicione('C', "Deposito salário", 1000.65f);
      cader.adicione('D', "Pagamento luz", 100.65f);
      cader.adicione('D', "Almoço", 12.30f);
      cader.adicione('C', "Freelancing", 300.65f);
      ArrayList<Item> itens = cader.listar();
      System.out.println("Monstrando Caderneta!!");
      for(int i = 0; i < itens.size(); i++) {
        System.out.println(itens.get(i));
      }
      System.out.println("Saldo: " + cader.calculaSaldo());
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}

//RESULTADO DE EXECUÇÃO DA MAIN
/*
  Caderneta:
  id: 0
  Cliente: Cliente{id=0, nome='Guilherme Alves Carvalho'}

  Monstrando Caderneta!!
  Item{data=Thu Apr 29 10:33:56 BRT 2021, tipo=C, historico='Deposito salário', valor=1000.65}
  Item{data=Thu Apr 29 10:33:56 BRT 2021, tipo=D, historico='Pagamento luz', valor=100.65}
  Item{data=Thu Apr 29 10:33:56 BRT 2021, tipo=D, historico='Almoço', valor=12.3}
  Item{data=Thu Apr 29 10:33:56 BRT 2021, tipo=C, historico='Freelancing', valor=300.65}
  Saldo: 1188.35
 */
