package apresentacao;

import java.util.Scanner;

import negocio.IFachadaSistema;
import negocio.Sistema;
import negocio.cliente.Cliente;

public class Principal {
	public static void main(String[] args) {
		Scanner tecl = new Scanner(System.in);
		IFachadaSistema fc = null;
		try {
			fc = Sistema.getFachada();
			while (true) {
				System.out.println("Informe seu NOME:");
				String nome = tecl.nextLine();

				if (nome.equalsIgnoreCase("fim"))
					break;
				System.out.println("Informe seu CPF:");
				String cpf = tecl.nextLine();

				Cliente c = new Cliente();
				c.setCpf(cpf);
				c.setNome(nome);
				try {
					fc.cadastrar(c);
					System.out.println("Cliente " + c.getNome() + " cadastrado com sucesso!!");
				} catch (Exception e) {
					// TODO Auto-generated catch block
					System.out.println(e.getMessage());
				}

			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}

		System.out.println("FIM DO PROGRAMA");
	}

}
