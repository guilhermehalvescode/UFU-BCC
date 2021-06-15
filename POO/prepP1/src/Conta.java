import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Conta {
  private static int id;
  private int nroConta;
  private Pessoa cliente;
  private ArrayList<Lancamento> lancamentos = new ArrayList<>();

  public Conta(Pessoa cli) throws Exception {
    this.setCliente(cli);
    this.setNroConta();
  }

  public Conta(int nroConta, Pessoa cli) throws Exception {
    this.setCliente(cli);
    this.setNroConta(nroConta);
  }

  public String getCliente() {
    return this.cliente.toString();
  }

  public void setCliente(Pessoa cliente) throws Exception {
    if(cliente == null) throw new Exception("Cliente informado para conta inválido!");
    this.cliente = cliente;
  }

  public int getNroConta() {
    return this.nroConta;
  }

  public void setNroConta() {
    this.nroConta = id++;
  }

  public void setNroConta(int nroConta) throws Exception {
    if(nroConta < 0) throw new Exception("Número informado para conta inválido!");
    this.nroConta = nroConta;
  }

  public void addLancamento(char tipo, String historico, float valor) throws Exception {
    Lancamento lm = new Lancamento(tipo, historico, valor);
    lancamentos.add(lm);
  }

  public void listLancamentos() {
    float saldo = 0;
    float valor;
    Lancamento temp;
    System.out.println("Listando lançamentos...");
    for(int i = 0; i < lancamentos.size(); i++) {
      temp = lancamentos.get(i);
      valor = temp.getValor();
      saldo += temp.getTipo() == 'D' ? (-valor) : valor;
      System.out.println(temp);
    }
    System.out.println("Saldo da conta: " + saldo);
  }

  @Override
  public String toString() {
    return "Conta{" +
            "nroConta=" + nroConta +
            ", cliente=" + cliente +
            '}';
  }

  public static void main(String[] args) {
    try {
      int nroC;
      String nome, descricao;
      Pessoa cliente;
      Conta cont;
      char tipo;
      float valor;

      Scanner tecl = new Scanner(System.in);
      System.out.println("Digite o nome do cliente: ");
      nome = tecl.nextLine();
      cliente = new Pessoa(nome);
      System.out.println("Bem vindo! -> " + cliente);
      System.out.println("Digite o número da conta do cliente: ");
      nroC = tecl.nextInt();
      cont = new Conta(nroC, cliente);
      System.out.println("Realizar lançamentos em " + cont.getCliente() + "...");
      while(true) {
        try {
          System.out.println("Digite uma operação ('C' ou 'D' ou 'S'): ");
          if(tecl.hasNext()) tecl.skip("\n");
          tipo = tecl.next().charAt(0);
          if(tipo == 'S') break;
          System.out.println("Digite a descrição: ");
          if(tecl.hasNextLine()) tecl.skip("\n");
          descricao = tecl.nextLine();
          System.out.println("Digite o valor: ");
          valor = tecl.nextFloat();
          cont.addLancamento(tipo, descricao, valor);
        } catch (InputMismatchException e) {
          System.out.println("Valor informado inválido!!");
        } catch (Exception e) {
          System.out.println(e.getMessage());
        }
      }
      cont.listLancamentos();
      tecl.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}
