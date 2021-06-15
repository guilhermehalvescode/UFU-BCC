package negocio.cliente;
import java.util.ArrayList;
import java.util.Iterator;

import dados.CadastroGenerico;
import dados.Gravavel;
import dados.RepositorioGenericoTXT;

public class ClienteDAO extends CadastroGenerico<negocio.cliente.Cliente> {
	
	static private int cont;
	
	public int getNextId() {
		// TODO Auto-generated method stub
		return ++cont;
	}
	@Override
	public Cliente busca(String chave) throws Exception {
		// TODO Auto-generated method stub
		for (int i = 0; i < this.lista.size(); i++) {
			Cliente c = lista.get(i);
			if (c.getCpf().equals(chave)){
				return c;
			}
		}
		throw new Exception("Cliente com chave "+chave+" não encontrado!");
	}

	@Override
	public int buscaPosicao(Cliente t) throws Exception {
		for (int i = 0; i < this.lista.size(); i++) {
			Cliente c = lista.get(i);
			if (c == t){
				return i;
			}
		}
		throw new Exception("Cliente com "+t.getCpf()+" não encontrado!");
	}

	/**
	 * @param repo
	 */
	public ClienteDAO() {
		RepositorioGenericoTXT<Cliente> r = new RepositorioClienteTXT();
		r.setNomeArquivo("CLIENTE.TXT");
		this.setRepo(r);
	}
	
	

	/* (non-Javadoc)
	 * @see dados.CadastroGenerico#recuperar()
	 */
	@Override
	public ArrayList<Cliente> recuperar() throws Exception {
		// TODO Auto-generated method stub
		ArrayList <Cliente> l = super.recuperar();
		cont = l.get(l.size()-1).getId();
		return l;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ClienteDAO dao = new ClienteDAO();
		
		
		Cliente c0 = new Cliente();
		c0.setCpf("000.000.000-00");
		c0.setId(0);
		c0.setNome("Ze Roberto");
		dao.incluir(c0);
		
		Cliente c1 = new Cliente();
		c1.setCpf("111.111.111-11");
		c1.setId(1);
		c1.setNome("Hum Berto");
		dao.incluir(c1);
		
		Cliente c2 = new Cliente();
		c2.setCpf("222.222.222-22");
		c2.setId(2);
		c2.setNome("Dois Berto");
		dao.incluir(c2);
		
		try {
			dao.salvar();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		ClienteDAO dao1 = new ClienteDAO();
		ArrayList<Cliente> clientes;
		try {
			clientes = dao1.recuperar();
			for (Cliente cliente : clientes) {
				System.out.println(cliente);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	

	
	
}
