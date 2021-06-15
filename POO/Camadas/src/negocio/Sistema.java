package negocio;

import negocio.cliente.Cliente;
import negocio.cliente.ClienteDAO;
import negocio.produto.Produto;
import negocio.produto.ProdutoDAO;

public class Sistema implements IFachadaSistema {

	ClienteDAO dao = new ClienteDAO();
	ProdutoDAO daoP = new ProdutoDAO();

	private static IFachadaSistema fc;

	private Sistema() throws Exception {
		dao.recuperar();
	}

	static public IFachadaSistema getFachada() throws Exception {
		if (fc == null) {
			fc = new Sistema();
		}
		return fc;
	}

	public void cadastrar(Cliente c) throws Exception {
		try {
			dao.busca(c.getCpf());

		} catch (Exception e) {
			c.setId(dao.getNextId());
			dao.incluir(c);
			dao.salvar();
			return;
		}
		throw new Exception("Cliente já cadastrado!");

	}

	public void cadastrarProduto(Produto c) throws Exception {
		try {
			daoP.busca(c.getCodigo());

		} catch (Exception e) {
			c.setId(daoP.getNextId());
			daoP.incluir(c);
			daoP.salvar();
			return;
		}
		throw new Exception("Cliente já cadastrado!");

	}
	public Cliente buscar(String cpf) throws Exception {
		return dao.busca(cpf);
	}

	public void excluir(String cpf) throws Exception {
		dao.remover(cpf);
		dao.salvar();
	}

	public void atualizar(Cliente c) throws Exception {
		dao.atualizar(c);
		dao.salvar();
	}

	
	public Produto buscarProduto(String codigo) throws Exception {
		// TODO Auto-generated method stub
		return null;
	}

	
	public void excluirProduto(String codigo) throws Exception {
		// TODO Auto-generated method stub
		
	}

	
	public void atualizarProduto(Produto c) throws Exception {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void cadastrarVenda(Produto c) throws Exception {
		// TODO Auto-generated method stub
		
	}

	@Override
	public Produto buscarVenda(String codigo) throws Exception {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void excluirVenda(String codigo) throws Exception {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void atualizarVenda(Produto c) throws Exception {
		// TODO Auto-generated method stub
		
	}

}
