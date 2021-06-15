/*
Aluno: Guilherme Alves Carvalho
Matrícula: 11921BCC016
*/

import java.util.ArrayList;
import java.util.Scanner;

public class Principal {


  public static int buscaCliente(String nome, ArrayList<Caderneta> cad) {
    for(int i = 0; i < cad.size(); i++) {
      if(nome.equals(cad.get(i).getCliente().getNome()))
        return i;
    }
    return -1;
  }

  public static void main(String[] args) {
    int escolha, ind;
    String nome;
    ArrayList<Caderneta> cadernetas = new ArrayList<>();
    Scanner tecl = new Scanner(System.in);
    while(true) {
      System.out.println("1 – Cadastrar um cliente");
      System.out.println("2 – Criar item na caderneta");
      System.out.println("3 – Listar itens de uma caderneta");
      System.out.println("4 – Sair");
      do {
        System.out.println("Digite a escolha:");
        escolha = tecl.nextInt();
      } while(escolha < 1 || escolha > 4);

      if(escolha == 4) break;
      tecl.nextLine();
      try {
        switch (escolha) {
          case 1:
            System.out.println("Digite o nome do cliente: ");
            nome = tecl.nextLine();
            cadernetas.add(new Caderneta(new Cliente(nome)));
            break;
          case 2:
            System.out.println("Digite o nome do cliente: ");
            nome = tecl.nextLine();
            ind = buscaCliente(nome, cadernetas);
            if(ind == -1) throw new Exception("Cliente não encontrado");
            System.out.println("Digite o tipo do Item: ");
            char tipo = tecl.next().charAt(0);
            System.out.println("Digite o histórico do Item: ");
            tecl.nextLine();
            String historico = tecl.nextLine();
            System.out.println("Digite o valor do Item: ");
            float valor = tecl.nextFloat();
            tecl.nextLine();
            cadernetas.get(ind).adicione(tipo, historico, valor);
            break;
          case 3:
            System.out.println("Digite o nome do cliente: ");
            nome = tecl.nextLine();
            ind = buscaCliente(nome, cadernetas);
            if(ind == -1) throw new Exception("Cliente não encontrado");
            Caderneta cader = cadernetas.get(ind);
            ArrayList<Item> itens = cader.listar();
            System.out.println("Monstrando Caderneta!!");
            for(int i = 0; i < itens.size(); i++) {
              System.out.println(itens.get(i));
            }
            System.out.println("Saldo: " + cader.calculaSaldo());
            break;
          default:
            throw new Exception("Opção inválida");
        }
      } catch(Exception e) {
        System.out.println("Ocorreu um erro: " + e.getMessage());
      }
    }
    tecl.close();
  }
}

//  RESULTADO DE EXECUÇÃO DA MAIN
/*
  1 – Cadastrar um cliente
  2 – Criar item na caderneta
  3 – Listar itens de uma caderneta
  4 – Sair
  Digite a escolha:
  1
  Digite o nome do cliente:
  Guilherme Alves
  1 – Cadastrar um cliente
  2 – Criar item na caderneta
  3 – Listar itens de uma caderneta
  4 – Sair
  Digite a escolha:
  2
  Digite o nome do cliente:
  Guilherme Alves
  Digite o tipo do Item:
  C
  Digite o histórico do Item:
  Apostando no Galo
  Digite o valor do Item:
  500,65
  1 – Cadastrar um cliente
  2 – Criar item na caderneta
  3 – Listar itens de uma caderneta
  4 – Sair
  Digite a escolha:
  3
  Digite o nome do cliente:
  Guilherme Alves
  Monstrando Caderneta!!
  Item{data=Thu Apr 29 11:29:40 BRT 2021, tipo=C, historico='Apostando no Galo', valor=500.65}
  Saldo: 500.65
  1 – Cadastrar um cliente
  2 – Criar item na caderneta
  3 – Listar itens de uma caderneta
  4 – Sair
  Digite a escolha:
  4
 */
