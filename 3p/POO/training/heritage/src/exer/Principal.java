package exer;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Principal {

  private static int getFuncionario(String nome, Funcionario[] funcs, int tam) {
    for (int i = 0; i < tam; i++) {
      if(funcs[i].getNome().equals(nome))
        return i;
    }
    return -1;
  }


  public static void main(String[] args) {
    Funcionario[] funcs = new Funcionario[10];
    int cont = 0, escolha, i;
    float valor;
    char tipo;
    String nome, rg;
    Scanner tecl = new Scanner(System.in);
    while(true) {
      System.out.println("------FUNCIONÁRIOS------");
      System.out.println("[1] Adicionar um funcionário");
      System.out.println("[2] Mostrar todos os funcionários");
      System.out.println("[3] Marcar horas extras/vendas");
      System.out.println("[4] Pagar salário de um funcionário");
      System.out.println("[5] Sair do sistema");
      escolha = tecl.nextInt();
      if(escolha == 5) break;
      try {
        switch (escolha) {
          case 1:
            tecl.nextLine();
            System.out.println("Digite o nome do funcionário: ");
            nome = tecl.nextLine();
            System.out.println("Digite o rg do funcionário: ");
            rg = tecl.nextLine();
            System.out.println("Digite o salario do funcionário: ");
            valor = tecl.nextFloat();
            tecl.nextLine();
            System.out.println("Funcionário é do vendas ou administrativo? (v/a)");
            tipo = tecl.next().charAt(0);
            funcs[cont++] = tipo == 'v' ? new Vendedor(nome, rg, valor) : new Administrativo(nome, rg, valor);
            break;
          case 2:
            System.out.println("Listando funcionários...");
            for (i = 0; i < cont; i++) {
              System.out.println(funcs[i]);
            }
            break;
          case 3:
            tecl.nextLine();
            do {
              System.out.println("Digite o nome do funcionário: ");
              nome = tecl.nextLine();
              i = getFuncionario(nome, funcs, cont);
            } while(i == -1);
            if(funcs[i] instanceof Vendedor) {
              System.out.println("Digite o valor total de vendas do vendedor: ");
              valor = tecl.nextFloat();
              ((Vendedor) funcs[i]).acumTotalVendas(valor);
            } else {
              System.out.println("Digite o total de horas extras do administrador: ");
              valor = tecl.nextFloat();
              ((Administrativo) funcs[i]).acumTotalHoras(valor);
            }
            break;
          case 4:
            tecl.nextLine();
            do {
              System.out.println("Digite o nome do funcionário: ");
              nome = tecl.nextLine();
              i = getFuncionario(nome, funcs, cont);
            } while(i == -1);
            System.out.println(funcs[i]);
            System.out.println(funcs[i].getSalTotal());
            break;
          default:
            System.out.println("Escolha inválida!!");
            break;
        }
      } catch (InputMismatchException e){
        System.out.println("Digite um valor válido!!");
      } catch (ArrayIndexOutOfBoundsException e) {
        System.out.println("Quantidade máxima de funcionarios alcançada!!");
      } catch (Exception e) {
        System.out.println("Ocorreu um erro: " + e.getMessage());
      }
    }
    tecl.close();
  }
}
