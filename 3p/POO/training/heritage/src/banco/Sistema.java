package banco;

import java.util.Scanner;

public class Sistema {

	public static void main(String[] args) {
		int escolha, nroConta, dia;
		String nome;
		float saldo, limite;
		ListaContaBancaria lista = new ListaContaBancaria();
		Scanner tecl = new Scanner(System.in);
		while(true) {
			System.out.println("---SISTEMA BANCÁRIO---");
			System.out.println("[1] Adicionar uma conta");
			System.out.println("[2] Remover uma conta");
			System.out.println("[3] Consultar uma conta");
			System.out.println("[4] Depositar em uma conta");
			System.out.println("[5] Sacar em uma conta");
			System.out.println("[6] Sair do sistema");
			escolha = tecl.nextInt();
			if(escolha == 6) break;
			try {
				switch (escolha) {
					case 1:
						System.out.println("Qual é o tipo de conta([1]Poupanca / [2]Especial): ");
						escolha = tecl.nextInt();
						tecl.nextLine();
						System.out.println("Digite o nome do cliente: ");
						nome = tecl.nextLine();
						System.out.println("Digite o número da conta do cliente: ");
						nroConta = tecl.nextInt();
						System.out.println("Digite o valor do saldo do cliente: ");
						saldo = tecl.nextFloat();
						limite = 0; dia = 0;
						if(escolha == 2) {
							System.out.println("Digite o valor do limite do cliente especial: ");
							limite = tecl.nextFloat();
						} else {
							System.out.println("Digite o dia do cliente poupanca: ");
							dia = tecl.nextInt();
						}
						lista.incluir(escolha == 2 ? new ContaEspecial(nome, nroConta, saldo, limite) : new ContaPoupanca(nome, nroConta, saldo, dia));
						break;
					case 2:
						System.out.println("Digite o número da conta do cliente a remover: ");
						nroConta = tecl.nextInt();
						lista.excluir(nroConta);
						break;
					case 3:
						System.out.println("Digite o número da conta do cliente a consultar: ");
						nroConta = tecl.nextInt();
						System.out.println(lista.obter(nroConta));
						break;
					case 4:
						System.out.println("Digite o número da conta do cliente a depositar: ");
						nroConta = tecl.nextInt();
						System.out.println("Digite o valor do deposito: ");
						saldo = tecl.nextFloat();
						lista.obter(nroConta).depositar(saldo);
						break;
					case 5:
						System.out.println("Digite o número da conta do cliente a sacar: ");
						nroConta = tecl.nextInt();
						System.out.println("Digite o valor do saque: ");
						saldo = tecl.nextFloat();
						lista.obter(nroConta).sacar(saldo);
						break;
					default:
						throw new IllegalStateException("Unexpected value: " + escolha);
				}
			} catch(Exception e) {
				System.err.println(e.getMessage());
			}
		}
	}

}
